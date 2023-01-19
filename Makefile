NAME = libftprintf.a
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
LIB = libft

CC = cc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIB) all
	ar rcs $@ $(LIB)/libft.a $(OBJS) 

%.o : $.c
	$(CC) $(FLAGS) -c $<

clean :
	@$(MAKE) -C $(LIB) clean
	@rm -f $(OBJS)

fclean : clean
	@$(MAKE) -C $(LIB) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re