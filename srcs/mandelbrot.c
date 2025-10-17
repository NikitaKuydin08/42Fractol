/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:38:27 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/17 23:54:03 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Calculates the Mandelbrot fractol for one pixel

#include "../fractol.h"

static void	calculation_colour(t_fractol *fractol, int i);

void	calculate_mandelbrot(t_fractol *fractol)
{
	int		n;
	double	temp_real;

	n = 0;
	fractol->z_real = 0.0;
	fractol->z_img = 0.0;
	fractol->c_real = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->c_img = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (++n < fractol->max_iterations)
	{
		temp_real = (fractol->z_real * fractol->z_real)
			- (fractol->z_img * fractol->z_img);
		fractol->z_img = 2.0 * fractol->z_real * fractol->z_img;
		fractol->z_real = temp_real + fractol->c_real;
		fractol->z_img += fractol->c_img;
		if ((fractol->z_real * fractol->z_real
				+ fractol->z_img * fractol->z_img) > 4)
			break ;
	}
	if (n == fractol->max_iterations)
		mlx_put_pixel(fractol->image, fractol->x, fractol->y, 0x000000FF);
	else
		calculation_colour(fractol, n);
}

static void	calculation_colour(t_fractol *fractol, int i)
{
	double		t;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	t = (double)i / (double)fractol->max_iterations;
	t = pow(t, 0.6);
	fractol->brightness = 0.1 + 1.2 * t;
	r = (uint8_t)(fractol->r * fractol->brightness);
	g = (uint8_t)(fractol->g * fractol->brightness);
	b = (uint8_t)(fractol->b * fractol->brightness);
	a = fractol->a;
	fractol->color = (r << 24) | (g << 16) | (b << 8)
		| a;
	mlx_put_pixel(fractol->image, fractol->x, fractol->y, fractol->color);
}

void	which_colour(t_fractol *fractol, char chr)
{
	if (chr == 'G')
	{
		fractol->r = 242;
		fractol->g = 204;
		fractol->b = 15;
		fractol->a = 255;
	}
	else if (chr == 'B')
	{
		fractol->r = 10;
		fractol->g = 180;
		fractol->b = 190;
		fractol->a = 255;
	}
}
