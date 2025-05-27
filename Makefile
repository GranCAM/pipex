NAME = pipex

CC = cc

CFLAGS = -Werror -Wall -Wextra -g3

RM = rm -f

LIBFT = libft/libft.a

SRCS = 	src/pipex.c\
	src/pipex_utils.c\

OBJS = $(SRCS:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@make re -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all
