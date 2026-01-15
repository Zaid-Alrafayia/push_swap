NAME        = push_swap
NAME_BONUS  = checker
COM_COLOR   = \033[0;34m
OK_COLOR    = \033[0;32m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
COM_STRING   = "Compiling"
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = sort/size_sort.c operations/swap.c operations/push.c operations/rotate.c \
							operations/rrotate.c arg/arg.c arg/arg2.c utils/errors.c utils/helper.c \
							utils/sort_helper.c	push_swap.c  utils/utils.c sort/functions.c sort/move.c utils/init.c utils/init_b.c utils/cost.c
SRCS_BONUS  = bonus/push_swap_bonus.c operations/rrotate.c operations/swap.c operations/push.c operations/rotate.c \
							arg/arg.c arg/arg2.c utils/utils.c utils/sort_helper.c utils/errors.c utils/helper.c


OBJS        = $(SRCS:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
		@printf "$(OK_COLOR)$(OK_STRING) push_swap executable successfully created\n$(NO_COLOR)"

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@printf "$(OK_COLOR)$(OK_STRING)final push_swap_bonus executable successfully created\n$(NO_COLOR)"
clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

. PHONY: all clean fclean re bonus

