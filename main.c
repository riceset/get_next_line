/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 04:56:51 by tkomeno           #+#    #+#             */
/*   Updated: 2022/06/05 05:40:57 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("abc.txt", O_RDONLY);

	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("%s", line);
	}

	close(fd);
	free(line);

	return (0);
}
