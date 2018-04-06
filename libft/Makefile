# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboivin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 13:09:07 by tboivin           #+#    #+#              #
#    Updated: 2016/11/25 05:01:56 by tboivin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

FLGS =	-Wall -Wextra -Werror

SRCS =	ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strsub.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_exit.c \
		ft_putendl.c \
		ft_bzero.c \
		ft_strncpy.c \

OBJS =	$(SRCS:.c=.o)

INC =	-I./includes

all: $(NAME)

$(NAME):
	gcc -c $(FLGS) $(SRCS) $(INC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
