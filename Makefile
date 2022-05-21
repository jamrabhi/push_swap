# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 17:37:16 by jamrabhi          #+#    #+#              #
#    Updated: 2022/03/30 17:37:23 by jamrabhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 	src/main.c \
		src/parsing/parse_args.c src/parsing/ft_split_whitespaces.c \
		src/utils/exit.c src/utils/stack_utils.c  src/utils/find_min_max.c \
			src/utils/is_sorted.c src/utils/get_index.c \
		src/moves/swap.c src/moves/push.c src/moves/rotate.c \
			src/moves/rev_rotate.c \
		src/sort/sort.c

OBJ = $(SRC:.c=.o)

INCDIR = include/

LIBDIR = libft/

LIB = libft/libft.a

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "Compiling libft ..."
	@cd $(LIBDIR) && make bonus
	@echo "DONE \n"

	@echo "Compiling push_swap ..."
	@$(CC) $(CFLAGS) $(OBJ) -L $(LIBDIR) -lft -o $(NAME)
	@echo "DONE"

.c.o:
	@${CC} ${CFLAGS} -I $(INCDIR) -I $(LIBDIR) -c $< -o $@

clean:
	@echo "Deleting libft objects files ..."
	@cd $(LIBDIR) && make $@
	@echo "DONE \n"

	@echo "Deleting push_swap objects files ..."
	@rm -f $(OBJ)
	@echo "DONE"

fclean: clean

	@echo "Deleting libft's binary ..."
	@cd $(LIBDIR) && make $@
	@echo "DONE \n"
	
	@echo "Deleting push_swap's binary ..."
	@rm -f $(NAME)
	@echo "DONE"

re: fclean all
