NAME=findC
LOWERNAME=findc
OBJS = ${LOWERNAME}.c
CFLAGS= -O2 -Wformat-security -Wduplicated-cond -Wfloat-equal -Wshadow -Wconversion -Wjump-misses-init -Wlogical-not-parentheses -Wnull-dereference -D_FORTIFY_SOURCE=3 -Wall -Wextra -Werror -pedantic-errors -I.
CC = gcc

${NAME}:${LOWERNAME}.c
	${CC} -o ${NAME} ${CFLAGS} ${OBJS}
