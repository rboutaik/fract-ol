/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:39:11 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/05 17:47:06 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	mv(double value, double nmin, double nmax, double omax)
{
	double	omin;

	omin = 0;
	return (((value - omin) / (omax - omin)) * (nmax - nmin) + nmin);
}

t_cmpx_nbr	ft_calcz(t_my_struct *my_str, t_cmpx_nbr z, t_vars *vars)
{
	vars->tmp = pow(z.real, 2) - pow(z.imag, 2) + my_str->c.real;
	z.imag = 2 * z.real * z.imag + my_str->c.imag;
	z.real = vars->tmp;
	vars->iters++;
	return (z);
}

void	fractol_rendering(t_my_struct *my_str)
{
	t_cmpx_nbr	z;
	t_vars		vars;

	vars_init(&vars);
	while (++vars.i < WIDTH)
	{
		vars.j = -1;
		while (++vars.j < HEIGHT)
		{
			z.real = mv(vars.i, -2, 2, WIDTH) * my_str->factor;
			z.imag = mv(vars.j, 2, -2, HEIGHT) * my_str->factor;
			if (ft_strncmp(my_str->title, "julia", 6))
				my_str->c = z;
			vars.iters = 0;
			while (pow(z.real, 2) + pow(z.imag, 2) <= 4
				&& vars.iters < my_str->max_iters)
				z = ft_calcz(my_str, z, &vars);
			my_mlx_pixel_put(&my_str->img, vars.i, vars.j,
				ft_color((int)vars.iters, (int)my_str->max_iters));
		}
	}
	mlx_put_image_to_window(my_str->mlx_conn,
		my_str->mlx_win, my_str->img.img, 0, 0);
}

void	ft_print_name(void)
{
	ft_putstr_fd("\033[0;31m\n\n", 1);
	ft_putstr_fd("███████ ██████   █████  ", 1);
	ft_putstr_fd(" ██████ ████████  ██████  ██      \n", 1);
	ft_putstr_fd("██      ██   ██ ██   ██ ██     ", 1);
	ft_putstr_fd("    ██    ██    ██ ██      \n", 1);
	ft_putstr_fd("█████   ██████  ███████ ██   ", 1);
	ft_putstr_fd("      ██    ██    ██ ██      \n", 1);
	ft_putstr_fd("██      ██   ██ ██   ██ ██", 1);
	ft_putstr_fd("         ██    ██    ██ ██      \n", 1);
	ft_putstr_fd("██      ██   ██ ██   ██  ██████ ", 1);
	ft_putstr_fd("   ██     ██████  ███████ \n\n\n", 1);
	ft_putstr_fd("\033[0m", 1);
}
