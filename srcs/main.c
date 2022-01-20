/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:36:12 by arudy             #+#    #+#             */
/*   Updated: 2022/01/20 10:28:04 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	init_data(&data);
	if (!parse_input(&data, av[1]))
		return (0);
	game(&data);
	return (0);
}
