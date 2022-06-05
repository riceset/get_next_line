/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 06:31:23 by tkomeno           #+#    #+#             */
/*   Updated: 2022/06/05 05:43:49 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *b, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	int i;
	char *line;
	char *buffer;
	char *remainder;
	ssize_t read_return;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);

	line = ft_strdup("");
	if (line == NULL)
		return (NULL);

	while (true)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);

		read_return = read(fd, buffer, BUFFER_SIZE);

		if (read_return == 0 || read_return == -1)
			break ;

		line = ft_strjoin(line, buffer);

		if (line == NULL)
			return (NULL);

		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == '\n')
			{
				return (line);
			}
			i++;
		}
	}

	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return ((size_t)(p - s));
}

void	*ft_bzero(void *b, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = 0;
		i++;
	}
	return (b);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize)
{
	size_t	i;

	if (cpysize)
	{
		i = -1;
		while (src[++i] && i < cpysize - 1)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s1) + 1;
	dup = malloc(size);
	if (dup)
		ft_strlcpy(dup, s1, size);
	return (dup);
}

size_t	ft_strlcat(char *dst, const char *src, size_t f_dst_s)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst && f_dst_s == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (f_dst_s == 0)
		return (src_len);
	if (dst_len < f_dst_s)
	{
		i = -1;
		while (src[++i] && i + 1 < f_dst_s - dst_len)
			dst[dst_len + i] = src[i];
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + f_dst_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j;
	size_t	js;

	if (s1 && s2)
	{
		js = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
		j = malloc(js);
		if (j)
		{
			ft_strlcpy(j, s1, ft_strlen(s1) + 1);
			ft_strlcat(j, s2, js);
			return (j);
		}
	}
	return (NULL);
}
