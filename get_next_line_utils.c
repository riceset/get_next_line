/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:24:56 by tkomeno           #+#    #+#             */
/*   Updated: 2022/07/04 23:37:41 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(char *s1)
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
}
