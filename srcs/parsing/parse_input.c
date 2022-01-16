/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:43:42 by arudy             #+#    #+#             */
/*   Updated: 2022/01/16 17:02:34 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_input(char *input)
{
	// if (ft_strlen(input) == 0)
	// 	return (0);
	// if (!ft_strnstr(input, ".ber", ft_strlen(input)))
	// 	return (0);
	printf("Checkinput\n %s", input);
	return (0);
}

int	parse_input(t_map *map, char *input)
{
	// int		i;
	// int		count;
	// int		fd;
	// char	buff[2];
	(void)map;
	// i = 0;
	// count = 1;
	// fd = 1;
	// buff[1] = '\0';
	if (!check_input(input))
		return (0);
	// fd = open(input, O_RDONLY);
	return (0);
}
