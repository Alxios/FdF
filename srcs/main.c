#include <mlx.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	size_t	height;
	size_t	width;
	size_t	zoom;
}				t_env;

int		rgb_color(int red, int green, int blue)
{
	int	res;

	res = red * green * blue - 1;
	return (res);
}

void	draw_square(t_env *e, int pos_x, int pos_y, int color)
{
	int size = 32 * e->zoom;
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
			mlx_pixel_put(e->mlx, e->win, xPos + x , yPos + y, color);
		}
	}
}

/*void	draw_line(t_env *e, int	pos_x, int pos_y, int color)
{

}*/

void	draw(t_env *e)
{
	//draw_square(e, 0, -3, 0xFF0000);
	draw_square(e, 0, 0, rand());
	//draw_square(e, 0, 1, 0x00FF00);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

/*void	refresh(t_env *e)
{
	size_t x = 0;
	size_t y = 0;
	ft_putstr("coucou");
	while (x++ < e->width)
	{
		y = 0;
		while (y++ < e->height)
			mlx_pixel_put(e->mlx, e->win, x, y, 0x000000);

	}
}*/

int		key_hook(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
		e->zoom += 1;
	else if(keycode == 125)
		e->zoom -= 1;
	draw(e);
	return (0);
}

int		main(void)
{
	t_env e;

	e.height = 420;
	e.width = 420;
	e.zoom = 1;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.height, e.width, "Attention un renard");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
