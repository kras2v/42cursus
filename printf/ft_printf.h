/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:04:10 by valeriia          #+#    #+#             */
/*   Updated: 2024/10/30 10:55:36 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h" 
# include "stdarg.h"
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_printf_c(char a);
int	ft_printf_s(char *a);
int	ft_printf_d(int num);
int	ft_printf_i(int num);
int	ft_printf_percent(void);
int	ft_printf_u(unsigned int dec);
int	ft_printf_x(unsigned long dec);
int	ft_printf_ux(unsigned long dec);
int	ft_printf_p(unsigned long dec);
int	ft_convert_to_base(unsigned long dec, char *base, int base_len);

#endif