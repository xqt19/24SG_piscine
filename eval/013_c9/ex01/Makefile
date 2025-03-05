# Complier and flags
CC = cc
CFLAG = -Wall -Wextra -Werror

# Directories
SRCSDIR = srcs
INCLDIR = includes

# Library to be complied
LIB = libft.a

# Sources files (*.c)
# There is a pair of () for Makefile variable. vs Shell variable without ()
SRC = $(SRCSDIR)/ft_putchar.c $(SRCSDIR)/ft_swap.c $(SRCSDIR)/ft_putstr.c $(SRCSDIR)/ft_strlen.c $(SRCSDIR)/ft_strcmp.c

# Object files ((.c=.o) means creating a new string by replacing those .c in (SRC) with .o )
# OBJ = $(SRCSDIR)/ft_putchar.o $(SRCSDIR)/ft_swap.o $(SRCSDIR)/ft_putstr.o $(SRCSDIR)/ft_strlen.o $(SRCSDIR)/ft_strcmp.o
OBJ = $(SRC:.c=.o)

# Archive Command to Create the library
# (r - Replace existing object files or add new ones if not present)
# (c - Create (.a) archive files if it does not exist)
AR = ar rc

# Default rule => all = make all = make libft.a
all: $(LIB)

# To build the Library from Object file
$(LIB): $(OBJ)
	$(AR) $(LIB) $(OBJ)

# To Complie .c files to .o files with .h files
$(SRCSDIR)/%.o: $(SRCSDIR)%/.c $(INCLDIR)/ft.h
	$(CC) $(CFLAG) -c $(SRC) -o $(OBJ)

# clean => Remove all the temporary generated files (.o files in this case)
clean:
	rm -f $(OBJ)

# fclean => Remove the files created by "all" (libft.a in this case) and
#           all temporary generated files (.o files in this case)
fclean: clean
	rm -f $(LIB)

# re => Run make fclean followed by make all
re: fclean all

# .PHONY is a special target in Makefile that tells make NOT to treat the followings as real files
# The following sentence means all, clean, fclean and re are NOT real files but COMMANDS
.PHONY: all clean fclean re