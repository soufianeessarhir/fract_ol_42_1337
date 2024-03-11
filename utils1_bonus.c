/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:44:30 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/11 05:34:14 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	which_fract(void)
{
	write(1, "\nincorrect param you can try again using one of the folwoing\n",
		62);
	write(1, "\n     =>mandelbrot\n", 20);
	write(1, "     =>julia\n", 14);
	write(1, "     =>tricorn\n\n", 17);
	exit(0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
