
NAME =	libft.a
INC = libft.h 
SRCS =	ft_atoi.c\
		ft_split.c\
		ft_strjoin.c\
		ft_isdigit.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_putstr.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
RM = @rm -f
AR = @ar -rcs

all: $(NAME)

$(NAME):$(OBJS) $(INC)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all