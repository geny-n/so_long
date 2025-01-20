# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:21:03 by ngeny             #+#    #+#              #
#    Updated: 2024/05/28 23:35:07 by ngeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

LIBFT	= ./lib/libft/libft.a
PRINTF	= ./lib/ftprintf/libftprintf.a
GNL 	= ./lib/gnl/gnl.a
OBJDIR = ./OBJ/

MLX_PATH = minilibx-linux/
MLX = minilibx-linux/libmlx_Linux.a
MLXFLAG = -lXext -lX11
MINILIBX = ${MLX} ${MLXFLAG}
INC_MLX = minilibx-linux/
INCLUDES = -I./${INC_MLX}

BONUS_DIR = ./bonus/
MANDA_DIR = ./mandatory/
CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRC =	${MANDA_DIR}free.c ${MANDA_DIR}utils.c ${MANDA_DIR}initialise.c \
		${MANDA_DIR}map.c ${MANDA_DIR}check_map.c ${MANDA_DIR}image_manager.c \
		${MANDA_DIR}keypress_manager.c ${MANDA_DIR}check_valid_path.c
SRC_MAIN = ${MANDA_DIR}main.c

BONUS_SRC =	${BONUS_DIR}bonus_free.c ${BONUS_DIR}bonus_utils.c ${BONUS_DIR}bonus_initialise.c \
			${BONUS_DIR}bonus_map.c ${BONUS_DIR}bonus_check_map.c ${BONUS_DIR}bonus_image_manager.c \
			${BONUS_DIR}bonus_keypress_manager.c ${BONUS_DIR}bonus_check_valid_path.c \
			${BONUS_DIR}bonus_set_player.c ${BONUS_DIR}bonus_set_collect.c ${BONUS_DIR}bonus_set_monster.c 
			
BONUS_MAIN = ${BONUS_DIR}bonus_main.c

SOURCES = ${SRC} ${SRC_MAIN}
SOURCES_BONUS = ${SRC} ${BONUS_SRC} ${BONUS_MAIN}

OBJ = ${SOURCES:${MANDA_DIR}%.c=${OBJDIR}%.o}
BONUS_OBJ = ${SOURCES_BONUS:${BONUS_DIR}%.c=${OBJDIR}%.o}


all: ${LIBFT} ${PRINTF} ${GNL} ${MLX} ${NAME}
${LIBFT} :
	@make -sC ./lib/libft
${PRINTF} :
	@make -sC ./lib/ftprintf
${GNL} :
	@make -sC ./lib/gnl
${MLX} :
	@make -sC ./minilibx-linux


${NAME} : ${OBJ} ${LIBFT} ${PRINTF} ${GNL} ${MINILIBX}
	${CC} ${FLAGS} ${OBJ} ${LIBFT} ${PRINTF} ${GNL} ${MINILIBX} -o ${NAME}

bonus: ${LIBFT} ${PRINTF} ${GNL} ${MLX} ${BONUS_NAME}  
${BONUS_NAME}: ${BONUS_OBJ} ${LIBFT} ${PRINTF} ${GNL} ${MINILIBX}
	${CC} ${FLAGS} ${BONUS_OBJ} ${LIBFT} ${PRINTF} ${GNL} ${MINILIBX} -o ${BONUS_NAME}
	
${OBJDIR}%.o : ${MANDA_DIR}%.c
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} ${INCLUDES} -c -o $@ $<
${OBJDIR}%.o : ${BONUS_DIR}%.c
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} -c -o $@ $<
	
clean :
	rm -rf $(OBJDIR)
	make clean -C ./lib/libft
	make clean -C ./lib/ftprintf
	make clean -C ./lib/gnl
	make clean -C ${MLX_PATH}

fclean : clean
	rm -rf ${NAME}
	rm -rf ${BONUS_NAME}
	rm -rf  ${LIBFT}
	rm -rf  ${PRINTF}
	rm -rf  ${GNL}

re : fclean all

.PHONY :
	all clean fclean re
