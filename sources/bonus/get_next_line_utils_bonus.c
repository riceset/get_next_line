/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 05:48:28 by tkomeno           #+#    #+#             */
/*   Updated: 2022/07/14 06:00:54 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return ((size_t)(p - s));
}

size_t	ft_strlcat(char *dst, char *src, size_t final_dst_size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst == NULL && final_dst_size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (final_dst_size == 0)
		return (src_len);
	if (dst_len < final_dst_size)
	{
		i = 0;
		while (src[i] != '\0' && i < final_dst_size - dst_len - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + final_dst_size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize)
{
	size_t	i;

	if (cpysize)
	{
		i = 0;
		while (src[i] != '\0' && i < cpysize - 1)
		{
			dst[i] = src[i];
			i++;
		}
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	joined_size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	joined_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(sizeof(char) * joined_size);
	if (joined == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
	ft_strlcat(joined, s2, joined_size);
	free(s1);
	return (joined);
}
