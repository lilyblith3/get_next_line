/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzari <lzari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:55:21 by lzari             #+#    #+#             */
/*   Updated: 2024/11/21 15:20:15 by lzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*c;

	i = 0;
	len = ft_strlen(s1);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	l;
	size_t	i;
	char	*c;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	l = ft_strlen(s);
	if (len > l - start)
		len = l - start;
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	while (i < len)
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || s2)
		return (NULL);
	r = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r)
		return (NULL);
	while (s1)
		r[i++] = s1[j++];
	j = 0;
	while (s2)
		r[i++] = s2[j++];
	r[i] = '\0';
	free(s1);
	return (r);
}
