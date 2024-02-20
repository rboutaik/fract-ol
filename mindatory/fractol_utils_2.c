/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:35:51 by rboutaik          #+#    #+#             */
/*   Updated: 2024/01/25 13:38:58 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	my_str->max_iters = 150;
	my_str->factor = 1;
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

int	ft_color(int iterations, int max_iterations)
{
	int	red;
	int	green;
	int	blue;

	if (iterations == max_iterations)
		return (0x000000);
	else
	{
		red = (iterations * 5) % 256;
		green = (iterations * 3) % 256;
		blue = (iterations * 11) % 256;
		return ((red << 16) | (green << 8) | (blue));
	}
}
