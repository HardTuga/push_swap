# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:11:06 by lucas-ma          #+#    #+#              #
#    Updated: 2022/03/07 11:58:54 by pcampos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------ LIBRARY NAME ----------------------------------#

NAME	= libps.a

#----------------------------- COMMAND LINES ----------------------------------#

RM	= rm -rf
MV	= mv
MKD	= mkdir
CPY	= cp
PRINT	= printf

#------------------------------ DIRECTORIES -----------------------------------#

_SRC	=
_OBJ	=	../obj/
_LIBS	=	../libs/

#-------------------------------- COMPILER ------------------------------------#

CC	= gcc
CF	= -Wall -Wextra -Werror
AR	= ar rcs

#---------------------------------- FILES -------------------------------------#

FILES	=	operations.c operations2.c push_swap.c sort_array.c\
			sort_array2.c up_2_5.c utils.c utils2.c utils3.c utils4.c errors.c

SRCS	=		$(addprefix $(_SRC), $(FILES))
OBJS	=		$(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS))

#---------------------------------- RULES -------------------------------------#

all: $(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CF) -c $< -o $@

$(NAME): $(_LIBS) $(_LIBS)$(NAME)
$(_LIBS)$(NAME): $(_OBJ) $(OBJS)
	$(AR) $(_LIBS)$(NAME) $(OBJS)

#---------------------------- DIRECTORIES CREATION ---------------------------#

$(_OBJ):
	$(MKD) $(_OBJ)

$(_LIBS):
	$(MKD) $(_LIBS)

$(_SRC):
	$(MKD) $(_SRC)

#---------------------------------- CLEAN ------------------------------------#

clean:
		@$(RM) $(_OBJ)$(OBJS)

fclean: clean
		@$(RM) $(_LIBS)$(NAME)

#---------------------------------- REST -------------------------------------#

re:	fclean all

.PHONY: all clean fclean re
