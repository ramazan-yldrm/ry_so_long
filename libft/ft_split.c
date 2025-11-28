/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:16:25 by ryildiri          #+#    #+#             */
/*   Updated: 2025/07/07 13:29:48 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	ft_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free_all(char **ptr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static char	**ft_toplace(char **ptr, const char *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (!s[j])
			break ;
		len = ft_word_len(s + j, c);
		ptr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (ptr[i] == NULL)
		{
			ft_free_all(ptr, i);
			return (NULL);
		}
		ft_strlcpy(ptr[i], s + j, len + 1);
		j += len;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		count;

	if (s == NULL)
		return (NULL);
	count = ft_count_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * (count + 1));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_toplace(ptr, s, c);
	return (ptr);
}
