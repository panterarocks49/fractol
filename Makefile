# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 00:12:46 by jbrown            #+#    #+#              #
#    Updated: 2018/05/07 00:12:48 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
RM := /bin/rm -f

FLAGS := -Wall -Wextra -Werror -O2

# fractrol
FILES := main msg render mandelbrot julia burningship image key_hooks mouse_hooks colors
INC_DIR := ./include/
FRAC_INC := -I $(INC_DIR)
HEADER := $(INC_DIR)fractol.h
SRC_DIR := ./src/
OBJ_DIR := ./obj/
CFILES := $(patsubst %, $(SRC_DIR)%.c, $(FILES))
OFILES := $(patsubst %, $(OBJ_DIR)%.o, $(FILES))

# libftprintf lib
LFT_DIR := ./libftprintf/
LFT_LIB := $(addprefix $(LFT_DIR), ftprintf.a)
LFT_INC := -I $(LFT_DIR)include/
LFT_LINK := -L $(LFT_DIR) -l ftprintf

# mlx lib
MLX_DIR := ./minilibx_macos/
MLX_LIB	:= $(addprefix $(MLX_DIR), mlx.a)
MLX_INC := -I $(MLX_DIR)
MLX_LINK := -L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(MLX_LIB) $(LFT_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LFT_LIB):
	make -C $(LFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo [INFO] $(NAME) Object Files Directory Created

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@gcc $(FLAGS) $(FRAC_INC) $(LFT_INC) $(MLX_INC) -o $@ -c $<
	@echo [INFO] Compiling $@ into $<

$(NAME): $(OBJ_DIR) $(OFILES)
	@gcc $(FLAGS) $(OFILES) $(LFT_LINK) $(MLX_LINK) -lpthread -o $(NAME)
	@echo [INFO] $(NAME) Binary Created

clean:
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo [INFO] $(NAME) Object Files Directory Destroyed
	@make -C $(LFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@echo [INFO] $(NAME) Binary Destroyed
	@make -C $(LFT_DIR) fclean

re: fclean all
