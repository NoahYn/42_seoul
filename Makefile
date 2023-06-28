NAME = push_swap
SRCS = main.c stk_fn.c stk_cmd1.c stk_cmd2.c stk_cmd3.c debug.c
PRT_PATH = ./ft_printf
PRT = $(PRT_PATH)/libftprintf.a
LIB_PATH = $(PRT_PATH)/libft
LIB = $(LIB_PATH)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror
DBG = -fsanitize=address

all : $(NAME) 

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

debug : $(DBG)

$(DBG) : $(PRT)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(PRT) $(DBG)

.PHONY: all clean fclean re bonus debug