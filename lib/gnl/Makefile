# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 23:12:03 by ngeny             #+#    #+#              #
#    Updated: 2024/03/29 23:23:01 by ngeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

CC = cc
FLAGS = -Wall -Wextra -Werror
HEAD = get_next_line.h
OBJDIR = ./OBJ/
SRCS = 	get_next_line_utils.c \
		get_next_line.c \
		

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
	