/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_complex_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:07:09 by valeriia          #+#    #+#             */
/*   Updated: 2025/01/09 18:49:42 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

//a^3 + 3a^2b + 3ab^2 + b^3 = (x^3 - 3xy^2) + (3x^2yi - yi^3)
t_complex	c_cube(t_complex z)
{
	t_complex	cubed_z;

	cubed_z.real = pow(z.real, 3) - 3.0 * z.real * pow(z.imag, 2);
	cubed_z.imag = 3.0 * pow(z.real, 2) * z.imag - pow(z.imag, 3);
	return (cubed_z);
}

//a^2 + 2ab + b^2 = x^2 - y^2 + 2xyi
t_complex	c_square(t_complex z)
{
	t_complex	squred_z;

	squred_z.real = pow(z.real, 2) - pow(z.imag, 2);
	squred_z.imag = 2.0 * z.imag * z.real;
	return (squred_z);
}

//(a + bi) / (c + di) = ((a + bi)(c - di)) / ((c + di)(c - di)) =
// ((ac + bd) / (c^2 + d^2)) * ((bc - ad)i/(c^2 + d^2))
t_complex	division(t_complex dividend, t_complex divisor)
{
	t_complex	quotient;

	quotient.real = (dividend.real * divisor.real
			+ dividend.imag * divisor.imag)
		/ (pow(divisor.real, 2) + pow(divisor.imag, 2));
	quotient.imag = (dividend.imag * divisor.real
			- dividend.real * divisor.imag)
		/ (pow(divisor.real, 2) + pow(divisor.imag, 2));
	return (quotient);
}

//(a + bi) - (c + di) = a - c + bi - di;
t_complex	subtraction(t_complex minuend, t_complex subtrahend)
{
	t_complex	difference;

	difference.real = minuend.real - subtrahend.real;
	difference.imag = minuend.imag - subtrahend.imag;
	return (difference);
}
