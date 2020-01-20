# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:27:22 by yberries          #+#    #+#              #
#    Updated: 2020/01/20 21:22:29 by yberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = $(addsuffix .c, \
	  main \
	  read_validate \
	  map)

OBJ = $(SRC:.c=.o)

HDR = include/

SRCDIR = src/

OBJDIR = obj/

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

LIB = libft/libft.a

FLAGS = -Wall -Werror -Wextra

.PHONY: clean fclean re all

all: $(NAME)

$(LIB):
	@cd libft; make

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS) -I $(HDR)
	mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

$(NAME): Makefile $(LIB) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIB) -I $(HDR) -o $(NAME)

clean:
	cd libft; make clean
	rm -rf $(OBJDIR)

fclean:
	cd libft; make fclean
	rm -rf $(OBJDIR)
	rm -f $(NAME)

re: fclean all
