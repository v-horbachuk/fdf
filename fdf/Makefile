#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 13:11:34 by vhorbach          #+#    #+#              #
#    Updated: 2017/04/14 19:12:54 by vhorbach         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRCS = ./main.c ./add_fuct.c ./chage_units.c ./colour.c \
		./draw_line.c ./ft_atoi_base.c ./keycodes.c \
		./matrix.c ./matrix_init.c

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

INCL = -I ./ \
		-I ./libft

all: $(NAME)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(OBJ) -L./libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

./libft/libft.a:
	make -C ./libft

%.o: %.c
	gcc $(FLAG) $(INCL) -c $< -o $@

clean:
	make clean -C ./libft 
	rm -rf $(OBJ)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all
