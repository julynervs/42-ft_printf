CC = clang

CFLAGS = -Wall -Werror -Wextra 

LIBFT = ./libft/libft.a

SCRS = ft_printf.c ft_type_returns.c ft_convert_base.c

OBJS = $(SCRS:.c=.o)

NAME = libftprintf.a

#making compiling, creating .o bjects from .c abstract files
.c.o:		$(SRCS)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


#creating library
#making linkage, creating binary executable program from .o objects compiling
$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			ar rcs  $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(MAKE) clean -C ./libft
			rm -f $(OBJS)

#force clean
fclean:		clean
			$(MAKE) fclean -C ./libft
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
