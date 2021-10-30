CC = gcc

CFLAGS = -g -Wall

seashell: prompt.o shell.o utils.o parse.o pipe.o redirection.o signals.o
	${CC} -o seashell ${CFLAGS} prompt.o shell.o utils.o parse.o pipe.o redirection.o signals.o

clean:
	rm -rf *.o seashell

# Following commands are invoked indirectly.

prompt.o: prompt.c prompt.h
	${CC} ${CFLAGS} -c prompt.c

shell.o: shell.c shell.h
	${CC} ${CFLAGS} -c shell.c

utils.o: utils.c utils.h
	${CC} ${CFLAGS} -c utils.c

parse.o: parse.c parse.h
	${CC} ${CFLAGS} -c parse.c

pipe.o: pipe.c pipe.h
	${CC} ${CFLAGS} -c pipe.c

redirection.o: redirection.c redirection.h
	${CC} ${CFLAGS} -c redirection.c

signals.o: signals.c signals.h
	${CC} ${CFLAGS} -c signals.c

