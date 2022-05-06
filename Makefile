# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 02:45:29 by tkomeno           #+#    #+#              #
#    Updated: 2022/05/06 05:07:41 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
EXE = main

CC = gcc
DB = lldb
RM = rm -rf
AR = ar -rc

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

DEFAULT_BS=256

ifdef BS
	CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BS)
else
	CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(DEFAULT_BS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXE) $(EXE).dSYM

re: fclean all

compile: all
	@$(CC) -g $(EXE).c $(NAME) -o $(EXE)

run: compile
	@./$(EXE)

db: compile
	clear
	$(DB) $(EXE)

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@norminette -R CheckDefine *.h

.PHONY: all clean fclean re compile run db norm
