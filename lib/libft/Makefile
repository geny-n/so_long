# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 10:28:13 by ngeny             #+#    #+#              #
#    Updated: 2023/11/23 10:28:13 by ngeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
FLAG = -Wall -Wextra -Werror
OBJDIR = ./OBJ/

SRC = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_striteri.c

SRC_BONUS = 	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

SRCS = ${SRC} ${SRC_BONUS}

OBJ = ${SRCS:.c=.o}
OBJS = $(addprefix $(OBJDIR), $(OBJ))

all: ${NAME}

${NAME} : ${OBJS}
	ar -crs ${NAME} ${OBJS}

#bonus : ${OBJ} ${OBJ_BONUS}
#	ar -crs ${NAME} ${OBJ_BONUS}

${OBJDIR}%.o : %.c
	mkdir -p ${OBJDIR}
	${CC} ${FLAG} -c -o $@ $<

#so:
#	$(CC) -nostartfiles -fPIC $(FLAG) $(SRCS) ${SRCS_BONUS}
#	gcc -nostartfiles -shared -o libft.so $(OBJ) ${OBJ_BONUS}

.phony : bonus clean all fclean re

clean :
	rm -rf ${OBJDIR}
fclean : clean
	rm -rf ${NAME}
re : fclean all


