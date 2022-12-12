NAME = get_next_line.a

SRC = get_next_line_utils.c \
	get_next_line.c \
	main.c

OBJ = $(SRC:.c=.o)

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

AR	=	ar
ARFLAGS = rcs

INCLUDE	= get_next_line.h

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)

.c.o:	$(CC) (CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all
