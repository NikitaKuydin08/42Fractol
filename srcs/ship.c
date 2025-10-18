/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:33:01 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/18 23:56:50 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	calculation_colour(t_fractol *fractol, int i);

void	calculate_ship(t_fractol *fractol)
{
	int		n;
	double	tmp_real;

	n = 0;
	fractol->z.real = 0.0;
	fractol->z.img = 0.0;
	fractol->c.real = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->c.img = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (++n < fractol->max_iterations)
	{
		tmp_real = (fractol->z.real * fractol->z.real)
			- (fractol->z.img * fractol->z.img);
		fractol->z.img = 2.0 * fabs(fractol->z.real * fractol->z.img);
		fractol->z.real = tmp_real + fractol->c.real;
		fractol->z.img += fractol->c.img;
		if ((fractol->z.real * fractol->z.real
				+ fractol->z.img * fractol->z.img) > 10)
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
