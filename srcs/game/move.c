/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:00:24 by arudy             #+#    #+#             */
/*   Updated: 2022/01/20 16:57:22 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_win(t_data *data)
{
	if (data->c == 0)
	{
		printf("Yeah, good job ! \n");
		ft_exit(data);
	}
}

void	move_up(t_data *data)
{
	if (data->lines[data->p_pos_y - 1][data->p_pos_x] == 'E')
		check_win(data);
	else
	{
		if (data->lines[data->p_pos_y - 1][data->p_pos_x] == '1')
			return ;
		if (data->lines[data->p_pos_y - 1][data->p_pos_x] == 'C')
			data->c--;
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/skier_back.xpm",
				&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			data->p_pos_x * 75, (data->p_pos_y - 1) * 75);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/bg.xpm",
				&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			data->p_pos_x * 75, data->p_pos_y * 75);
		mlx_destroy_image(data->mlx, data->img);
		data->lines[data->p_pos_y - 1][data->p_pos_x] = 'P';
		data->lines[data->p_pos_y][data->p_pos_x] = '0';
		data->nb_mv++;
		printf("Moves : %d\n", data->nb_mv);
	}
}

void	move_down(t_data *data)
{
	if (data->lines[data->p_pos_y + 1][data->p_pos_x] == 'E')
		check_win(data);
	else
	{
		if (data->lines[data->p_pos_y + 1][data->p_pos_x] == '1')
			return ;
		if (data->lines[data->p_pos_y + 1][data->p_pos_x] == 'C')
			data->c--;
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/skier_front.xpm",
				&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			data->p_pos_x * 75, (data->p_pos_y + 1) * 75);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/bg.xpm",
				&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			data->p_pos_x * 75, data->p_pos_y * 75);
		mlx_destroy_image(data->mlx, data->img);
		data->lines[data->p_pos_y + 1][data->p_pos_x] = 'P';
		data->lines[data->p_pos_y][data->p_pos_x] = '0';
		data->nb_mv++;
		printf("Moves : %d\n", data->nb_mv);
	}
}

void	move_left(t_data *data)
{
	if (data->lines[data->p_pos_y][data->p_pos_x - 1] == 'E')
		check_win(data);
	else
	{
		if (data->lines[data->p_pos_y][data->p_pos_x - 1] == '1')
			return ;
		if (data->lines[data->p_pos_y][data->p_pos_x - 1] == 'C')
			data->c--;
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/skier_left.xpm",
				&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			(data->p_pos_x - 1) * 75, data->p_pos_y * 75);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/bg.xpm",
				&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			data->p_pos_x * 75, data->p_pos_y * 75);
		mlx_destroy_image(data->mlx, data->img);
		data->lines[data->p_pos_y][data->p_pos_x - 1] = 'P';
		data->lines[data->p_pos_y][data->p_pos_x] = '0';
		data->nb_mv++;
		printf("Moves : %d\n", data->nb_mv);
	}
}

void	move_right(t_data *data)
{
	if (data->lines[data->p_pos_y][data->p_pos_x + 1] == 'E')
		check_win(data);
	else
	{
		if (data->lines[data->p_pos_y][data->p_pos_x + 1] == '1')
			return ;
		if (data->lines[data->p_pos_y][data->p_pos_x + 1] == 'C')
			data->c--;
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/skier_right.xpm",
				&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			(data->p_pos_x + 1) * 75, data->p_pos_y * 75);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_xpm_file_to_image(data->mlx, "assets/bg.xpm",
				&data->img_size, &data->img_size);
		mlx_put_image_to_window(data->mlx, data->win, data->img,
			data->p_pos_x * 75, data->p_pos_y * 75);
		mlx_destroy_image(data->mlx, data->img);
		data->lines[data->p_pos_y][data->p_pos_x + 1] = 'P';
		data->lines[data->p_pos_y][data->p_pos_x] = '0';
		data->nb_mv++;
		printf("Moves : %d\n", data->nb_mv);
	}
}
