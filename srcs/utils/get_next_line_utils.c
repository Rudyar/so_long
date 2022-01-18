/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:45:16 by arudy             #+#    #+#             */
/*   Updated: 2022/01/18 17:45:52 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(sizeof(char) * (total_len + 1));
	if (!dst)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	free(s1);
	return (dst);
}
