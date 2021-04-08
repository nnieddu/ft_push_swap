NAME				=	push_swap

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror

DIR_FT				=	srcs/ft_printf/
LIBS				=	-lft

VPATH				=	incs/ \
						srcs/ \
						# srcs/environment \

INCS				=	push_swap.h

SRCS				=	push_swap.c \

OPATH				=	objs/

OBJS				=	$(SRCS:%.c=$(OPATH)%.o)

all					:	$(NAME)

$(OPATH)%.o			:	%.c $(INCS)
						$(shell mkdir -p objs)
						$(CC) $(CFLAGS) -c $< -o $@

$(NAME)				:	$(OBJS)
						$(MAKE) -C $(DIR_FT)
						$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(DIR_FT) $(LIBS)

clean				:
						$(RM) $(OBJS)
						$(RM) -r push_swap.dSYM
						$(RM) -r $(OPATH)
						$(MAKE) $@ -C $(DIR_FT)

fclean				:	clean
						# $(RM) srcs/ft_printf/ft_printf.a
						$(RM) srcs/$(DIR_FT)/$(DIR_FT).a
						$(RM) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
