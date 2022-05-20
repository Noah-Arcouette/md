CC        = gcc -I./inc -Wall -Wextra -O2 -g
OUT       = ./bin/md
STYLE     = default
STYLEFILE = ./styles/${STYLE}.h

all: ./inc/style.h ${OUT}
	${OUT} ./test.md

./inc/style.h: ${STYLEFILE}
	cp ${STYLEFILE} ./inc/style.h


build: ./inc/style.h ${OUT}
	strip -s ${OUT}

	gzip -k ./md.1

	rm ./inc/style.h

${OUT}: ./obj/printer.o ./obj/main.o ./obj/settings.o ./obj/reader.o
	${CC} ./obj/*.o -o ${OUT} -ladvo

./obj/main.o: ./src/main.c ./inc/style.h
	${CC} -c ./src/main.c -o ./obj/main.o

./obj/settings.o: ./src/settings.c ./inc/style.h
	${CC} -c ./src/settings.c -o ./obj/settings.o

./obj/reader.o: ./src/reader.c ./inc/style.h
	${CC} -c ./src/reader.c -o ./obj/reader.o

./obj/printer.o: ./src/printer.c ./inc/style.h
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
	rm -f ./obj/* ./bin/* ./inc/style.h *.gz

docs:
	mkdir -p "/usr/doc/md/"
	cp ./doc/* /usr/doc/md/
	cp ./face /usr/doc/md/face
