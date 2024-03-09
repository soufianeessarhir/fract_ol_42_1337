/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 06:13:34 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/09 09:09:02 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double ft_atod(const char *str)
{
    long long int result;
    double  decimal_place;
   	double         sign;

    result = 0.0;
    sign = 1.0;
    decimal_place = 1.0;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str && ((*str >= '0' && *str <= '9') || *str == '.'))
	{
        if (*str == '.')
            decimal_place = 1;
		else
		{
        	result = result * 10 + (*str - '0');
        	if (decimal_place)
                decimal_place *= 10;
        }
       	str++;
    }
    return (sign * (double)result / (double)decimal_place);
}
