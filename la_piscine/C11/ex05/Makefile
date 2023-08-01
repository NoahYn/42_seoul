SRCS = do_op.c ft_putnbr.c main.c

OBJS = do_op.o ft_putnbr.o main.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = do-op

all : ${NAME}

${OBJS} : ${SRCS}
	${CC} ${CFLAGS} -c ${SRCS}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : clean all
