/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:23:11 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/06 12:42:37 by tkomeno          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t f_dst_s);
size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
