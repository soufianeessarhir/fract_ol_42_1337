/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:00:48 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/10 10:11:18 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


int check_squaring(double a,double b,t_list *fractol) 
{ 
	double tmp; 
	int i;
	
	i = 0;
	while ((a * a + b *  b < 4) && i < 80) 
	{ 
		tmp = a; 
		a = a*a - b*b;
		b = 2 * b * tmp;
		if (fractol->j == 'j')
		{
			a += fractol->r_j;
			b += fractol->i_j;
		}
		else
		{
			a += fractol->x;
			b += fractol->y;
		}
		i++; 
	} 
	fractol->color = i;
	if (i >= 80)
		return(i); 
	else
		return(0); 
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
				my_mlx_pixel_put(fractol, i, j,get_color(fractol->color,fractol) >> 16 );
			else
			{
				my_mlx_pixel_put(fractol, i, j,get_color(fractol->color,fractol) >> 2 );
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
void which_fract()
{
	write(1, "\nincorrect param you can try again using one of the folwoing\n",62);
	write(1, "\n     =>mandelbrot\n",20);
	write(1,"     =>julia\n\n",15);
	exit(0);
}
void draw_julia(int ac ,char **av,t_list *fractol)
{

			if (ac == 2)
			{
				fractol->j = 'j';
				draw_frct_m(fractol);
			}
			else if (ft_parcing(av[2]) && ft_parcing(av[3]) && ac == 4)
			{
			
				fractol->j = 'j';
				fractol->r_j = ft_atod(av[2]);
				fractol->i_j = ft_atod(av[3]);
				draw_frct_m(fractol);
			}
			else
				which_fract(); 
}
int main(int ac , char **av) 
{
	if (ac > 1 && ac < 5)
	{
		t_list fractol;
		fractol = init_data_fractol();
		if (ft_strncmp(av[1],"mandelbrot",10) == 0 && ft_strlen(av[1]) == 10)
			draw_frct_m(&fractol);
		else if((ac == 2 || ac == 4) && ft_strncmp(av[1],"julia",5) == 0 && ft_strlen(av[1]) == 5)
			draw_julia(ac, av, &fractol);
		else
			which_fract(); 
		mlx_mouse_hook(fractol.mlx_win, mouse_hook, &fractol); 
		mlx_key_hook (fractol.mlx_win, &key_hook, &fractol);
		mlx_hook(fractol.mlx_win,17,0,&destroy,&fractol);
		mlx_put_image_to_window((fractol).mlx,(fractol).mlx_win, (fractol).img, 0, 0); 
		mlx_loop(fractol.mlx); 
	}
	else
		which_fract();
	return 0;
}
