/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:18:59 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/19 00:28:15 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	color1(t_fractol	*fractol)
{
	if (fractol->color_shift == 1)
	{
		fractol->r = 255;
		fractol->g = 0;
		fractol->b = 0;
		fractol->a = 255;
	}
	else
	{
		fractol->r = 0;
		fractol->g = 255;
		fractol->b = 0;
		fractol->a = 255;
	}
}

void	color2(t_fractol	*fractol)
{
	if (fractol->color_shift == 3)
	{
		fractol->r = 0;
		fractol->g = 0;
		fractol->b = 255;
		fractol->a = 255;
	}
	else
	{
		fractol->r = 242;
		fractol->g = 204;
		fractol->b = 15;
		fractol->a = 255;
	}
}

void	color3(t_fractol	*fractol)
{
	if (fractol->color_shift == 5)
	{
		fractol->r = 0;
		fractol->g = 255;
		fractol->b = 255;
		fractol->a = 255;
	}
	else
	{
		fractol->r = 255;
		fractol->g = 0;
		fractol->b = 255;
		fractol->a = 255;
	}
}

void	color4(t_fractol	*fractol)
{
	if (fractol->color_shift == 7)
	{
		fractol->r = 192;
		fractol->g = 192;
		fractol->b = 192;
		fractol->a = 255;
	}
	else
	{
		fractol->r = 255;
		fractol->g = 165;
		fractol->b = 0;
		fractol->a = 255;
	}
}

void	change_color_in_struct(t_fractol	*fractol)
{
	if (fractol->color_shift == 1 || fractol->color_shift == 2)
		color1(fractol);
	else if (fractol->color_shift == 3 || fractol->color_shift == 4)
		color2(fractol);
	else if (fractol->color_shift == 5 || fractol->color_shift == 6)
		color3(fractol);
	else if (fractol->color_shift == 7 || fractol->color_shift == 8)
		color4(fractol);
	else
		fractol->color_shift = 0;
}
