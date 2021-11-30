NAME = push_swap
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  src/get_standard_value.c \
		src/sort_disposal.c \
		src/sort.c \
		src/sort2.c \
		src/sort3.c \
		src/push_swap.c \
		src/ft_push_front.c \
		src/error_disposal.c \
		src/main.c
CSRCS = src/get_next_line.c \
		src/ft_checker.c \
		src/get_standard_value.c \
		src/is_same_number.c \
		src/sort_disposal.c \
		src/sort.c \
		src/sort2.c \
		src/sort3.c \
		src/push_swap.c \
		src/ft_push_front.c \
		src/error_disposal.c
OBJS = $(SRCS:%.c=%.o)
INCLUDE = -I include/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LIBFT)

checker: $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) -o ft_checker $(CSRCS) $(LIBFT)

$(LIBFT): empty
	make -C libft
empty:

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
clean:
	rm -f $(OBJS)
	make clean -C libft
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