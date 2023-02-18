# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 20:19:45 by sel-biyy          #+#    #+#              #
#    Updated: 2023/02/18 00:59:52 by sel-biyy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = creation.c philo.c threads.c time.c utils.c
OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra 
NAME = philo
all: $(NAME)

$(NAME): $(OBJFILES)
	cc  $(CFLAGS) $(OBJFILES) -o $(NAME)

clean:
	rm -rf $(OBJFILES) 

fclean: clean
	rm -rf $(NAME)
re:fclean all