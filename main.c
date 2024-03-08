/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:00:48 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/08 09:05:35 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

double map(double x, double in_min, double in_max, double out_min, double out_max) 
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
int check_squaring(double a,double b,t_list *fractol) 
{ 
	double tmp; 
	int i; 
	i = 0; 
	while ((a * a + b *  b < 4) && i < 80) 
	{ 
		tmp = a; 
		a = a*a - b*b +  fractol->x; 
		b = 2 * b * tmp + fractol->y; 
		i++; 
	} 
	if (i >= 80)
	{ 
		fractol->color = i;
		return(i); 
	}
	else 
	{ 
		fractol->color = i;
		return(0); 
	}
} 

void draw_frct_m(t_list *fractol) 
{ 
	int i; 
	int j; 
	i = 0; 
	j = 0; 
	
	while (i < 800) 
	{ 
		
			fractol->x = map(i,0,800,fractol->r_min,fractol->r_max);
		while (j < 800) 
		{ 
			fractol->y = map(j,0,800,fractol->i_min,fractol->i_max);
			if (check_squaring(fractol->x,fractol->y,fractol) != 0) 
				my_mlx_pixel_put(fractol, i, j,get_color(fractol->color) >> 16 );
			else
			{
				my_mlx_pixel_put(fractol, i, j,get_color(fractol->color) >> 2 );
			} 
			j++; 
		}
		j = 0; 
		i++; 
		
	} 
	
} 


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
		rebuild(fractol);
	}
	if (keycode == 125)
	{
		fractol->i_max -= 0.1;
		fractol->i_min -= 0.1;
		rebuild(fractol);
	}
	if (keycode == 124)
	{
		fractol->r_max -= 0.1;
		fractol->r_min -= 0.1;
		rebuild(fractol);
	}
	if (keycode == 123)
	{
		fractol->r_max += 0.1;
		fractol->r_min += 0.1;
		rebuild(fractol); 
	}
	helper(keycode,fractol);
	printf("%d\n",keycode);
	return 0;
}
int main(int ac , char **av) 
{
	av = NULL;
	if (ac > 0)
	{
		t_list fractol;
		fractol.zoom_factor = 1;
		fractol.off_x = 0;
		fractol.off_y = 0; 
		fractol.i_max = 2;
		fractol.i_min = -2;
		fractol.r_max = 2;
		fractol.r_min = -2;
		fractol.mlx = mlx_init(); 
		fractol.mlx_win =  mlx_new_window(fractol.mlx, 800, 800, "Hello world!"); 
		fractol.img = mlx_new_image(fractol.mlx, 800, 800); 
		fractol.addr = mlx_get_data_addr(fractol.img,&fractol.bits_per_pixel,&fractol.line_length,&fractol.endian); 
		mlx_mouse_hook(fractol.mlx_win, mouse_hook, &fractol); 
		mlx_key_hook (fractol.mlx_win, &key_hook, &fractol);
		draw_frct_m(&fractol);
		mlx_put_image_to_window((fractol).mlx,(fractol).mlx_win, (fractol).img, 0, 0); 
		mlx_loop(fractol.mlx); 
	}
	return 0;
}
