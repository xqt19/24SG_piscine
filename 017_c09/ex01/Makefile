SRCS = srcs
INCL = includes
SRC = $(SRCS)/ft_putchar.c \
			$(SRCS)/ft_swap.c \
			$(SRCS)/ft_putstr.c \
			$(SRCS)/ft_strlen.c \
			$(SRCS)/ft_strcmp.c
OBJ = $(SRC:.c=.o)
INCLUDES = -I$(INCL)
LIB = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIB)

$(LIB): $(OBJ)
	@ar -rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(OBJ)
	@rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re