# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: binam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 18:58:49 by binam             #+#    #+#              #
#    Updated: 2022/03/17 18:58:56 by binam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard src/*.c) $(wildcard ./*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc

MFLAGS =  ./libft/libft.a ./mlx/libmlx.a ./ft_printf/libftprintf.a ./get_next_line/get_next_line.a

AFLAGS =  -Wall -Wextra -Werror -I./mlx -I./libft -I./ft_printf -I./get_next_line

RM = rm -rf

NAME = cub3d

MAKE = make -C 

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	$(MAKE) ./libft
	$(MAKE) ./get_next_line
	$(MAKE) ./ft_printf

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	$(RM) ./libft/*.a
	$(RM) ./src/*.a
	$(RM) ./ft_printf/*.a
	$(RM) ./get_next_line/*.a
	$(RM) $(NAME)

clean :
	$(RM) ./libft/*.o
	$(RM) ./src/*.o
	$(RM) ./ft_printf/*.o
	$(RM) ./get_next_line/*.o

re : fclean all

.PHONY : all fclean clean re
