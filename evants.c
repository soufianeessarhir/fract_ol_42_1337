/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evants.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:53:24 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/10 13:47:34 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, int x, int y, t_list *fractol)
{
	double	zoom_amount;

	zoom_amount = 0.1;
	(void)x;
	(void)y;
	if (keycode == 4)
		fractol->zoom_factor *= (1 + zoom_amount);
	else if (keycode == 5)
		fractol->zoom_factor /= (1 + zoom_amount);
	draw_frct_m(fractol);
	rebuild(fractol);
	return (0);
}

int	key_hook(int keycode, t_list *fractol)
{
	if (keycode == 53)
	{
		mlx_clear_window(fractol->mlx, fractol->mlx_win);
		mlx_destroy_image(fractol->mlx, fractol->img);
		exit(1);
	}
	return (0);
}

int	destroy(t_list *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	exit(0);
	return (0);
}
