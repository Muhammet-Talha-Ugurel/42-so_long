#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 04:45:20 by mugurel           #+#    #+#              #
#    Updated: 2023/02/06 04:45:22 by mugurel          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = ./src/so_long.c
SRCBS = 
NAME = so_long
CC = gcc
CFLAGS =  -g
LFLAGS = -lXext -lX11 -lm -lz -L./lib/mlx_lib -lmlx
MLX = ./lib/mlx_lib/libmlx.a
FT_PRINTF = ./lib/ft_printf/libftprintf.a
GET_NEXT_LINE = ./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c
RM = rm -rf
LIBC = ar -rcs

all: $(MLX) ${NAME}

$(NAME): $(SRCS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(FT_PRINTF) $(MLX) $(GET_NEXT_LINE) -o $(NAME)

bonus : $(SRCBS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

$(MLX) :
	@make -C ./mlx_lib

$(FT_PRINTF) :
	@make -C ./ft_printf

clean:

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./mlx_lib
	@make fclean -C ./ft_printf

re: fclean all

.PHONY: all bonus clean fclean re .c.o
