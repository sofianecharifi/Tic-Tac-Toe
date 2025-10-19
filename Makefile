# Makefile

NAME = tic_tac_toe

SRCS = main.c \
	tic_tac_toe.c \
	robot.c

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all