HEAD = includes

SRCS = srcs/ft_strdup.c srcs/ft_atoa.c srcs/ft_strlen.c srcs/ft_strstr.c srcs/ft_space.c srcs/ft_split.c srcs/ft_printable.c srcs/ft_num.c srcs/ft_strncpy.c srcs/ft_print_all.c srcs/ft_strjoin.c srcs/ft_sort_string.c srcs/main.c srcs/ft_print_all2.c

OBJS = ${SRCS:.c=.o}

NAME = rush-02

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${HEAD}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
