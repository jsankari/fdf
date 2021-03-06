# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/25 13:42:01 by jsankari          #+#    #+#              #
#    Updated: 2021/03/06 23:50:45 by jsankari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main_fdf.c \
projections_fdf.c \
maps_fdf.c \
structs_fdf.c \
keys_fdf.c \
errors_fdf.c \
lines_fdf.c \
switchers_fdf.c \

OBJ = $(SRCS:.c=.o)

LIBRARY = libft/libft.a

MINILIBX = minilibx/libmlx.a

XFLAGS = -I /usr/local/include/X11 -L /usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) :
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx
	@gcc $(FLAGS) -c $(SRCS) 
	@gcc $(FLAGS) $(OBJ) $(LIBRARY) $(MINILIBX) $(XFLAGS) -o $(NAME)
	@echo "[ fdf executable compiled ]"

clean :
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C minilibx
	@rm -f $(OBJ)
	@echo "[ fdf objects deleted ]"

fclean : clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)
	@echo [ fdf executable deleted ]

re : fclean all
	@$(MAKE) re -C libft

.PHONY = all clean fclean re