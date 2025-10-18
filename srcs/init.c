/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:35:59 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/19 00:36:13 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Initialises the fractal structure to the default values
// initialises the mlx42 with mlx_init

#include "../fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->width = 800;
	fractol->height = 800;
	fractol->r = 10;
	fractol->g = 180;
	fractol->b = 190;
	fractol->a = 255;
	fractol->max_iterations = 300;
	fractol->animation = -1;
	fractol->julia_angle = 0.0;
	fractol->julia_speed = 0.02;
	fractol->color_shift = 0;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init(fractol->width, fractol->height, "Fract-ol", true);
	if (!fractol->mlx)
		ft_error(fractol);
	fractol->image = mlx_new_image(fractol->mlx, fractol->width,
			fractol->height);
	if (!fractol->image)
		ft_error(fractol);
	if (mlx_image_to_window(fractol->mlx, fractol->image, 0, 0) < 0)
		ft_error(fractol);
}
