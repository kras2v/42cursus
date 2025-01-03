/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:31:22 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/03 23:03:05 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <X11/keysym.h>
#include "libft/libft.h"

#define M_PI 3.14159265358979323846

enum {
	WIDTH = 1000,
	HEIGHT = 1000
};

#define ON_DESTROY 17
#define ON_MOUSEMOVE 6
#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define LEFT_CLICK 1

typedef struct s_scale
{
	double min_real;
	double max_real;
	double min_imag;
	double max_imag;
} t_scale;

typedef struct s_img_size
{
	int min_px;
	int max_px;
	int min_py;
	int max_py;
} t_img_size;

typedef struct s_complex
{
	double	real;
	double	imag;
} t_complex;

typedef struct s_fractol
{
	t_scale		scale;
	char		name;
	int			max_iterations;
	t_complex	c;
}	t_fractol;

typedef struct s_img_data
{
	void		*img_ptr;
	char		*data_addr;
	int			bites_per_pixel;
	int			size_line;
	int			endian;
	t_img_size	size;
	t_fractol	fractol;
} t_img_data;

typedef struct s_my_display
{
	void		*mlx;
	void		*win;
	t_img_data	img_data;

	int mouse_moved;
	int last_mouse_x;
	int last_mouse_y;
}	t_my_display;

typedef struct s_pixels
{
	int px;
	int py;
} t_pixels;

typedef struct s_color
{
	int r;
	int g;
	int b;
} t_color;

double ft_atof(char *argv, t_my_display *my_display);

t_complex c_cube(t_complex z);
t_complex c_square(t_complex z);
t_complex division(t_complex dividend, t_complex divisor);
t_complex	subtraction(t_complex minuend, t_complex subtrahend);

int	calc_m(t_fractol *mandelbrot);
int	calc_j(t_complex Z, t_fractol *julia);
int calc_n(t_fractol newton);

void newton(t_img_data *img_data);
void mandelbrot(t_img_data *img_data);
void julia(t_img_data *img_data);


int	create_rgb(int r, int g, int b);
int coloring_m(int i, int max_iterations);
int coloring_j(int i, t_complex z);


void	identify_event_handlers(t_my_display *my_display);

void	my_put_pixel(t_img_data *img, int x, int y, int color);
void	init_img_size(t_img_size *img_size, t_pixels min, t_pixels max);
void	create_img_data(t_my_display *my_display);
t_my_display	create_my_display(void);


void	display_info(void);
void	send_error_msg(char *msg);
void	free_and_exit(t_my_display *my_display, int exit_code, char *msg);

double	convert_pixel_to_coordinate(int pix, t_img_data *img_data, t_fractol *fractol, char direction);

#endif 