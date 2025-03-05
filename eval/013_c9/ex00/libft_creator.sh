# Name of Linrary to create
LIB="libft.a"

# List of Source Files
SRC_C="ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c"

# Complie the sources files (-c means to Complie ONLY $SRC_C to create .o files)
cc -Wall -Wextra -Werror -c $SRC_C

# Create the library with ALL the just created (.o) object files
# (r - Replace existing object files or add new ones if not present)
# (c - Create (.a) archive files if it does not exist)
ar rc $LIB *.o

# Remove the (.o) object files after creating the library (-f means Force Remove)
rm -f *.o
