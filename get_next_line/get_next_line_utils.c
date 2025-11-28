/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:53:15 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/28 15:12:22 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	gnl_strlen(const char *str)
{
	unsigned int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *str, int c)
{
	unsigned int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*gnl_strjoin(char *str1, const char *str2)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	total_len;

	total_len = gnl_strlen(str1) + gnl_strlen(str2);
	new_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	free(str1);
	j = 0;
	while (str2[j])
	{
		new_str[i + j] = str2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
