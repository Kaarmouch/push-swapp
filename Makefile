NAME = push_swap

RM = rm -rf

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = do_push.c do_rrotate.c ft_sorting.c helpers.c push_swap.c sort_utils.c \
build_ft.c do_rotate.c do_swap.c ft_split.c utils.c print_nodes.c

$(NAME) :
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all	: $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all

