# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 00:48:23 by jcasino           #+#    #+#              #
#    Updated: 2017/06/15 04:25:40 by jcasino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

CFLAGS	= gcc -Wall -Wextra -Werror

#INC	= ./includes/

SRC 	=	main.c \
				parse.c\
				draw.c \
				initiate.c\
				read.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT	= libft/libft.a

LIBINC	= -I./libft/includes/

LIBLINK	= -L./libft -lft

LIBDIR 	= ./libft/

SRCDIR	= ./src/

INCDIR	= ./includes/

OBJDIR	= ./obj/

LIBOBJ	= ./libft/obj

# Colors
RESET		=	\033[0m
DARK		=	\033[1;32m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
MAGENTA		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
BOLDBLACK	=	\033[1m\033[30m
BOLDRED		=	\033[1m\033[31m
BOLDWHITE	=	\033[1m\033[37m


all: obj  $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		@$(CFLAGS)  -I $(INCDIR) -o $@ -c $<


$(NAME): $(OBJ)
	$(CFLAGS)  -o $(NAME) $(LIBFT) $(OBJ) -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit -g

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
