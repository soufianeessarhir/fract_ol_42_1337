/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:01:30 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/08 04:53:28 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
typedef struct s_list
{
	void *mlx; 
	void *mlx_win;
	double           zoom_factor;
	double			x;
	double			y;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	double off_x;
	double off_y;
	int height;
	int width;
	double r_max;
	double r_min;
	double i_max;
	double i_min;
	
}f_list;


int main(int ac , char **av);
#endif