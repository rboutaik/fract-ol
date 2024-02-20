/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:16:58 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/02 23:08:54 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keys_press(int keycode, t_my_struct *param)
{
	if (keycode == 53)
		ft_close(param);
	return (0);
}

int	ft_zoom(int button, int x, int y, t_my_struct *param)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		param->factor *= 1.1;
	}
	else if (button == 5)
	{
		param->factor *= 0.90;
	}
	else
		return (0);
	fractol_rendering(param);
	return (0);
}

int	ft_close(t_my_struct *param)
{
	mlx_destroy_image(param->mlx_conn, param->img.img);
	mlx_destroy_window(param->mlx_conn, param->mlx_win);
	exit(0);
}

void	conn_init(t_my_struct *my_str)
{
	my_str->mlx_conn = mlx_init();
	if (my_str->mlx_conn == NULL)
		exit (1);
	my_str->mlx_win = mlx_new_window(my_str->mlx_conn,
			WIDTH, HEIGHT, my_str->title);
	if (my_str->mlx_win == NULL)
		exit(1);
	my_str->img.img = mlx_new_image(my_str->mlx_conn, WIDTH, HEIGHT);
	if (my_str->img.img == NULL)
	{
		mlx_destroy_window(my_str->mlx_conn, my_str->mlx_win);
		exit(1);
	}
	my_str->img.addr = mlx_get_data_addr(my_str->img.img,
			&my_str->img.bits_per_pixel,
			&my_str->img.line_length, &my_str->img.endian);
	if (my_str->img.addr == NULL)
		ft_close(my_str);
}
