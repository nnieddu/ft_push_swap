# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 14:35:45 by ninieddu          #+#    #+#              #
#    Updated: 2021/04/13 16:47:28 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

CHEKCER				=	checker

CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror

LIBS				=	-lft -lftprintf -lgnl

VPATH				=	incs/ \
						srcs/ \
						srcs/checker \
						srcs/push_swap

DIR_LIBFT			=	srcs/ext/libft/

DIR_FT_PRINTF		=	srcs/ext/ft_printf/

DIR_GNL				=	srcs/ext/ft_get_next_line/

INCS				=	push_swap.h

INCS_CHECKER		=	checker.h

SRCS				=	push_swap.c

SRCS_CHECKER		=	checker.c \
						utils.c \
						exec.c \
						errors.c

OPATH				=	objs/push_swap/

OPATH_CHECKER		=	objs/objs_checker/

OBJS				=	$(SRCS:%.c=$(OPATH)%.o)

OBJS_CHECKER		=	$(SRCS_CHECKER:%.c=$(OPATH_CHECKER)%.o)

all					:	$(NAME) $(CHEKCER)

$(OPATH)%.o			:	%.c $(INCS)
						$(shell mkdir -p objs)
						$(shell mkdir -p objs/push_swap)
						$(CC) $(CFLAGS) -c $< -o $@

$(NAME)				:	$(OBJS)
						$(MAKE) -C $(DIR_LIBFT)
						$(MAKE) -C $(DIR_FT_PRINTF)
						$(MAKE) -C $(DIR_GNL)
						$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(DIR_LIBFT) -L $(DIR_FT_PRINTF) -L $(DIR_GNL) $(LIBS)

$(OPATH_CHECKER)%.o		:	%.c $(INCS_CHECKER)
						$(shell mkdir -p objs/objs_checker)
						$(CC) $(CFLAGS) -c $< -o $@

$(CHEKCER)			:	$(OBJS_CHECKER)
						$(CC) $(CFLAGS) $(OBJS_CHECKER) -o $(CHEKCER) -L $(DIR_LIBFT) -L $(DIR_FT_PRINTF) -L $(DIR_GNL) $(LIBS)

clean				:
						$(RM) -r push_swap.dSYM
						$(RM) -rf objs/
						$(MAKE) $@ -C $(DIR_LIBFT)
						$(MAKE) $@ -C $(DIR_FT_PRINTF)
						$(MAKE) $@ -C $(DIR_GNL)

fclean				:	clean
						$(RM) srcs/ext/libft/libft.a
						$(RM) srcs/ext/ft_printf/libftprintf.a
						$(RM) $(NAME)
						$(RM) $(CHEKCER)

re					:	fclean all

.PHONY				:	all clean fclean re
