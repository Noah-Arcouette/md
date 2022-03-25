CC        = gcc -Wall -Wextra -O0 -g
CCBUILD   = gcc -O2
OUT       = ./bin/md
STYLE     = default
STYLEFILE = ./styles/${STYLE}.h
LIBOUT    = ./bin/libmarkdown.so

all: style ${OUT}
	${OUT} ./test.md

lib: style
	${CCBUILD} -I./inc --shared -o ${LIBOUT} ./src/printer.c ./src/libmd.c

	strip -s ${LIBOUT}

# 	gzip -k ./mdout.1
# 	gzip -k ./libmarkdown.1

	rm ./src/style.h

style:
	cp ${STYLEFILE} ./src/style.h


build: style
	${CCBUILD} ./src/*.c -o ${OUT}

	strip -s ${OUT}

	gzip -k ./md.1

	rm ./src/style.h

${OUT}: ./obj/printer.o ./obj/main.o ./obj/settings.o ./obj/reader.o
	${CC} ./obj/*.o -o ${OUT}

./obj/main.o: ./src/main.c 
	${CC} -c ./src/main.c -o ./obj/main.o 

./obj/settings.o: ./src/settings.c ./src/style.h
	${CC} -c ./src/settings.c -o ./obj/settings.o 

./obj/reader.o: ./src/reader.c ./src/style.h
	${CC} -c ./src/reader.c -o ./obj/reader.o 

./obj/printer.o: ./src/printer.c ./src/style.h
	${CC} -c ./src/printer.c -o ./obj/printer.o 


mk:
	mkdir -p obj bin


install: mk build
	chmod a+x ${OUT}

	mkdir -p "/usr/doc/md/"
	cp ./doc/* /usr/doc/md/
	cp ./face /usr/doc/md/face

	cp ${OUT} /usr/bin/

	cp ./md.1.gz /usr/share/man/man1/

	rm ./bin/md

uninstall:
	rm /usr/doc/md/ -r
	rm /usr/bin/md
	rm /usr/share/man/man1/md.1.gz

clean:
	rm -f ./obj/* ./bin/* ./src/style.h *.gz
