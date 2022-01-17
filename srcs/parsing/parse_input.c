/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:43:42 by arudy             #+#    #+#             */
/*   Updated: 2022/01/17 18:23:00 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_input(char *input)
{
	if (ft_strlen(input) == 0)
		return (ft_put_error("Eroor\nNo input file"));
	if (!ft_strnstr(input, ".ber", ft_strlen(input)))
		return (ft_put_error("Error\nMust be a .ber file"));
	return (1);
}

int	parse_input(t_map *map, char *input)
{
	int		i;
	int		count;
	int		fd;
	char	buff[2];

	i = 0;
	count = 1;
	fd = 1;
	buff[1] = '\0';
	if (!check_input(input))
		return (0);
	fd = open(input, O_RDONLY);
	if (fd < 0)
		return (ft_put_error("Error\nCan't read input file"));
	while (count > 0)
	{
		
	}

	return (0);
}
