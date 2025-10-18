# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 16:21:44 by nkuydin           #+#    #+#              #
#    Updated: 2025/10/19 00:26:39 by nkuydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./includes/MLX42
LIBFT_DIR = ./includes/42Libft
OBJ_DIR = objects

HEADERS = -I ${MLX_DIR}/include -I ${LIBFT_DIR}
LIBS = ${MLX_DIR}/build/libmlx42.a ${LIBFT_DIR}/libft.a -ldl -lglfw -pthread -lm
SRCS = srcs/main.c \
		srcs/draw.c \
		srcs/events.c \
		srcs/init.c \
		srcs/mandelbrot.c \
		srcs/julia.c \
		srcs/ship.c \
		srcs/help.c \
		srcs/color.c

OBJS = $(patsubst srcs/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default rule
all: mlx libft ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBS} -o $@

# Compile object files
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	${CC} ${CFLAGS} ${HEADERS} -c $< -o $@

# Ensure object directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build libft
libft:
	@make -C ${LIBFT_DIR}

# Build MLX42
mlx:
	@cmake -S ${MLX_DIR} -B ${MLX_DIR}/build
	@cmake --build ${MLX_DIR}/build -j4

# Clean objects
clean:
	rm -rf ${OBJ_DIR}
	@make -C ${LIBFT_DIR} clean

# Clean everything
fclean: clean
	rm -f ${NAME}
	rm -rf ${MLX_DIR}/build
	@make -C ${LIBFT_DIR} fclean

# Rebuild
re: fclean all

.PHONY: all clean fclean re mlx libft
