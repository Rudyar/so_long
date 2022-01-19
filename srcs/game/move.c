/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:00:24 by arudy             #+#    #+#             */
/*   Updated: 2022/01/19 18:07:19 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_up(t_data *data)
{
	data->nb_mv++;
	printf("Move up\n");
	printf("Nb de mouvs : %d\n", data->nb_mv);
}

void	move_down(t_data *data)
{
	data->nb_mv++;
	printf("Move down\n");
	printf("Nb de mouvs : %d\n", data->nb_mv);
}

void	move_left(t_data *data)
{
	data->nb_mv++;
	printf("Move left\n");
	printf("Nb de mouvs : %d\n", data->nb_mv);
}

void	move_right(t_data *data)
{
	data->nb_mv++;
	printf("Move right\n");
	printf("Nb de mouvs : %d\n", data->nb_mv);
}
