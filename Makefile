NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER = ./includes/pipex.h

SRCS =  ./pipex.c \
		./srcs/fd_check.c \
		./srcs/free_2d.c \
		./srcs/ft_putchar_fd.c \
		./srcs/ft_putstr_fd.c \
		./srcs/ft_split.c \
		./srcs/ft_strjoin.c \
		./srcs/ft_strlen.c \
		./srcs/ft_strncmp.c \
		./srcs/ft_substr.c \
		./srcs/ft_strdup.c \
		./srcs/ft_memcpy.c \
		./srcs/ft_slashjoin.c \
		./srcs/secure_freedom.c \
		./srcs/path_finder.c

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re