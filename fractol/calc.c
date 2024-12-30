/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:37:06 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/27 20:37:59 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	hsv_to_rgb(double hue, double saturation, double value)
{
	int		hi;
	int		v;
	int		p;
	int		q;
	int		t;
	double	f;

	hi = (int)(hue / 60) % 6;
	value *= 255;
	f = hue / 60 - (int)(hue / 60);
	v = (int)value;
	p = (int)(value * (1 - saturation));
	q = (int)(value * (1 - f * saturation));
	t = (int)(value * (1 - (1 - f) * saturation));
	if (hi == 0)
        return create_trgb(0, v, t, p);
    else if (hi == 1)
        return create_trgb(0, q, v, p);
    else if (hi == 2)
        return create_trgb(0, p, v, t);
    else if (hi == 3)
        return create_trgb(0, p, q, v);
    else if (hi == 4)
        return create_trgb(0, t, p, v);
    else
        return create_trgb(0, v, p, q);
}

double d_abs(double abs)
{
	if (abs < 0)
		return (-abs);
	return (abs);
}

// int coloring_m(int i, t_complex z)
// {
// 	double	di;
// 	double	zn;
// 	double	hue;

// 	di = i * 2.5;
// 	zn = sqrt(z.imag + z.real);
// 	hue = di + 1.0 - log(log(d_abs(zn)));
// 	hue = 5.0 * hue;
// 	while (hue > 360)
// 		hue -= 360;
// 	while (hue < 360)
// 		hue += 360;
// 	return hsv_to_rgb(hue, 0.8, 0.9);
// }

int coloring_m(int i, int max_iterations)
{
	t_color color;
	double t = (double)i / (double)max_iterations;

	color.r = (int)(9.0 * (1 - t) * pow(t, 3) * 255);
	color.g = (int)(15.0 * pow(1 - t, 2) * pow(t, 2) * 255);
	color.b = (int)(8.5 * pow(1 - t, 3) * t * 255);
	return (create_trgb(255, color.r, color.g, color.b));
}

int	calc_m(t_fractol *mandelbrot)
{
	t_complex Z = {0.0, 0.0};
	t_complex Ztemp = {0.0, 0.0};

	int i = 0;
	while (i < mandelbrot->max_iterations)
	{
		Ztemp.imag = 2 * Ztemp.imag * Ztemp.real + mandelbrot->c.imag;
		Ztemp.real = Z.real - Z.imag + mandelbrot->c.real;
		Z.real = Ztemp.real * Ztemp.real;
		Z.imag = Ztemp.imag * Ztemp.imag;
		if ((Z.real + Z.imag) >= 4.0)
			break;
		i++;
	}
	if (i == mandelbrot->max_iterations)
		return create_trgb(0, 0, 0, 0);
	return coloring_m(i, mandelbrot->max_iterations);
	// return coloring_m(i, Z);
}

int coloring_j(int i, t_complex z)
{
	double	zn;
	double	hue;

	zn = z.imag * z.imag + z.real * z.real;
	hue = ((i - log(log(d_abs(zn)))) * 1.5);
	return hsv_to_rgb(hue, 0.5, 0.8);
}

int	calc_j(t_complex Z, t_fractol *julia)
{
	t_complex Ztemp = {0, 0};

	int i = 0;
	double z_real_2 = Z.real * Z.real;
	double z_imag_2 = Z.imag * Z.imag;
	while (i < julia->max_iterations && (z_real_2 + z_imag_2) < 16)
	{
		z_real_2 = Z.real * Z.real;
		z_imag_2 = Z.imag * Z.imag;
		Z.imag = 2 * Z.imag * Z.real + julia->c.imag;
		Ztemp.real = z_real_2 - z_imag_2;
		Z.real = Ztemp.real + julia->c.real;
		i++;
	}
	if (i == julia->max_iterations)
		return create_trgb(0, 0, 0, 0);
	// return coloring_j(i, Z);
	return coloring_m(i, julia->max_iterations);
}
