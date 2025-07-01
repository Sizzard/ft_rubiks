NAME = ft_rubik
SRCS = main.c srcs/ft_split.c srcs/utils.c srcs/actions.c
OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -o $(NAME) $(OBJ)

%.o:%.c ft_rubik.h
	cc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re