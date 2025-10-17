/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:35:59 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/17 23:14:55 by nkuydin          ###   ########.fr       */
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
	fractol->r = 242;
	fractol->g = 204;
	fractol->b = 15;
	fractol->a = 255;
	if (strncmp(fractol->name, "mandelbrot", 10) == 0)
	{
		fractol->offset_x = -1.90;
		fractol->offset_y = -1.40;
		fractol->zoom = 300;
	}
	else if (strncmp(fractol->name, "julia", 5) == 0)
	{
		fractol->offset_x = -1.60;
		fractol->offset_y = -1.60;
		fractol->zoom = 250;
	}
	fractol->max_iterations = 150;
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
