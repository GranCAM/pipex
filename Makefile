NAME = pipex

CC = cc

CFLAGS = -Werror -Wall -Wextra -g3

RM = rm -rf

SRCS = 	src/pipex.c\
		src/pipex_utils.c\
		libft/libft.a\

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all
