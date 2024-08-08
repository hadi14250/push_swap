# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 09:35:00 by hakaddou          #+#    #+#              #
#    Updated: 2022/05/31 09:19:17 by hakaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	get_next_line.c get_next_line_utils.c push_swap_bonus.c add_new.c checkers.c \
					ops.c seperate.c a_operations.c b_operations.c \
					assign.c parse_operations.c parse_operations_v2.c extras.c sort_normally.c \
					sort_4_chunks.c chunk_extras.c max_and_tops.c long_limits.c 
					
OBJS			= $(SRCS:.c=.o)

BONUS			= get_next_line.c get_next_line_utils.c push_swap_bonus.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc -g3
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= checker

all:			$(NAME)

$(NAME):		$(OBJS)
				 $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
