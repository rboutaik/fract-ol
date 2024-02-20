/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:16:58 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/03 21:37:33 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_exchange(t_my_struct *param)
{
	int	tmp;

	tmp = (int)(param->l1 + param->l3) % 11;
	param->l1 = (int)(param->l2 + param->l1) % 11;
	param->l2 = (int)(param->l3 + param->l2) % 11;
	param->l3 = tmp;
}

int	ft_keys_press(int keycode, t_my_struct *param)
{
	if (keycode == 49)
		ft_exchange(param);
	else if (keycode == 27)
	{
		if (param->max_iters > 20)
			param->max_iters -= 10;
	}
	else if (keycode == 24)
		param->max_iters += 10;
	else if (keycode == 53)
		ft_close(param);
	else if (keycode == 123)
		param->i_ofs -= 0.1 * param->factor;
	else if (keycode == 124)
		param->i_ofs += 0.1 * param->factor;
	else if (keycode == 125)
		param->j_ofs -= 0.1 * param->factor;
	else if (keycode == 126)
		param->j_ofs += 0.1 * param->factor;
	else
		return (0);
	fractol_rendering(param);
	return (0);
}

int	ft_zoom(int button, int x, int y, t_my_struct *param)
{
	double	s_x;
	double	s_y;

	s_x = mv(x, param->mi, param->mxi, WIDTH);
	s_y = mv(y, param->mj, param->mxj, HEIGHT);
	if (button == 5)
	{
		param->factor *= 1.1;
		param->mi = s_x + (param->mi - s_x) * 1.1;
		param->mxi = s_x + (param->mxi - s_x) * 1.1;
		param->mj = s_y + (param->mj - s_y) * 1.1;
		param->mxj = s_y + (param->mxj - s_y) * 1.1;
	}
	else if (button == 4)
	{
		param->factor *= 0.9;
		param->mi = s_x + (param->mi - s_x) * 0.9;
		param->mxi = s_x + (param->mxi - s_x) * 0.9;
		param->mj = s_y + (param->mj - s_y) * 0.9;
		param->mxj = s_y + (param->mxj - s_y) * 0.9;
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
