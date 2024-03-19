# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 13:56:07 by ragrigor          #+#    #+#              #
#    Updated: 2022/08/21 18:01:41 by ragrigor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

SRCS		= $(wildcard *.c) 

OBJS 		= $(SRCS:.c=.o)

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) 
			$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
