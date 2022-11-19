# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sroggens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 17:34:33 by sroggens          #+#    #+#              #
#    Updated: 2022/09/18 06:09:39 by sroggens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = errormess.c parent.c \
	   printfpipex.c printfpipex2.c \
	   main.c splitpipex.c \
	   outils.c trueparsing.c \
	   ft_strchr.c ft_calloc.c \
	   ft_bzero.c ft_strdup.c \
	   absolucmd.c \

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Werror -Wextra -Wall

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean :
	rm -rf $(NAME)

re : fclean all
	rm -rf *.o

.PHONY: all clean flean re
