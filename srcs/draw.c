/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:40:21 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/28 15:43:13 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_cube(t_env *e, int pos_x, int pos_y)
{
	int size = 64 + e->zoom * 10;
	int	xPos;
	int	yPos;
	int	y = 0;
	int	x = 0;

	xPos = (e->height / 2) - size / 2  + pos_x * size;
	yPos = (e->width / 2) - size/ 2 + pos_y * size;
	while (y++ < size)
	{
		x = 0;
		while (x++ < size)
		{
			mlx_pixel_put(e->mlx, e->win, xPos + x , yPos + y,
					rgb_color(x, y, 100));
		}
	}
}

/*void	draw_plan(t_env *e)
{
	//int	xPos;
	int	yPos;
	int	y = 0;
	//int	x = 0;
	//xPos = (e->height / 2) - 32 / 2;
	yPos = (e->width / 2) - 32 / 2;
	while (y++ < e->width / 32)
	{
		x = 0;
		while (x++ > e->height)
			mlx_pixel_put(e->mlx, e->win, x, yPos
	}
}*/

