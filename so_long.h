/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:36:00 by arudy             #+#    #+#             */
/*   Updated: 2022/01/19 14:12:21 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data
{
	int		row;
	int		col;
	int		p;
	int		e;
	int		c;
	char	**lines;
}t_data;

int		parse_input(t_data *data, char *input);
int		ft_put_error(char *msg);
int		ft_strchr(char *s, char c);
int		free_map(t_data *data);
int		check_c(char c);
int		check_line_length(t_data *data);
int		check_borders(t_data *data);
size_t	ft_strlen(char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	init_data(t_data *data);
#endif
