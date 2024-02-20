/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:35:51 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/03 21:35:03 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	size;

	size = 0;
	if (s == NULL || fd < 0 || fd > 1023)
		return ;
	while (s[size])
		size++;
	write(fd, s, size);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

double	ft_atod(char *s)
{
	int		i;
	int		sign;
	double	fract;
	double	n;

	i = 0;
	fract = 0.1;
	sign = 1;
	n = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign *= -1;
	}
	while (s[i] >= 48 && s[i] <= 57)
		n = n * 10 + s[i++] - 48;
	if (s[i] == '.')
		i++;
	while (s[i] >= 48 && s[i] <= 57)
	{
		n += (s[i++] - 48) * fract;
		fract *= 0.1;
	}
	return (n * sign);
}

void	my_struct_init(t_my_struct *my_str, char **av)
{
	my_str->title = av[1];
	my_str->max_iters = 100;
	my_str->factor = 1;
	my_str->i_ofs = 0;
	my_str->j_ofs = 0;
	my_str->l1 = 3;
	my_str->l2 = 5;
	my_str->l3 = 7;
	my_str->mi = -2;
	my_str->mxi = 2;
	my_str->mj = 2;
	my_str->mxj = -2;
	if (!ft_strncmp(av[1], "julia", 6))
	{
		my_str->c.real = ft_atod(av[2]);
		my_str->c.imag = ft_atod(av[3]);
	}
	else
	{
		my_str->c.real = 0;
		my_str->c.imag = 0;
	}
}

int	ft_color(int iterations, int max_iterations, t_my_struct *my_str)
{
	int	red;
	int	green;
	int	blue;

	if (iterations == max_iterations)
		return (0x000000);
	else
	{
		red = (int)(iterations * my_str->l1) % 256;
		green = (int)(iterations * my_str->l2) % 256;
		blue = (int)(iterations * my_str->l3) % 256;
		return ((red << 16) | (green << 8) | (blue));
	}
}
