# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 01:14:11 by hakaddou          #+#    #+#              #
#    Updated: 2022/11/12 17:30:28 by hakaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	add_new.c checkers.c push_swap.c ops.c seperate.c a_operations.c b_operations.c \
					assign.c parse_operations.c parse_operations_v2.c extras.c sort_normally.c \
					sort_4_chunks.c chunk_extras.c max_and_tops.c long_limits.c 
					
OBJS			= $(SRCS:.c=.o)

BONUS			=

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc -g3
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				 $(CC) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
					rm *.o

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
