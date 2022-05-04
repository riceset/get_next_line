/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:24:41 by tkomeno           #+#    #+#             */
/*   Updated: 2022/05/04 09:38:24 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *res = malloc(BUFFER_SIZE);
	read(fd, res, BUFFER_SIZE);
	return (res);
}

int main(void)
{
	char *p = get_next_line(1);
	write(1, p, BUFFER_SIZE);
	free(p);
}
