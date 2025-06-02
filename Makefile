NAME = pipex

NAME_BONUS = pipex

CC = cc

CFLAGS = -Werror -Wall -Wextra -g3

RM = rm -f

LIBFT = libft/libft.a

SRCS = 	src/pipex.c\
		src/pipex_utils.c\

SRCS_BONUS = src_bonus/pipex_bonus.c\
			src_bonus/pipex_utils_bonus.c\
			src_bonus/get_next_line.c\

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

#%.o : %.c
#	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@make re -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_BONUS) : $(OBJS_BONUS)
	@make re -C libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

all : $(NAME)

bonus : $(NAME_BONUS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C libft

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C libft

re : fclean all

re_bonus : fclean bonus

.PHONY: all clean fclean re bonus re_bonus