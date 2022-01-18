/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:43:42 by arudy             #+#    #+#             */
/*   Updated: 2022/01/18 19:18:43 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_input(char *input)
{
	int		i;
	int		j;
	int		fd;
	char	*to_find;

	i = ft_strlen(input) - 1;
	j = 0;
	to_find = "reb.";
	if (ft_strlen(input) == 0)
		return (ft_put_error("Error\nNo input file"));
	while (j < 4)
	{
		if (to_find[j] != input[i])
			return (ft_put_error("Error\nMust be a .ber file"));
		j++;
		i--;
	}
	fd = open(input, O_RDONLY);
	if (fd < 0)
		return (ft_put_error("Error\nCan't find / open input file"));
	close(fd);
	return (1);
}

int	count_map_lines(t_map *map, char *input)
{
	int		fd;
	char	*buff;

	map->x = 0;
	fd = open(input, O_RDONLY);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break;
		map->x++;
		free(buff);
	}
	close(fd);
	free(buff);
	return (1);
}

int	parse_input(t_map *map, char *input)
{
	if (!check_input(input))
		return (0);
	if (!count_map_lines(map, input))
		return (ft_put_error("Error\nMap is not valid"));
		// return (ft_map_error("Error\nMap is not valid", map));
	return (1);
}
