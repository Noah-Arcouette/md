# CC = cc -Wall -Wextra -g
CC = cc -Wall -Wextra
OUT = ./bin/md
# RUN = ${OUT} ./README.md
RUN = ${OUT} ./test.md


${OUT}: ./obj/printer.o ./obj/main.o ./obj/settings.o ./obj/reader.o
	${CC} ./obj/*.o -o ${OUT}

	${RUN}

./obj/main.o: ./src/main.c 
	${CC} -c ./src/main.c -o ./obj/main.o 

./obj/settings.o: ./src/settings.c 
	${CC} -c ./src/settings.c -o ./obj/settings.o 

./obj/reader.o: ./src/reader.c 
	${CC} -c ./src/reader.c -o ./obj/reader.o 

./obj/printer.o: ./src/printer.c ./src/main.h
	${CC} -c ./src/printer.c -o ./obj/printer.o 

debug:
	${CC} -o ${OUT} ./src/*.c -g


run:
	${RUN}

mk:
	mkdir obj bin


cyg: ${OUT}
	chmod a+x ${OUT}

	cp ${OUT} /usr/bin/

linux: ${OUT}
	sudo chown root:root ${OUT}
	sudo chmod a+x ${OUT}

	sudo cp ${OUT} /usr/bin/


clean:
	rm obj/*.o 
