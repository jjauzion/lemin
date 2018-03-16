# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 11:25:23 by jjauzion          #+#    #+#              #
#    Updated: 2018/03/16 13:13:09 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, LIB

SRC_NAME1 = main.c \
			init.c \
			parse.c \
			check_name.c \
			add_link.c \
			add_vertex.c \
			free.c \
			list_fct.c \
			path_finding.c \
			djikstra.c \
			print.c \
			run_ants_run.c \
			adj_list_mgmt.c

SRC_NAME2 = 

SRC_PATH1 = src/

SRC_PATH2 =

OBJ_PATH1 = .obj/

LIB_PATH = libft/

LDLIBS = libftprintf.a

EXT_LIB =

INC_PATH1 = libft/

INC_PATH2 = includes/

INC_NAME1 = libft.h

INC_NAME2 = lemin.h

NAME = lem-in

CC = gcc

ifdef FLAG
	ifeq ($(FLAG), no)
	CFLAGS =
	DBFLAGS =
endif
ifeq ($(FLAG), debug)
	CFLAGS = -Wall -Wextra -Werror
	DBFLAGS = -g3 -fsanitize=address
endif
else
	CFLAGS = -Wall -Wextra -Werror
	DBFLAGS =
endif

SRC = $(addprefix $(SRC_PATH1),$(SRC_NAME1)) \
	  $(addprefix $(SRC_PATH2),$(SRC_NAME2))

OBJ1 = $(addprefix $(OBJ_PATH1),$(SRC_NAME1:.c=.o))

OBJ2 = $(addprefix $(OBJ_PATH1),$(SRC_NAME2:.c=.o))

INC =  $(addprefix $(INC_PATH2),$(INC_NAME2)) \
	   $(addprefix $(INC_PATH1),$(INC_NAME1))

LDFLAGS = $(addprefix $(LIB_PATH),$(LDLIBS))

CPPFLAGS = $(addprefix -I,$(INC_PATH1)) \
		   $(addprefix -I,$(INC_PATH2))

all: LIB $(NAME)

$(NAME): $(LDFLAGS) $(OBJ1) $(OBJ2)
	$(CC) $(DBFLAGS) $(LDFLAGS) $(EXT_LIB) $(OBJ1) $(OBJ2) -o $(NAME)

LIB:
	make -C libft

$(OBJ_PATH1)%.o: $(SRC_PATH1)%.c $(INC) Makefile
	@mkdir $(OBJ_PATH1) 2> /dev/null || true
	$(CC) $(CFLAGS) $(DBFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	make -C libft clean
	rm -f $(OBJ1) $(OBJ2)
	@rmdir $(OBJ_PATH1) 2> /dev/null || true

fclean: clean
	make -C libft fclean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC)
	norminette $(LIB_PATH)
