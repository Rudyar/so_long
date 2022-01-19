/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:47:37 by arudy             #+#    #+#             */
/*   Updated: 2022/01/19 10:00:51 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_trim_stat(char *s)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (ft_free(s));
	dst = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!dst)
		return (NULL);
	i++;
	while (s[i] != '\0')
		dst[j++] = s[i++];
	dst[j] = '\0';
	free(s);
	return (dst);
}

char	*make_line(char *stat)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (stat[i] == '\0')
		return (NULL);
	while (stat[i] != '\0' && stat[i] != '\n')
		i++;
	if (stat[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free(stat));
	while (stat[j] != '\0' && stat[j] != '\n')
	{
		line[j] = stat[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*read_line(int fd, char *stat)
{
	int			count;
	char		*buff;

	count = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (ft_strchr(stat, '\n') == 0 && count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
			break ;
		buff[count] = '\0';
		stat = ft_strjoin(stat, buff);
	}
	free(buff);
	return (stat);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!stat)
	{
		stat = malloc(sizeof(char) * 1);
		if (!stat)
			return (NULL);
		stat[0] = '\0';
	}
	stat = read_line(fd, stat);
	if (!stat)
		return (NULL);
	line = make_line(stat);
	stat = ft_trim_stat(stat);
	return (line);
}
