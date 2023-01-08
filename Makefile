NAME = getnextline
CC = gcc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1
INCLUDES = get_next_line.h

SRC = main.c get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all