/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:14:26 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/17 23:30:44 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_error(t_fractol *fractol)
{
	if (!fractol)
		exit(EXIT_FAILURE);
	if (fractol->image)
		mlx_delete_image(fractol->mlx, fractol->image);
	if (fractol->mlx)
		mlx_close_window(fractol->mlx);
	exit(EXIT_FAILURE);
}

void	fractal_launch_options(void)
{
	ft_putendl_fd("			Available Fractols			", 1);
	ft_putendl_fd("Which fractal are you interested in?", 1);
	ft_putendl_fd("\tMandelbrot - mandelbrot", 1);
	ft_putendl_fd("\tJulia - julia", 1);
	ft_putendl_fd("Proper Usage: ./fractol <fractal>", 1);
	ft_putendl_fd("For Julia, you could specify starting values for the\n", 1);
	ft_putendl_fd("desired fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putendl_fd("Usage example: .fractol julia -0.7 0.27015", 1);
}

void	fractal_controls(void)
{
	ft_putendl_fd("			Available Controls			", 1);
	ft_putendl_fd("You are able to zoom in/out using mouse wheel", 1);
	ft_putendl_fd("Use R key to reset your current fractal", 1);
	ft_putendl_fd("The changing of the fractol colour is available.", 1);
	ft_putendl_fd("Press B to switch to blue-ish colour, press G", 1);
	ft_putendl_fd("to switch back to the golden star colour", 1);
}

void	help(t_fractol *fractol)
{
	ft_putendl_fd("\n+=================================================+", 1);
	ft_putendl_fd("|                     FRACT'OL                       |", 1);
	ft_putendl_fd("+===================================================+\n", 1);
	fractal_launch_options();
	fractal_controls();
	ft_error(fractol);
}

void	reset_fractol(t_fractol *fractol)
{
	if (fractol->image)
	{
		mlx_delete_image(fractol->mlx, fractol->image);
		fractol->image = NULL;
	}
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
	fractol->image = mlx_new_image(fractol->mlx, fractol->width,
			fractol->height);
	if (!fractol->image)
		ft_error(fractol);
	if (mlx_image_to_window(fractol->mlx, fractol->image, 0, 0) < 0)
		ft_error(fractol);
	fractol->needs_redraw = true;
}
