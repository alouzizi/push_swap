PUSH_SWAP = push_swap

SRC = pp.c\
	rules.c\
	check_args.c\
	sort.c\
	utils0.c\
	utils1.c\
	utils2.c\
	utils3.c\
	utils4.c
SRC2 = ./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c
CC = gcc

LIBFT = ./libft/libft.a

CHEKER = cheker

HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror

all : $(LIBFT) $(HEADER) $(PUSH_SWAP)

$(PUSH_SWAP) : push_swap.c $(HEADER) $(SRC)
	$(CC) $(CFLAGS) $(SRC) push_swap.c $(LIBFT) -o push_swap

bonus : cheker.c $(HEADER) $(SRC) $(src2)
	$(CC) $(SRC) cheker.c $(SRC2) $(LIBFT) -o cheker

$(LIBFT) :
	Make -C./libft

clean :
	make clean -C ./libft

fclean : clean
	rm -rf $(PUSH_SWAP) Push_swap.a
	make fclean -C ./libft

re : fclean all 