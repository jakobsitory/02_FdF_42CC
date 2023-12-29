# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 14:58:38 by jschott           #+#    #+#              #
#    Updated: 2023/08/24 16:31:40 by jschott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#SOURCES
SRCDIR = src
SRCS = ft_isalpha.c \
		ft_memchr.c \
		ft_memset.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_isascii.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strrchr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		ft_printf.c \
		ft_printc.c \
		ft_prints.c \
		ft_printi.c \
		ft_printu.c \
		ft_printp.c \
		ft_printx.c \
		ft_abs.c \
		ft_atol.c

#INCLUDES
HDRDIR = include
HDRS = 	libft.h\
		ft_printf.h\
		get_next_line.h

#COMPILATION CMNDS
CC = cc
FT_FLAGS = -Wextra -Wall -Werror -Wall

#COMPILATION FILES
SRC = $(addprefix $(SRCDIR)/,$(SRCS))
OBJS = $(SRCS:%.c=$(SRCDIR)/%.o)
HDR = $(addprefix $(HDRDIR)/,$(HDRS))

#RULES

all: $(NAME)

$(NAME): $(OBJS)
	@ar -crs $(NAME) $(OBJS)

$(OBJS): $(SRCDIR)/%.o : $(SRCDIR)/%.c $(HDR)
	$(CC) $(FT_FLAGS) -I$(HDRDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re