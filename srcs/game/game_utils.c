/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:14:35 by arudy             #+#    #+#             */
/*   Updated: 2022/01/20 12:15:33 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_exit(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	exit (0);
}

void	get_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->lines[i][j] == 'P')
			{
				data->p_pos_x = j;
				data->p_pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	key_press(int keycode, t_data *data)
{
	get_player_position(data);
	if (keycode == XK_Escape)
		ft_exit(data);
	else if (keycode == 119)
		move_up(data);
	else if (keycode == 115)
		move_down(data);
	else if (keycode == 97)
		move_left(data);
	else if (keycode == 100)
		move_right(data);
	return (0);
}
