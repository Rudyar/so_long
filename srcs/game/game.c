/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:40:02 by arudy             #+#    #+#             */
/*   Updated: 2022/01/20 17:44:32 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	get_img(t_data *data, char c)
{
	if (c == '1')
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
				&data->img_size, &data->img_size);
	else if (c == '0')
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/bg.xpm",
				&data->img_size, &data->img_size);
	else if (c == 'P')
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/skier_spawn.xpm",
				&data->img_size, &data->img_size);
	else if (c == 'E')
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
				&data->img_size, &data->img_size);
	else if (c == 'C')
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/col.xpm",
				&data->img_size, &data->img_size);
}

void	put_img_to_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			get_img(data, data->lines[i][j]);
			mlx_put_image_to_window(data->mlx, data->win,
				data->img, j * 75, i * 75);
			mlx_destroy_image(data->mlx, data->img);
			j++;
		}
		i++;
	}
}

void	game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->col * 75,
			data->row * 75, "So Long");
	put_img_to_map(data);
	mlx_key_hook(data->win, &key_press, data);
	mlx_hook(data->win, 17, 17, &ft_exit, data);
	mlx_loop(data->mlx);
}
