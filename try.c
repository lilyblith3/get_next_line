/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzari <lzari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:59:27 by lzari             #+#    #+#             */
/*   Updated: 2024/11/22 14:59:44 by lzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cup = read_file(fd, cup);
	if (!cup)
		return (NULL);
	line = copy_line(cup);
	cup = new_line(cup);
	return (line);
}