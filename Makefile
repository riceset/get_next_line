# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 02:45:29 by tkomeno           #+#    #+#              #
#    Updated: 2022/09/17 13:35:43 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CFLAGS = -Wall -Wextra -Werror -I includes

FILES = main.c \
		get_next_line.c \
		get_next_line_utils.c

BFILES = main.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c


SRCS = $(addprefix srcs/,$(FILES))
BSRCS = $(addprefix srcs/bonus/,$(BFILES))

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

ifdef WITH_BONUS
	OBJS = $(BOBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

bonus:
	@make WITH_BONUS=TRUE

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
