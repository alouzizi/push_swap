PUSH_SWAP = push_swap

SRC = utils.c\
	rules.c\
	check_args.c\
	sort.c\
	utils0.c\
	utils1.c\
	utils2.c\
	utils3.c\
	utils4.c

BSRC = ./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		bonus_check_args.c\
		bonus_rules.c\
		bonus_utils.c

CC = gcc

LIBFT = ./libft/libft.a

CHEKER = checker

HEADER = push_swap.h
B_HEADER = push_swap_bonus.h

CFLAGS = -Wall -Wextra -Werror

all : $(LIBFT) $(HEADER) $(PUSH_SWAP)

$(PUSH_SWAP) : $(HEADER) $(SRC)
	$(CC) $(CFLAGS) $(SRC) push_swap.c $(LIBFT) -o  push_swap

bonus : $(B_HEADER) $(BSRC)
	$(CC) $(CFLAGS) checker.c $(BSRC) $(LIBFT) -o checker

$(LIBFT) :
	Make -C./libft

clean :
	make clean -C ./libft

fclean : clean
	rm -rf $(PUSH_SWAP) Push_swap.a $(CHEKER)
	make fclean -C ./libft

re : fclean all 