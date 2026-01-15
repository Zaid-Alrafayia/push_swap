NAME        = push_swap
NAME_BONUS  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = sort/size_sort.c operations/swap.c operations/push.c operations/rotate.c \
							operations/rrotate.c arg/arg.c arg/arg2.c utils/errors.c utils/helper.c \
							utils/sort_helper.c	push_swap.c  utils/utils.c sort/functions.c sort/move.c utils/init.c utils/init_b.c
SRCS_BONUS  = 

OBJS        = $(SRCS:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

. PHONY: all clean fclean re bonus

