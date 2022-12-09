NAME=findC
LOWERNAME=findc
OBJS = ${LOWERNAME}.c
CFLAGS= -O2 -I.
CC = gcc

${NAME}:${LOWERNAME}.c
	${CC} -o ${NAME} ${CFLAGS} ${OBJS}
