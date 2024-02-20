/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:58:12 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/02 23:08:45 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# define WIDTH 900
# define HEIGHT 900

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	double	i;
	double	j;
	double	tmp;
	double	iters;
}	t_vars;

typedef struct s_cmpx_nbr
{
	double	real;
	double	imag;
}	t_cmpx_nbr;

typedef struct s_my_struct
{
	void				*mlx_conn;
	void				*mlx_win;
	char				*title;
	double				factor;
	double				max_iters;
	t_cmpx_nbr			c;
	t_data				img;
}	t_my_struct;

void	conn_init(t_my_struct *my_str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	my_struct_init(t_my_struct *my_str, char **av);
void	fractol_rendering(t_my_struct *my_str);
double	mv(double value, double nmin, double nmax, double omax);
int		ft_color(int iterations, int max_iterations);
void	vars_init(t_vars *vars);
double	ft_atod(char *s);
int		ft_keys_press(int keycode, t_my_struct *param);
int		ft_close(t_my_struct *param);
int		ft_parse(char *s, int i, int sign, int dot);
int		ft_zoom(int button, int x, int y, t_my_struct *param);
void	ft_print_name(void);

#endif