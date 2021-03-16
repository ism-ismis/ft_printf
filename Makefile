NAME	=	libftprintf.a
CC		=	gcc
CFLAGS	=	-Wall	-Wextra	-Werror
RM		=	rm -f
SRCDIR	=	./
SRCNAME	=	ft_printf.c \
			dict_add.c \
			get_len_putnbr.c \
			input_base.c \
			print_int.c \
			print_p_s.c \
			ft_isdigit.c \
			ft_strlen.c
SRCS	=	$(addprefix $(SRCDIR), $(SRCNAME))
OBJS	=	$(SRCS:.c=.o)
.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
all:		$(NAME)
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME) test
re:			fclean all
test:		$(NAME)
			$(CC) -L. -lftprintf -o test test.c
.PHONY:	all clean fclean re
