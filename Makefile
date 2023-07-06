NAME = push_swap
BONUS = checker

SRCS = main.c errorhandle.c free.c \
	stk_fn.c stk_cmd1.c stk_cmd2.c \
	debug.c cmd_utils.c \
	sort_small.c \
	merge.c merge_utils.c
SRCS_BNS = bonus.c

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

bonus : all $(BONUS)

$(BONUS) : $(LIB)
	$(CC) $(FLAGS) -o $(BONUS) $(SRCS_BNS) $(LIB)

debug : $(DBG)

$(DBG) : $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIB) $(DBG)

.PHONY: all clean fclean re bonus debug