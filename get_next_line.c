/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:24:41 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/04 11:37:46 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return ((size_t)(p - s));
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

char	*ft_strjoin(char *s1, char *s2)
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
			free(s1);
			return (j);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*curr_line;
	static char *save;
	int			i;
	char *		res;

	save = ft_strdup("");
	curr_line = malloc(BUFFER_SIZE);
	while (read(fd, curr_line, BUFFER_SIZE))
	{
		save = ft_strjoin(save, curr_line);
		//Use strnchar to find \n. if it was found get out of  the loop
		//and allocate memory for res. Then, fill it until \n and return it.
	}
	return (curr_line);
}

#include <fcntl.h>

int	main(void)
{
	char	*res;

	int fd = open("hello.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s\n", res);
	free(res);
	system("leaks a.out");
}
