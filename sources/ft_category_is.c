/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_category_is.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:19:24 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/26 12:26:47 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	category_is_char(t_data *box)
{
	box->sum += ft_putchar((char)va_arg(box->list, int));
}

void	category_is_string(t_data *box)
{
	box->sum += ft_putstr((char *)va_arg(box->list, char *));
}

void	category_is_decint(t_data *box)
{
	box->sum += ft_putnbr(va_arg(box->list, int));
}

void	category_is_modulo(t_data *box)
{
	box->sum += (write(1, "%", 1));
}
