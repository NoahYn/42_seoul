NAME = push_swap
SRCS = main.c errorhandle.c debug.c \
	stk_fn.c stk_cmd1.c stk_cmd2.c \
	cmd_utils.c \
	sort_small.c

LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a

CC = cc
FLAGS = #-Wall -Wextra -Werror
DBG = -fsanitize=address

all : $(NAME) 

$(NAME) : $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIB)

$(LIB) :
	@$(MAKE) -C $(LIB_PATH) all

clean :
	@$(MAKE) -C $(LIB_PATH) clean

fclean : 
	@$(MAKE) -C $(LIB_PATH) fclean
	@rm -f $(NAME) 

re : fclean all

bonus : all

debug : $(DBG)

$(DBG) : $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIB) $(DBG)

.PHONY: all clean fclean re bonus debug