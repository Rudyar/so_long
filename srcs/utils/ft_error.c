/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:07:18 by arudy             #+#    #+#             */
/*   Updated: 2022/01/19 18:14:19 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_put_error(char *msg)
{
	printf("%s\n", msg);
	return (0);
}

int	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->row)
	{
		free(data->lines[i]);
		i++;
	}
	free(data->lines);
	return (0);
}
