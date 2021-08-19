CC = gcc

CFLAGS = -g -Wall

seashell: prompt.o shell.o utils.o
	${CC} -o seashell ${CFLAGS} prompt.o shell.o utils.o

clean:
	rm -rf *.o seashell

# Following commands are invoked indirectly.

prompt.o: prompt.c prompt.h
	${CC} ${CFLAGS} -c prompt.c

shell.o: shell.c shell.h
	${CC} ${CFLAGS} -c shell.c

utils.o: utils.c utils.h
	${CC} ${CFLAGS} -c utils.c

