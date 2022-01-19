/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:43:42 by arudy             #+#    #+#             */
/*   Updated: 2022/01/19 14:12:53 by arudy            ###   ########.fr       */
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
	if (close(fd) == -1)
		return (ft_put_error("Error\nCan't close input file"));
	return (1);
}

int	count_map_lines(t_data *data, char *input)
{
	int		fd;
	char	*buff;

	fd = open(input, O_RDONLY);
	if (fd < 0)
		return (ft_put_error("Error\nCan't open input file"));
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		data->row++;
		free(buff);
	}
	free(buff);
	if (close(fd) == -1)
		return (ft_put_error("Error\nCan't close input file"));
	return (1);
}

int	init_map(t_data *data, char *input)
{
	int		fd;
	int		i;

	i = 0;
	data->lines = malloc(sizeof(char *) * (data->row + 1));
	fd = open(input, O_RDONLY);
	if (!data->lines || fd < 0)
		return (ft_put_error("Error\nCan't open input file"));
	while (1)
	{
		data->lines[i] = get_next_line(fd);
		if (!data->lines[i])
			break ;
		i++;
	}
	if (close(fd) == -1)
		return (ft_put_error("Error\nCan't close input file"));
	return (1);
}

int	check_components(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			if (!check_c(data->lines[i][j]))
				return (0);
			if (data->lines[i][j] == 'P')
				data->p += 1;
			if (data->lines[i][j] == 'E')
				data->e += 1;
			if (data->lines[i][j] == 'C')
				data->c += 1;
			j++;
		}
		i++;
	}
	if (data->p != 1 || data->e == 0 || data->c == 0)
		return (ft_put_error("Error\nOnly 1 P & at least 1 E & 1 C"));
	return (1);
}

int	parse_input(t_data *data, char *input)
{
	if (!check_input(input) || !count_map_lines(data, input))
		return (0);
	if (!init_map(data, input) || !check_line_length(data)
		|| !check_components(data) || !check_borders(data))
		return (free_map(data));
	return (1);
}
