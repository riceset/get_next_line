/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 06:31:23 by tkomeno           #+#    #+#             */
/*   Updated: 2022/07/04 23:49:32 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 21

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	char		*buffer;
	static char	*remainder = NULL;
	ssize_t read_return ;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);

	if (remainder != NULL)
	{
		line = remainder;
		remainder = NULL;
	}
	else
	{
		line = ft_strdup("");
		if (line == NULL)
			return (NULL);
	}
	i = 0;
	while (TRUE)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		read_return = read(fd, buffer, BUFFER_SIZE);

		if (read_return == -1)
			break ;

		if (read_return == 0 && ft_strcmp(line, "") == 0)
			break ;

		else if (read_return == 0 && line[i] == '\0')
			return (line);

		line = ft_strjoin(line, buffer);
		if (line == NULL)
			return (free_all(line, buffer, remainder, SUCCESS));

		while (line[i] != '\0')
		{
			if (line[i] == '\n')
			{
				if (line[i + 1] != '\0')
				{
					remainder = ft_strdup(&line[i + 1]);
					if (remainder == NULL)
						return (free_all(line, buffer, remainder, FAIL));
				}
				line[i + 1] = '\0';
				return (free_all(line, buffer, remainder, SUCCESS));
			}
			i++;
		}
	}
	return (NULL);
}

char *free_all(char *line, char *buffer, char *remainder, t_status status)
{
	free(buffer);

	if (status == SUCCESS)
		return (line);
	free(line);
	free(remainder);
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
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = 0;
		i++;
	}
	return (b);
}
