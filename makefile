CC = cc -Wall -Wextra
OUT = ./bin/md
RUN = ${OUT} ./README.md


${OUT}: ./obj/main.o 
	${CC} ./obj/*.o -o ${OUT}

	${RUN}

./obj/main.o: ./src/main.c 
	${CC} -c ./src/main.c -o ./obj/main.o 


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
