/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:36:00 by arudy             #+#    #+#             */
/*   Updated: 2022/01/20 11:46:58 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

# include <mlx.h>
# include <mlx_int.h>
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
	int		nb_mv;
	int		p_pos_x;
	int		p_pos_y;
	int		img_size;
	char	**lines;
	void	*mlx;
	void	*win;
	void	*img;
}t_data;

int		parse_input(t_data *data, char *input);
int		ft_put_error(char *msg);
int		ft_strchr(char *s, char c);
int		free_map(t_data *data);
int		check_c(char c);
int		check_line_length(t_data *data);
int		check_borders(t_data *data);
int		ft_exit(t_data *data);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	init_data(t_data *data);
void	game(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
#endif
