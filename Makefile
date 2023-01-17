NAME = libftprintf.a
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : $.c
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re