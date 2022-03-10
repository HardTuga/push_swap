# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 15:07:52 by lucas-ma          #+#    #+#              #
#    Updated: 2022/03/04 11:48:21 by pcampos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################ PROGRAM ################

NAME    =        push_swap

################ TERMINAL ###############

RMV        =        rm -f
MKD        =        mkdir
PRT        =        printf
MKE        =        make
CPY        =        cp

################# COLORS ################

--GRN    =        \033[32m
--RED    =        \033[31m
--WHT    =        \033[39m

################# DIRS ##################

_SRC    =        src/
_OBJ 	=		 obj/
_LIB    =        libs/
_BIN    =        ./

############### COMPILER ################

CC        =        gcc
CF        =        -Wall -Werror -Wextra

################ FILES ##################

SRCS    =        $(_SRC)push_swap.c
OBJS    =        $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS))
DEPS    =        $(_LIB)libps.a
LIBS    =        -lps

################ RULES ##################

all: $(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CF) -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	$(CC) $(CF) $(LIBS) $(OBJS) -o $@ -L $(_LIB)

################ DEPS ###################

$(_LIB)libps.a: $(shell make -C src/ -q libps.a || echo force)
	$(MKE) libps.a -C src/

############## STRUCTURE ################

$(_OBJ):
	$(MKD) $(_OBJ)

$(_LIB):
	$(MKD) $(_LIB)

$(_SRC):
	$(MKD) $(_SRC)

$(_BIN):
	$(MKD) $(_BIN)

################### CLEAN ###############

clean:
	$(RMV) -r $(_OBJ)

fclean: clean
	$(RMV) -r $(NAME)
	$(RMV) -r $(NAME_BONUS)
	$(RMV) -r $(_LIB)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re force
