/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:28:53 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/09 22:55:26 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <X11/keysym.h>

void	change_scale_parametrs(t_scale *old, t_scale new)
{
	old->max_imag += new.max_imag;
	old->min_imag += new.min_imag;
	old->max_real += new.max_real;
	old->min_real += new.min_real;
}

void	zoom(int btn, int x, int y, t_my_display *my_display)
{
	double		x_ratio;
	double		y_ratio;
	t_complex	delta;
	t_scale		new_scale;
	double		scale_factor;

	x_ratio = (double)x / (double)my_display->img_data.size.max_px;
	y_ratio = (double)y / (double)my_display->img_data.size.max_py;
	delta.real = my_display->img_data.fractol.scale.max_real
		- my_display->img_data.fractol.scale.min_real;
	delta.imag = my_display->img_data.fractol.scale.max_imag
		- my_display->img_data.fractol.scale.min_imag;
	scale_factor = 0.3;
	if (btn == SCROLL_DOWN || btn == XK_minus)
		scale_factor = (1 / scale_factor);
	delta.real = (scale_factor * delta.real) - delta.real;
	delta.imag = (scale_factor * delta.imag) - delta.imag;
	new_scale = create_scale((delta.imag * (1 - y_ratio)),
			-(delta.imag * y_ratio),
			(delta.real * (1 - x_ratio)),
			-(delta.real * x_ratio));
	change_scale_parametrs(&(my_display->img_data.fractol.scale), new_scale);
	execute_fractal_rendering(&(my_display->img_data), 0);
	mlx_put_image_to_window(my_display->mlx, my_display->win,
		my_display->img_data.img_ptr, 0, 0);
}

void	execute_fractal_rendering(t_img_data *img_data, int change_color)
{
	if (img_data->fractol.name == 'M')
		render_mandelbrot(img_data);
	else if (img_data->fractol.name == 'J')
		render_julia(img_data);
	else if (img_data->fractol.name == 'N')
		render_newton(img_data, change_color);
}
