NAME := libftprintf.a
LIBFT := ./libft/libft.a

ARFLAGS := -r -s -c
SRCS := ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_d.c

OBJS := $(SRCS:%.c=%.o)
CFLAGS := -Wall -Werror -Wextra
AR := ar rcs

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	ar $(ARFLAGS) $(NAME) $(OBJS)
	ar x $(LIBFT)
	ar $(ARFLAGS) $(NAME) *.o
	rm -f *.o

#! to remove
ft_printf : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L./libft -lft -o ft_printf 

$(LIBFT) :
	$(MAKE) -C ./libft

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re