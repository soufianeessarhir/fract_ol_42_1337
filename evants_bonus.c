/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evants_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:53:24 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/10 11:14:51 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int mouse_hook(int keycode, int x, int y, t_list *fractol) 
{ 
    double zoom_amount = 0.2; 
	fractol->off_x = (fractol->r_min - fractol->r_max)/ 800; 
	fractol->off_y = (fractol->i_min - fractol->i_max)/ 800; 
    if (keycode == 4) 
	{
		fractol->r_min += (x * fractol->off_x) * zoom_amount;
		fractol->r_max -= ((800 - x) * fractol->off_x) * zoom_amount;
		fractol->i_max -= ((800 - y) * fractol->off_y) * zoom_amount;
		fractol->i_min += (y * fractol->off_y) * zoom_amount;
	}
    else if (keycode == 5 ) 
	{
		fractol->r_min -= (x * fractol->off_x) * zoom_amount;
		fractol->r_max += ((800 - x) * fractol->off_x) * zoom_amount;
		fractol->i_max += ((800 - y) * fractol->off_y) * zoom_amount;
		fractol->i_min -= (y * fractol->off_y) * zoom_amount;
	}
	rebuild(fractol);
    return 0; 
} 
void helper(int keycode, t_list *fractol)
{
	if (keycode == 69)
	{
		fractol->r_color = fractol->r_color + 5;
		rebuild(fractol);
	}
	if (keycode == 78)
	{
		fractol->r_color = fractol->r_color - 5;
		rebuild(fractol);
	}
	if (keycode == 53)
	{
		mlx_clear_window(fractol->mlx,fractol->mlx_win);
		mlx_destroy_image(fractol->mlx,fractol->img);
		exit(1);
	}

}

int key_hook(int keycode, t_list *fractol)
{
	if(keycode == 126)
	{
		fractol->i_min += 0.1;
		fractol->i_max += 0.1;
	}
	if (keycode == 125)
	{
		fractol->i_max -= 0.1;
		fractol->i_min -= 0.1;
	}
	if (keycode == 124)
	{
		fractol->r_max -= 0.1;
		fractol->r_min -= 0.1;
	}
	if (keycode == 123)
	{
		fractol->r_max += 0.1;
		fractol->r_min += 0.1;
	}
	
	rebuild(fractol); 
	helper(keycode,fractol);
	return 0;
}
int destroy(t_list *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	exit(0);
	return 0;
}