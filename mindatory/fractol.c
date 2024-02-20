/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:31:56 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/02 23:08:50 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	vars_init(t_vars *vars)
{
	vars->i = -1;
	vars->j = -1;
	vars->iters = 0;
	vars->tmp = 0;
}

int	ft_parse(char *s, int i, int sign, int dot)
{
	int	others;
	int	num;

	i = 0;
	num = 0;
	dot = 0;
	sign = 0;
	others = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
			sign++;
		else if (s[i] == '.')
			dot++;
		else if (s[i] < 48 || s[i] > 57)
			others++;
		else
			num++;
		i++;
	}
	if (s[0] == '.' || s[i - 1] == '.')
		dot = 2;
	if (dot > 1 || sign > 1 || others > 0 || num < 1)
		return (0);
	return (1);
}

int	ft_check(char **av, int ac)
{
	int	i;
	int	sign;
	int	dot;

	i = 0;
	sign = 0;
	dot = 0;
	if (ac != 4)
		return (1);
	if (ft_strncmp(av[1], "julia", 6))
		return (1);
	if (!ft_parse(av[2], i, sign, dot) || !ft_parse(av[3], i, sign, dot))
		return (0);
	return (1);
}

void	ft_errors(void)
{
	ft_putstr_fd("\n\x1b[31mWrong args:\n\x1b[0m", 1);
	ft_putstr_fd("\x1b[33m\t./fractol mandelbrot\n\x1b[0m", 1);
	ft_putstr_fd("\x1b[34m\t./fractol julia real imaginary\n\x1b[0m", 1);
	ft_putstr_fd("\x1b[32m", 1);
	ft_putstr_fd("\n\n\t***************************\n", 1);
	ft_putstr_fd("\t*          Enjoy 😊       *\n", 1);
	ft_putstr_fd("\t***************************\n", 1);
	ft_putstr_fd("\x1b[0m", 1);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_my_struct	my_str;

	ft_print_name();
	if ((!(ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
			&& !(ac == 4 && !ft_strncmp(av[1], "julia", 6)))
		|| !ft_check(av, ac))
		ft_errors();
	my_struct_init(&my_str, av);
	conn_init(&my_str);
	fractol_rendering(&my_str);
	mlx_key_hook(my_str.mlx_win, ft_keys_press, &my_str);
	mlx_mouse_hook(my_str.mlx_win, ft_zoom, &my_str);
	mlx_hook(my_str.mlx_win, 17, 0, ft_close, &my_str);
	mlx_loop(my_str.mlx_conn);
	return (0);
}
