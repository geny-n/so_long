# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 12:05:57 by ngeny             #+#    #+#              #
#    Updated: 2024/06/03 19:21:37 by ngeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
HEAD = ft_printf.h
OBJDIR = ./OBJ/
SRCS = 	ft_printf.c \
		ft_print_len.c \
		ft_print_char.c \
		ft_print_string.c \
		ft_print_pointer.c \
		ft_print_unsigned.c \
		ft_print_nb.c \
		ft_print_hex.c \
		

OBJ = ${SRCS:.c=.o}
OBJS = $(addprefix $(OBJDIR), $(OBJ))

all : ${NAME}
${NAME} : ${OBJS}
	ar -crs ${NAME} ${OBJS}

$(OBJDIR)%.o : %.c ${HEAD}
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} -c $< -o $@ 

.phony : clean fclean re
clean :
	rm -rf $(OBJDIR)
fclean : clean
	rm -f ${NAME}
re : fclean all
	