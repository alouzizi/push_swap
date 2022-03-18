PUSH_SWAP = push_swap

SRC = utils.c\
	rules.c\
	check_args.c\
	sort.c\
	utils0.c\
	utils1.c\
	utils2.c\
	utils3.c\
	utils4.c\
	push_swap.c\

BSRC = ./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		bonus_check_args.c\
		bonus_rules.c\
		bonus_utils.c\
		checker.c\

CC = cc

LIBFT = ./libft/libft.a

CHECKER = checker

HEADER = push_swap.h
B_HEADER = push_swap_bonus.h

CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
OBJ_B = $(BSRC:.c=.o)

all : $(PUSH_SWAP)

$(PUSH_SWAP) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I $(HEADER) $(LIBFT) -o $(PUSH_SWAP) $^

bonus : $(OBJ_B) $(LIBFT)
	$(CC) $(CFLAGS) -I $(B_HEADER) $(LIBFT) -o $(CHECKER) $^

%.o : %.c $(HEADER) $(B_HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT) :
	Make -C./libft

clean :
	make clean -C ./libft
	rm -rf $(OBJS) $(OBJ_B)

fclean : clean
	rm -rf $(PUSH_SWAP) $(CHECKER)
	make fclean -C ./libft

re : fclean all 