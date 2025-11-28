/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:22 by ryildiri          #+#    #+#             */
/*   Updated: 2025/07/07 13:59:48 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	total_len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((total_len * sizeof(char)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = ((unsigned char *)s1)[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = ((unsigned char *)s2)[j++];
	str[i] = '\0';
	return (str);
}
