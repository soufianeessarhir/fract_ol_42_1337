/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:47:39 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/27 19:51:52 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, t_list *fractol)
{
	int	color;

	if (iter == 80)
		iter = 0;
	color = (0x00A020F0 >> 3) *(iter * fractol->r_color);
	iter++;
	return (color);
}

void	my_mlx_pixel_put(t_list *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	rebuild(t_list *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_image(fractol->mlx, fractol->img);
	fractol->img = mlx_new_image(fractol->mlx, 800, 800);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->line_length, &fractol->endian);
	draw_frct_m(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
}

double	map(double x, double in_max, double out_min, double out_max)
{
	return (((x - 0) * (out_max - out_min) / (in_max - 0) + out_min));
}

t_list	init_data_fractol(void)
{
	t_list	fractol;

	fractol.zoom_factor = 1;
	fractol.off_x = 0;
	fractol.off_y = 0;
	fractol.i_max = 2;
	fractol.i_min = -2;
	fractol.r_max = 2;
	fractol.r_min = -2;
	fractol.r_color = 6000;
	fractol.r_j = 0;
	fractol.i_j = 0;
	fractol.zoom_factor = 1;
	fractol.mlx = mlx_init();
	fractol.mlx_win = mlx_new_window(fractol.mlx, 800, 800, "Hello world!");
	fractol.img = mlx_new_image(fractol.mlx, 800, 800);
	fractol.addr = mlx_get_data_addr(fractol.img, &fractol.bits_per_pixel,
			&fractol.line_length, &fractol.endian);
	return (fractol);
}
