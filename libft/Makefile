# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/11 12:24:19 by jsankari          #+#    #+#              #
#    Updated: 2020/09/25 18:12:04 by jsankari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_countstring.c \
	ft_ilen.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_nilen.c \
	ft_printnull.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_striteritest.c \
	ft_stritertest.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strmapitest.c \
	ft_strmaptest.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_strtrimc.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_islower.c \
	ft_isupper.c \
	ft_isspace.c \
	ft_lstnew.c \
	ft_lstadd.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line.c \

OFILES = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean :
	@/bin/rm -f $(OFILES)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all