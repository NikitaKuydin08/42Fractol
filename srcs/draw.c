/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:38:22 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/16 17:37:30 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// doesn't actually draws the sets, it's just putting collors in each pixel
// making sure that everything is filled, by looping through columns(y),
// incrementing row(x), and looping trough (y) again

#include "../fractol.h"

int	draw_fractol(t_fractol *fractol)
{
	if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractol);
	else if (ft_strncmp(fractol->name, "julia", 5) == 0)
		draw_julia(fractol);
	else
		help(fractol);
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
	return (0);
}

int	draw_mandelbrot(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < fractol->width)
	{
		while (fractol->y < fractol->height)
		{
			calculate_mandelbrot(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
	return (0);
}

int	draw_julia(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < fractol->width)
	{
		while (fractol->y < fractol->height)
		{
			calculate_julia(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
	return (0);
}
