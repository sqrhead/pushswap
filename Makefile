# Program name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = $(wildcard *.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Testing rules
test: $(NAME)
	./$(NAME) "4 67 3 87 23"

test100: $(NAME)
	@ARG=$$(shuf -i 1-500 -n 100 | tr '\n' ' '); \
	echo "Testing with 100 numbers..."; \
	./$(NAME) "$$ARG" | wc -l

test500: $(NAME)
	@ARG=$$(shuf -i 1-5000 -n 500 | tr '\n' ' '); \
	echo "Testing with 500 numbers..."; \
	./$(NAME) "$$ARG" | wc -l

.PHONY: all clean fclean re test test100 test500