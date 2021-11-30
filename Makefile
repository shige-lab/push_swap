NAME = push_swap
CHECKER = checker
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  src/function_for_main.c \
		src/sort_disposal.c \
		src/sort.c \
		src/sort2.c \
		src/sort3.c \
		src/push_swap.c \
		src/sort_disposal_parts.c \
		src/error_disposal.c \
		src/main.c
CSRCS = src/get_next_line.c \
		src/ft_checker.c \
		src/function_for_main.c \
		src/sort_disposal.c \
		src/sort.c \
		src/sort2.c \
		src/sort3.c \
		src/push_swap.c \
		src/sort_disposal_parts.c \
		src/error_disposal.c
OBJS = $(SRCS:%.c=%.o)
INCLUDE = -I include/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LIBFT)

$(CHECKER): $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(CHECKER) $(CSRCS) $(LIBFT)

$(LIBFT): empty
	make -C libft
empty:

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
clean:
	rm -f $(OBJS)
	make clean -C libft
	rm -f $(CHECKER)
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
re: fclean all
# test: $(NAME)
# 	$(CC) $(CFLAGS) $(NAME) main.c &&./a.out
# t: $(NAME)
# 	$(CC) $(CFLAGS) $(NAME) main.c
# test-: $(NAME)
# 	$(CC) $(NAME) main.c &&./a.out

.PHONY: all clean fclean re 