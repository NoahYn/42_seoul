NAME = push_swap
SRCS = push_swap.c stk_fn.c
PRT_PATH = ./ft_printf
PRT = $(PRT_PATH)/libftprintf.a
LIB_PATH = $(PRT_PATH)/libft
LIB = $(LIB_PATH)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror

all : $(NAME) $(NAME2)

$(NAME) : $(PRT)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(PRT)

$(PRT) :
	@$(MAKE) -C $(PRT_PATH) all

clean :
	@$(MAKE) -C $(PRT_PATH) clean

fclean : 
	@$(MAKE) -C $(PRT_PATH) fclean
	@rm -f $(NAME) $(NAME2)

re : fclean all

bonus : all

.PHONY: all clean fclean re