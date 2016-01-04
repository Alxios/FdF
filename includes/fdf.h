/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:52:03 by agaspar           #+#    #+#             */
/*   Updated: 2016/01/04 17:51:35 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <libft.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	size_t	height;
	size_t	width;
	float	zoom;
	float	cam_x;
	float	cam_y;
}				t_env;

void	load_map(char *file);
void	draw_cube(t_env *e, int pos_x, int pos_y);

void	env_init(t_env *e);
int		rgb_color(int red, int green, int blue);

int		rgb_color(int r, int g, int b);

void	error(char *error);

#endif
