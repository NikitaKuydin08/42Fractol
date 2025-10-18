/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:38:10 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/19 00:49:14 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Soom in and zoom out the fractol
// Handle keyboard events:
// ESC: exit the program
// R: reset the fractol

#include "../fractol.h"

void	loop_hook(void *param)
{
	t_fractol		*fractol;

	fractol = (t_fractol *)param;
	if (fractol->needs_redraw)
	{
		draw_fractol(fractol);
		fractol->needs_redraw = 0;
	}
	if (fractol->animation == 1)
		animation(fractol);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keydata.key == 82 && keydata.action == 1)
		reset_fractol(fractol);
	if (keydata.key == 256 && keydata.action == 1)
		mlx_close_window(fractol->mlx);
	if (keydata.key == 265 && (keydata.action == 2 || keydata.action == 1))
		fractol->offset_y -= 0.0005 * fractol->zoom;
	if (keydata.key == 264 && (keydata.action == 2 || keydata.action == 1))
		fractol->offset_y += 0.0005 * fractol->zoom;
	if (keydata.key == 263 && (keydata.action == 2 || keydata.action == 1))
		fractol->offset_x -= 0.0005 * fractol->zoom;
	if (keydata.key == 262 && (keydata.action == 2 || keydata.action == 1))
		fractol->offset_x += 0.0005 * fractol->zoom;
	if (keydata.key == 67 && (keydata.action == 2 || keydata.action == 1))
		change_color(fractol);
	if (keydata.key == 66 && keydata.action == 1)
		
	if (keydata.key == 70 && keydata.action == 1)
		switch_fractol(fractol);
	if (keydata.key == 65 && keydata.action == 1)
		fractol->animation *= -1;
	fractol->needs_redraw = 1;
}

void	zoom(t_fractol *fractol, int x, int y, int zoom)
{
	if (zoom == 1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom * 1.42));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom * 1.42));
		fractol->zoom = fractol->zoom * 1.42;
	}
	else if (zoom == -1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom / 1.42));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom / 1.42));
		fractol->zoom = fractol->zoom / 1.42;
	}
	else
		return ;
	if (fractol->zoom > 500)
		fractol->max_iterations = 100;
	else if (fractol->zoom > 200)
		fractol->max_iterations = 75;
	else
		fractol->max_iterations = 42;
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	(void)xdelta;
	mlx_get_mouse_pos(fractol->mlx, &fractol->x, &fractol->y);
	if (ydelta > 0)
		zoom(fractol, fractol->x, fractol->y, 1);
	else if (ydelta < 0)
		zoom(fractol, fractol->x, fractol->y, -1);
	fractol->needs_redraw = 1;
}

void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (fractol->image)
		mlx_delete_image(fractol->mlx, fractol->image);
	fractol->image = mlx_new_image(fractol->mlx, width, height);
	if (!fractol->image)
		ft_error(fractol);
	if (mlx_image_to_window(fractol->mlx, fractol->image, 0, 0) < 0)
		ft_error(fractol);
	fractol->width = width;
	fractol->height = height;
	fractol->needs_redraw = 1;
}
