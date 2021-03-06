# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/05 12:24:50 by mtaquet      #+#   ##    ##    #+#        #
#    Updated: 2022/03/21 12:11:05 by mtaquet          ###   ########lyon.fr    #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = computor
LIBDIR = libft/
SRCDIR = srcs/
INCDIR = includes/
LIBFILES = libft.a
SRCFILES = main.c\
		   math.c\
		   utils.c\
		   parsing.c\
		   resol.c\
		   print.c\
		   utils2.c\

INCFILES = computer.h
LIB = $(addprefix $(LIBDIR),$(LIBFILES))
SRC = $(addprefix $(SRCDIR),$(SRCFILES))
INC = $(addprefix $(INCDIR),$(INCFILES)) libft/includes/libft.h
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra -I includes -I libft/includes

all: lib $(NAME)

%.o: %.c $(INC)
	gcc -c -o $@ $< $(FLAG)

lib: $(LIBDIR)
	@make -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ) $(INC)
	gcc -o $@ $(OBJ) $(FLAG) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all
