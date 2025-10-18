/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:38:22 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/19 00:44:11 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// doesn't actually draws the sets, it's just putting collors in each pixel
// making sure that everything is filled, by looping through columns(y),
// incrementing row(x), and looping trough (y) again

#include "../fractol.h"

int	draw_fractol(t_fractol *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < fractol->width)
	{
		while (fractol->y < fractol->height)
		{
			if (fractol->type == 1)
				calculate_mandelbrot(fractol);
			else if (fractol->type == 2)
				calculate_julia(fractol);
			else if (fractol->type == 3)
				calculate_ship(fractol);
			else
				help(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
	return (0);
}

void	switch_fractol(t_fractol *fractol)
{
	if (fractol->type == 3)
		fractol->type = 1;
	else
		fractol->type += 1;
}

void	animation(t_fractol *fractol)
{
	fractol->jc.real = 0.7788 * cos(fractol->julia_angle);
	fractol->jc.img = 0.7788 * sin(fractol->julia_angle);
	fractol->julia_angle += fractol->julia_speed;
	fractol->needs_redraw = true;
}

void	change_color(t_fractol *fractol)
{
	if (fractol->image)
		mlx_delete_image(fractol->mlx, fractol->image);
	fractol->color_shift += 1;
	if (fractol->color_shift > 8)
		fractol->color_shift = 1;
	change_color_in_struct(fractol);
	fractol->image = mlx_new_image(fractol->mlx, fractol->width,
			fractol->height);
	if (!fractol->image)
		ft_error(fractol);
	if (mlx_image_to_window(fractol->mlx, fractol->image, 0, 0) < 0)
		ft_error(fractol);
}
