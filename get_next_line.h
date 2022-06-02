/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:23:11 by tkomeno           #+#    #+#             */
/*   Updated: 2022/06/02 00:26:48 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef int t_flag;

typedef enum e_bool
{
	false,
	true
}		t_bool;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
// #  define BUFFER_SIZE 256
# endif

char	*get_next_line(int fd);

#endif
