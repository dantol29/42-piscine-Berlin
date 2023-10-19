# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmejbar <mmejbar@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 14:51:09 by dtolmaco          #+#    #+#              #
#    Updated: 2023/10/15 22:10:49 by mmejbar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = *.c
DEST = rush-02

$(DEST): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(DEST)

fclean:
	rm -f *.o $(DEST)

clean: fclean

.PHONY = fclean clean
