# CC = cc -Wall -Wextra -g
CC = cc -Wall -Wextra
OUT = ./bin/md
RUN = ${OUT} ./README.md
DEBUG = ${OUT} ./doc/Styles.md


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


run:
	${RUN}

mk:
	mkdir obj bin


cyg: ${OUT}
	chmod a+x ${OUT}

	mkdir -p "/usr/doc/md/"
	cp ./doc/CommandLine.md /usr/doc/md/CommandLine.md
	cp ./face /usr/doc/md/face

	cp ${OUT} /usr/bin/

linux: ${OUT}
	sudo chown root:root ${OUT}
	sudo chmod a+x ${OUT}

	sudo mkdir -p "/usr/doc/md/"
	sudo cp ./doc/CommandLine.md /usr/doc/md/CommandLine.md
	sudo cp ./face /usr/doc/md/face

	sudo cp ${OUT} /usr/bin/

debug: ${OUT}
	${DEBUG}


clean:
	rm obj/*.o 
