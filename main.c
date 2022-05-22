/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 04:56:51 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/06 12:48:18 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define FILENAME "test.txt"

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open(FILENAME, O_RDONLY);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	close(fd);
	free(buffer);
	return (0);
}
