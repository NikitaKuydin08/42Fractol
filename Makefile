# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 16:21:44 by nkuydin           #+#    #+#              #
#    Updated: 2025/10/16 16:00:06 by nkuydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./includes/MLX42
LIBFT_DIR = ./includes/42Libft

HEADERS = -I ${MLX_DIR}/include -I ${LIBFT_DIR}
LIBS = ${MLX_DIR}/build/libmlx42.a ${LIBFT_DIR}/libft.a -ldl -lglfw -pthread -lm
SRCS = srcs/main.c \
		srcs/draw.c \
		srcs/events.c \
		srcs/init.c \
		srcs/mandelbrot.c \
		srcs/julia.c \
		srcs/help.c \

OBJS = ${SRCS:.c=.o}

all : mlx libft ${NAME}

libft:
	@make -C ${LIBFT_DIR}

mlx :
	@cmake -S ${MLX_DIR} -B ${MLX_DIR}/build
	@cmake --build ${MLX_DIR}/build -j4

.c.o:
	${CC} ${CFLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	${CC} ${OBJS} ${LIBS} -o $(NAME)

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}
	rm -rf ${MLX_DIR}/build
	@make -C ${LIBFT_DIR} fclean

re : fclean all

.PHONY : all clean fclean re mlx