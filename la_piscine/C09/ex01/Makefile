NAME = libft.a

HEAD = includes
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

${NAME} : ${OBJS}
	ar rsc ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I ${HEAD}

all : ${NAME}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re
