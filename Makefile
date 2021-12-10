NAME = push_swap
CHECKER = checker
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  src/function_for_main.c \
		src/sort_disposal.c \
		src/sort_s_stock.c \
		src/sort1.c \
		src/sort2.c \
		src/sort3.c \
		src/push_swap.c \
		src/sort_disposal_parts.c \
		src/error_disposal.c \
		src/main.c
CSRCS = src/ft_checker.c \
		src/function_for_main.c \
		src/sort_disposal.c \
		src/sort_s_stock.c \
		src/sort1.c \
		src/sort2.c \
		src/sort3.c \
		src/push_swap.c \
		src/sort_disposal_parts.c \
		src/error_disposal.c
OBJS = $(SRCS:%.c=%.o)
COBJS = $(CSRCS:%.c=%.o)
INCLUDE = -I include/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LIBFT)

$(CHECKER): $(LIBFT) $(COBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(CHECKER) $(COBJS) $(LIBFT)

$(LIBFT): empty
	make -C libft
empty:

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
clean:
	$(RM) $(OBJS)
	$(RM) $(COBJS)
	make clean -C libft
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(CHECKER)
re: fclean all
# test: $(NAME)
# 	$(CC) $(CFLAGS) $(NAME) main.c &&./a.out
# t: $(NAME)
# 	$(CC) $(CFLAGS) $(NAME) main.c
# test-: $(NAME)
# 	$(CC) $(NAME) main.c &&./a.out

.PHONY: all clean fclean re empty