/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:03:08 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/19 00:21:03 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "includes/42Libft/libft.h"
# include "includes/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

# define SIZE 800

typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*image;
	double		zoom;
	int			x;
	int			y;
	t_complex	c;
	t_complex	z;
	t_complex	jc;
	int32_t		width;
	int32_t		height;
	double		offset_x;
	double		offset_y;
	int			max_iterations;
	int			type;
	bool		needs_redraw;
	double		brightness;
	uint32_t	color;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	double		param1;
	double		param2;
	int			color_shift;
	int			animation;
	double		julia_angle;
	double		julia_speed;
}	t_fractol;

// init.c
void	init_fractol(t_fractol *fractol);
void	init_mlx(t_fractol *fractol);

// events.c
void	key_hook(mlx_key_data_t keydata, void *param); // detects ESC button
void	scroll_hook(double xdelta, double ydelta, void *param); //Zoom in & out
void	resize_hook(int32_t width, int32_t height, void *param); //Resizing
void	loop_hook(void *param);
void	reset_fractol(t_fractol *fractol);

// ship.c
void	calculate_ship(t_fractol *fractol);

// julia.c
void	calculate_julia(t_fractol *fractol);
void	check_jc(t_fractol	*fractol);

// mandelbrot.c
void	calculate_mandelbrot(t_fractol *fractol);

// draw.c
int		draw_fractol(t_fractol *param);
void	switch_fractol(t_fractol *fractol);
void	animation(t_fractol *fractol);
void	change_color(t_fractol *fractol);

// main.c
double	ft_atof(char *nptr);

// help.c
void	help(t_fractol *fractol);
void	ft_error(t_fractol *fractol);
void	reset_fractol(t_fractol *fractol);

// color.c
void	change_color_in_struct(t_fractol	*fractol);

#endif