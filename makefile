# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 02:57:31 by akabbouc          #+#    #+#              #
#    Updated: 2016/11/29 03:36:28 by akabbouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRCS= src/main.c \
	  src/ft_need.c \
	  src/get_tetris.c \
	  src/solve.c \
	  src/reader.c \

OBJS= $(SRCS:.c=.o)

FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "Compiling \033[33m$(NAME)..\033[0m"
	@make -C libft/ re
	@gcc -I./libft/includes/ -I includes -L./libft/ -lft $(FLAGS) -o $(NAME) $(SRCS)
	@echo "\033[32mCompilation Done !\033[0m"

clean:
	@make -C libft clean
	@rm -rf obj

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
