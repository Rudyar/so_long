/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:39:40 by arudy             #+#    #+#             */
/*   Updated: 2022/01/20 18:13:58 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_c(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		return (ft_put_error("Error\nMap must be fill with 0 1 C E P only !"));
	return (1);
}

int	check_line_length(t_data *data)
{
	int	i;

	i = 1;
	data->col = ft_strlen(data->lines[0]);
	while (data->lines[i])
	{
		if ((int)ft_strlen(data->lines[i]) != data->col)
			return (ft_put_error("Error\nMap have to be rectangular"));
		i++;
	}
	return (1);
}

int	is_full_one(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_borders(t_data *data)
{
	int	i;

	i = 0;
	if (!is_full_one(data->lines[0])
		|| !is_full_one(data->lines[data->row - 1]))
		return (ft_put_error("Error\nMap have to be bordered by 1"));
	while (i < data->row)
	{
		if (data->lines[i][0] != '1' || data->lines[i][data->col - 1] != '1')
			return (ft_put_error("Error\nMap have to be bordered by 1"));
		i++;
	}
	return (1);
}

int	check_xpm(void)
{
	
}
