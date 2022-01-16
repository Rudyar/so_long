/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:36:00 by arudy             #+#    #+#             */
/*   Updated: 2022/01/16 17:01:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_map
{
	int		x;
	int		y;
	int		collectibles;
	char	**lines;
}t_map;

int		parse_input(t_map *map, char *input);
size_t	ft_strlen(char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif
