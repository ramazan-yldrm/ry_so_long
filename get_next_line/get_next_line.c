/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:51:49 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/28 15:12:28 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*gnl_return(char *str1, char *str2)
{
	free (str1);
	free (str2);
	return (NULL);
}

static char	*clean_line(char *star)
{
	unsigned int	i;
	unsigned int	j;
	char			*new_str;

	if (!star)
		return (NULL);
	i = 0;
	while (star[i] && star[i] != '\n')
		i++;
	if (star[i] == '\n')
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + 1));
	if (new_str == NULL)
	{
		free(star);
		return (NULL);
	}
	j = 0;
	while (star[j] && j < i)
	{
		new_str[j] = star[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static char	*clean_stat(char *star)
{
	unsigned int	i;
	unsigned int	j;
	char			*new_str;

	i = 0;
	if (!star || star[i] == '\0')
		return (gnl_return(star, NULL));
	while (star[i] && star[i] != '\n')
		i++;
	if (star[i] == '\n')
		i++;
	new_str = (char *)malloc(sizeof(char) * (gnl_strlen(star) - i + 1));
	if (!new_str)
	{
		free (star);
		return (NULL);
	}
	j = 0;
	while (star[i])
		new_str[j++] = star[i++];
	free(star);
	new_str[j] = '\0';
	return (new_str);
}

static char	*read_line(int fd, char *star)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free (star);
		return (NULL);
	}
	while (!gnl_strchr(star, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes < 0)
			return (gnl_return(buffer, star));
		buffer[read_bytes] = '\0';
		star = gnl_strjoin(star, buffer);
		if (!star)
			break ;
	}
	free (buffer);
	return (star);
}

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = read_line(fd, stat);
	if (!stat)
		return (NULL);
	line = clean_line(stat);
	if (!line)
		return (NULL);
	stat = clean_stat(stat);
	if (!stat)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
