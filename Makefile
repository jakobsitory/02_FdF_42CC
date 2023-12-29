# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschott <jschott@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 15:00:12 by jschott           #+#    #+#              #
#    Updated: 2023/11/17 12:11:02 by jschott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 15:00:12 by jschott           #+#    #+#              #
#    Updated: 2023/09/26 13:47:16 by jschott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# SOURCES
SRCDIR = src
SRC = 	fdf.c \
		regex.c \
		error_handling.c \
		ft_vctradd_back.c \
		ft_vctrlast.c \
		ft_vctrnew.c \
		ft_vctrsize.c \
		ft_vctrclear.c \
		ft_vctrdelone.c \
		ft_vctrrng.c \
		ft_vctrset.c \
		vctr_normalize.c \
		vctr_translate.c \
		vctr_scale.c \
		vctr_draw.c \
		draw_lines.c \
		scn_init.c \
		scn_borders.c \
		scn_fit.c \
		#vctr_project.c \
		#input_controls.c


# BONUS
BNSDIR = bns
BNS = 	vctr_rotate_bonus.c \
		input_controls_bonus.c \
		vctr_project_bonus.c


# INCLUDES
HDRS = FdF.h

# LIBRARIES
LIBFTNAME = libft.a
LIBFTDIR = ./include/Libft
MINILIBXNAME = libmlx.a
MINILIBXDIR = ./include/minilibx-linux
MINILIBLOCALDIR = /usr/local/lib
MINILIBLOCALFILE = $(addprefix $(MINILIBXDIR)/,$(MINILIBXNAME))

# COMPILATION CMNDS
CC = cc
FT_FLAGS = -g -Wextra -Werror -Wall
INCLUDES = -I$(LIBFTDIR)
LDFLAGS = -L$(MINILIBLOCALDIR) -lmlx -lXext -lX11 -L$(LIBFTDIR) -lft -lm

# COMPILATION FILES
SRCS = $(addprefix $(SRCDIR)/,$(SRC))
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# BONUS COMPILATION FILES
BNS_SRCS = $(addprefix $(BNSDIR)/,$(BNS))
BNS_OBJS = $(addprefix $(OBJDIR)/,$(BNS:.c=.o))

all: $(NAME)

$(NAME): makelibft makeminilibx $(OBJS)
	@echo "\n\nCompiling Project\n"
	$(CC) $(FT_FLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
	@echo "\n\nCompilation finished successfully\nHave fun breaking things\n"

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(HDRS) | $(LIBFTNAME) $(MINILIBLOCALFILE)
	$(CC) $(FT_FLAGS) $(INCLUDES) -c $< -o $@

makelibft:
	@echo "\n\nCompiling LibfFt\n"
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@echo "\n\nLibft is compiled & ready\n"

makeminilibx:
	@echo "\n\nCompiling MiniLibX\n"
	@make -C $(MINILIBXDIR)
	@cp $(MINILIBXDIR)/$(MINILIBXNAME) .
	@echo "\n\nMiniLibX is compiled & ready\n"

bonus: makelibft makeminilibx $(OBJS) $(BNS_OBJS)
	@echo "\n\nCompiling Bonus Files\n"
	$(CC) $(FT_FLAGS) -o $(NAME) $(BNS_OBJS) $(OBJS) $(LDFLAGS)
	@echo "\n\nCompilation finished successfully\nHave fun breaking things\n"

$(BNS_OBJS): $(OBJDIR)/%.o : $(BNSDIR)/%.c $(HDRS) | $(LIBFTNAME) $(MINILIBLOCALFILE)
	$(CC) $(FT_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(BNS_OBJS)
	@make -C $(LIBFTDIR) clean
	@make -C $(MINILIBXDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTNAME)
	rm -f $(MINILIBXNAME)

re: fclean all

.PHONY: all clean fclean re
