/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzari <lzari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:37:49 by lzari             #+#    #+#             */
/*   Updated: 2024/11/22 18:37:23 by lzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*read_from_the_file(int fd, char *string)
{
	char	*buffer;
	ssize_t	b_read;

	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	b_read = 1;
	while (!ft_strchr(string, '\n') && b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		string = ft_strjoin(string, buffer);
		if (!string)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (string);
}

char	*get_line(char *string)
{
	int		i;
	char	*p;

	i = 0;
	if (!string || !string[i])
		return (NULL);
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
	{
		p[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		p[i] = '\n';
		i++;
	}
	p[i] = '\0';
	return (p);
}
char	*skip_new_line(char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	if (line == NULL || line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	while (line[i] && line[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * ft_strlen(line) - i + 1);
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		new_line[j++] = line[i++];
	new_line[j] = '\0';
	free(line);
	return (new_line);
}
// #include <fcntl.h>
// #include <stdio.h>
// #include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_from_the_file(fd, string);
	if (!string)
	{
		return (NULL);
	}
	line = get_line(string);
	if (!line)
		return (free(string), string = NULL, NULL);
	string = skip_new_line(string);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }
