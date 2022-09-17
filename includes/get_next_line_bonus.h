/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 05:48:40 by tkomeno           #+#    #+#             */
/*   Updated: 2022/07/21 21:30:33 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}		t_bool;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*get_line(char *str);
char	*get_buffer(int fd, char *str);
char	*prepare_next_line(char *str);

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
t_bool	ft_strchr(char *s, char c);
char	*ft_strdup(const char *src);

#endif
