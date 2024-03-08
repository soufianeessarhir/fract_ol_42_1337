/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:47:39 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/08 08:58:18 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int get_color(int iter)
{
	
	int color;
	if(iter == 80)
		iter = 0;
	
	color = (0x00FDFFFC >> 8) * iter;
	iter++;

	return color;		
} 
void	my_mlx_pixel_put(t_list *data, int x, int y, int color) 
{ 
	char	*dst; 
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); 
	*(unsigned int*)dst = color; 
}

void rebuild(t_list *fractol)
{
		mlx_clear_window(fractol->mlx,fractol->mlx_win);
		mlx_destroy_image(fractol->mlx,fractol->img);
		fractol->img = mlx_new_image(fractol->mlx, 800, 800); 
		fractol->addr = mlx_get_data_addr(fractol->img,&fractol->bits_per_pixel,&fractol->line_length,&fractol->endian); 
		draw_frct_m(fractol);
		mlx_put_image_to_window(fractol->mlx,fractol->mlx_win, fractol->img, 0, 0); 
}