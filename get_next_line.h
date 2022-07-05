/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:23:11 by tkomeno           #+#    #+#             */
/*   Updated: 2022/07/04 23:37:39 by tkomeno          ###   ########.fr       */
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
	FALSE,
	TRUE
}		t_bool;


typedef enum e_status
{
	FAIL,
	SUCCESS
} t_status;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_bzero(void *b, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strcmp(char *s1, char *s2);
char *free_all(char *line, char *buffer, char *remainder, t_status status);
size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize);
size_t	ft_strlcat(char *dst, const char *src, size_t f_dst_s);


#endif
