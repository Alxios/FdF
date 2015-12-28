/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:52:03 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/28 13:53:38 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

#endif
