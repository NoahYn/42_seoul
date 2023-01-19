NAME = libftprintf.a
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIB_PATH) all
	@cp $(LIB) $(NAME)
	ar rcs $@ $(LIB) $(OBJS) 

%.o : $.c
	$(CC) $(FLAGS) -c $<

clean :
	@$(MAKE) -C $(LIB_PATH) clean
	@rm -f $(OBJS)

fclean : clean
	@$(MAKE) -C $(LIB_PATH) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re