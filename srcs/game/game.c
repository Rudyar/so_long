/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:40:02 by arudy             #+#    #+#             */
/*   Updated: 2022/01/19 18:16:33 by arudy            ###   ########.fr       */
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

int	key_press(int keycode, t_data *data)
{
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

void	put_img_to_map(t_data *data)
{
	int	i;
	int	j;
	int	r;
	int	c;
	int	img_size;

	i = 0;
	r = 0;
	img_size = 75;
	while (i < data->row)
	{
		j = 0;
		c = 0;
		while (j < data->col)
		{
			if (data->lines[i][j] == '1')
				data->img = mlx_xpm_file_to_image(data->mlx, "assets/wall_2.xpm", &img_size, &img_size);
			else if (data->lines[i][j] == '0')
				data->img = mlx_xpm_file_to_image(data->mlx, "assets/bg_1.xpm", &img_size, &img_size);
			else if (data->lines[i][j] == 'P')
				data->img = mlx_xpm_file_to_image(data->mlx, "assets/player_1.xpm", &img_size, &img_size);
			else if (data->lines[i][j] == 'E')
				data->img = mlx_xpm_file_to_image(data->mlx, "assets/exit_1.xpm", &img_size, &img_size);
			else if (data->lines[i][j] == 'C')
				data->img = mlx_xpm_file_to_image(data->mlx, "assets/col_1.xpm", &img_size, &img_size);
			mlx_put_image_to_window(data->mlx, data->win,data->img, c, r);
			mlx_destroy_image(data->mlx, data->img);
			c += 75;
			j++;
		}
		r += 75;
		i++;
	}
}

void	game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->col * 75, data->row * 75, "So Long");
	put_img_to_map(data);
	mlx_key_hook(data->win, &key_press, data);
	mlx_loop(data->mlx);
}
