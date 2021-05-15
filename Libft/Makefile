# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 11:22:54 by sehypark          #+#    #+#              #
#    Updated: 2021/05/15 19:41:32 by sehypark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
			ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcmp.c\
			ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strdup.c\
			ft_strlcat.c ft_strlen.c ft_substr.c ft_tolower.c ft_toupper.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o $@ -I libft.h

$(NAME) : ${OBJS}
	ar rcs ${NAME} ${OBJS}

all : $(NAME)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY:	all clean fclean re
