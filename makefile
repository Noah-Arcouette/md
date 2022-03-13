CC      = gcc -Wall -Wextra -O0 -g
CCBUILD = gcc -O2
OUT     = ./bin/md


all: ${OUT}
	${OUT} ./test.md

build: 
	${CCBUILD} ./src/*.c -o ${OUT}

	strip -s ${OUT}

${OUT}: ./obj/printer.o ./obj/main.o ./obj/settings.o ./obj/reader.o
	${CC} ./obj/*.o -o ${OUT}

./obj/main.o: ./src/main.c 
	${CC} -c ./src/main.c -o ./obj/main.o 

./obj/settings.o: ./src/settings.c 
	${CC} -c ./src/settings.c -o ./obj/settings.o 

./obj/reader.o: ./src/reader.c 
	${CC} -c ./src/reader.c -o ./obj/reader.o 

./obj/printer.o: ./src/printer.c ./src/main.h
	${CC} -c ./src/printer.c -o ./obj/printer.o 


mk:
	mkdir obj bin


install: build
	chmod a+x ${OUT}

	mkdir -p "/usr/doc/md/"
	cp ./doc/* /usr/doc/md/
	cp ./face /usr/doc/md/face

	cp ${OUT} /usr/bin/

	rm ./bin/md

clean:
	rm obj/*.o 
