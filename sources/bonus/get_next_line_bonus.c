/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 05:47:59 by tkomeno           #+#    #+#             */
/*   Updated: 2022/07/21 21:28:55 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_bool	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (FALSE);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*get_buffer(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	read_bytes;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr(buffer, '\n') == FALSE)
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == 0 || read_bytes == -1)
			break ;
		tmp[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (buffer == NULL)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	if (read_bytes == -1)
		return (NULL);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + (buffer[i] == '\n') + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*prepare_next_line(char *buffer)
{
	char	*next;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	next = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (next == NULL)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i + j] != '\0')
	{
		next[j] = buffer[i + j];
		j++;
	}
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = get_buffer(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = prepare_next_line(buffer[fd]);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
// 	size_t	i;
// 	int		fd;
// 	char *s;

// 	fd = open("fileA",O_RDONLY);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		if (s == NULL || s[0] == '\0')
// 			printf("\n");
// 		s = get_next_line(fd);
// 		printf("line%zu : %s", i, s);
// 		i++;
// 	}
// }
