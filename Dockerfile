# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 07:55:33 by tkomeno           #+#    #+#              #
#    Updated: 2022/06/20 15:43:56 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM gcc:latest

RUN apt-get update

RUN apt-get upgrade -y

RUN apt-get install valgrind -y

COPY . /get_next_line

WORKDIR /get_next_line

RUN cc *.c -o main

CMD [ "valgrind", "./main" ]
