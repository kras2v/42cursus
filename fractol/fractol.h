/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:31:22 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/22 14:10:25 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <X11/keysym.h>
#include "libft/libft.h"

#define WIDTH 1200
#define HEIGHT 1200
#define min_scale_X -2
#define max_scale_X 0.5
#define min_scale_Y -1.2
#define max_scale_Y 1.2

typedef struct s_img_data
{
	void		*img_ptr;
	char		*data_addr;
	int			bites_per_pixel;
	int			size_line;
	int			endian;
	int			*pallete;
} t_img_data;

typedef struct s_my_display
{
	void	*mlx;
	void	*win;
	t_img_data	img_data;
}	t_my_display;

typedef struct s_compex
{
	double real;
	double imag;
} t_compex;

typedef struct s_color
{
	int t;
	int r;
	int g;
	int b;
} t_color;

int		calc(t_compex C, int max_iterations);
void	my_put_pixel(t_img_data *img, int x, int y, int color);

int generate_color(double hue);
double scale_pixel_to_coord(int pix, int size, double min, double max);

int	calc_j(t_compex Z, t_compex C, int max_iterations);
int	calc_m(t_compex C, int max_iterations);

#endif 