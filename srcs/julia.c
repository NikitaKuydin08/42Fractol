/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:18:16 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/18 23:56:52 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	calculation_colour(t_fractol *fractol, int i);

void	calculate_julia(t_fractol *fractol)
{
	int		n;
	double	tmp_real;

	n = 0;
	fractol->z.real = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->z.img = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (++n < fractol->max_iterations)
	{
		tmp_real = (fractol->z.real * fractol->z.real)
			- (fractol->z.img * fractol->z.img);
		fractol->z.img = 2.0 * fractol->z.real * fractol->z.img;
		fractol->z.real = tmp_real + fractol->jc.real;
		fractol->z.img += fractol->jc.img;
		if ((fractol->z.real * fractol->z.real
				+ fractol->z.img * fractol->z.img) > 4)
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

void	check_jc(t_fractol	*fractol)
{
	if (fractol->param1 && fractol->param2)
	{
		fractol->jc.real = fractol->param1;
		fractol->jc.img = fractol->param2;
	}
	else
	{
		fractol->jc.real = -0.7;
		fractol->jc.real = 0.27015;
	}
}
