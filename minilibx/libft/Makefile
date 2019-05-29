# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahintz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 08:36:14 by ahintz            #+#    #+#              #
#    Updated: 2019/04/01 16:42:35 by ahintz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = src/ft_*.c
OBJ = ft_*.o
FLAGS = -Wall -Wextra -Werror 

all: $(NAME) 
$(NAME):
	gcc $(FLAGS) -c $(SRC)  -I includes
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all clean
