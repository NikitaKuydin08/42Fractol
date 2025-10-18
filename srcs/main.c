/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:19:22 by nkuydin           #+#    #+#             */
/*   Updated: 2025/10/19 00:06:45 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Because the user might ask for different sets, this file must also include
// the appropriate function for fiduring out which set to draw

// (draw_fractal) function iterates through the pixels of the window and
// calls the appropriate function to draw the fractal

// Such a dificult thing
// The thing right now is that I'm not handling the H cases, where 
// argv[2] and argv[3] are empty, and when I'm trying to zoom in or out, the
// program fails. 

#include "../fractol.h"

static void	get_name(t_fractol *fractol, char **argv);
static void	handle_args(t_fractol *fractol, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc < 2)
		help(NULL);
	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		return (0);
	handle_args(fractol, argc, argv);
	init_fractol(fractol);
	init_mlx(fractol);
	check_jc(fractol);
	draw_fractol(fractol);
	mlx_key_hook(fractol->mlx, key_hook, fractol);
	mlx_scroll_hook(fractol->mlx, scroll_hook, fractol);
	mlx_resize_hook(fractol->mlx, resize_hook, fractol);
	mlx_loop_hook(fractol->mlx, loop_hook, fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	free(fractol);
	return (0);
}

static int	which_sign(int *is_neg, char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *nptr)
{
	int		i;
	int		is_neg;
	double	result;
	double	divisitor;

	is_neg = 1;
	i = which_sign(&is_neg, nptr);
	result = 0;
	divisitor = 0.1;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '.')
	{
		result = result * 10.0 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '.')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result + ((nptr[i] - '0') * divisitor);
		divisitor *= 0.1;
		i++;
	}
	return (result * is_neg);
}


static void	handle_args(t_fractol *fractol, int argc, char **argv)
{
	get_name(fractol, argv);
	if (strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		if (argc != 2)
			help(fractol);
		return ;
	}
	if (argc == 2)
	{
		fractol->jc.real = -0.7;
		fractol->jc.real = 0.27015;
		return ;
	}
	if (argc != 4)
		help(fractol);
	if (!ft_strchr(argv[2], '.') || !ft_strchr(argv[3], '.'))
		help(fractol);
	fractol->param1 = ft_atof(argv[2]);
	fractol->param2 = ft_atof(argv[3]);
	if ((fractol->param1 < -2.0 && fractol->param1 > 2.0)
		|| (fractol->param2 < -2.0 && fractol->param2 > 2.0))
		help(fractol);
}

static void	get_name(t_fractol *fractol, char **argv)
{
	if (strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		fractol->offset_x = -1.90;
		fractol->offset_y = -1.40;
		fractol->zoom = 300;
		fractol->type = 1;
	}
	else if (strncmp(argv[1], "julia", 5) == 0)
	{
		fractol->offset_x = -1.60;
		fractol->offset_y = -1.60;
		fractol->zoom = 250;
		fractol->type = 2;
	}
	else if (strncmp(argv[1], "ship", 4) == 0)
	{
		fractol->offset_x = -1.90;
		fractol->offset_y = -1.60;
		fractol->zoom = 250;
		fractol->type = 3;
	}
	else
		help(fractol);
}

/* Different Types of Julia Sets, you may try out

./fractol julia -0.7 0.27015
./fractol julia 0.285 0.01
./fractol julia 0.285 0.013
./fractol julia -0.4 0.6
./fractol julia 0.355 0.355
./fractol julia -0.54 0.54
./fractol julia 0.37 -0.1 - Like it the most
./fractol julia -0.70176 -0.3842 - Like snowflake

*/