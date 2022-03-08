PUSH_SWAP = push_swap

SRC = pp.c\
	rules.c\
	check_args.c\
	sort.c\
	utils0.c\
	utils1.c\
	utils2.c\
	utils3.c
CC = cc

LIBFT = ./libft/libft.a

HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror

all : $(LIBFT) $(HEADER) $(PUSH_SWAP)

$(PUSH_SWAP) : push_swap.c $(HEADER) $(SRC)
	$(CC) $(CFLAGS) $(SRC) push_swap.c $(LIBFT) -o push_swap

$(LIBFT) :
	make -C./libft

clean :
	make clean -C ./libft

fclean : clean
	rm -rf $(PUSH_SWAP) Push_swap.a
	make fclean -C ./libft

re : fclean all 