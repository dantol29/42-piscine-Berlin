# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zblume <zblume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:33:21 by zblume            #+#    #+#              #
#    Updated: 2023/10/17 16:21:57 by dtolmaco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c solve.c read_map.c funcs.c x.c
DEST = bsq

$(DEST): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(DEST)

clean:
	rm -f $(DEST)

fclean: clean
	rm -f $(DEST)
