/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcollection2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:50:19 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/26 12:36:43 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	static int	bytes;

	bytes = 0;
	if (n < 0 && n / 10 == 0)
		bytes += ft_putchar('-');
	if (n / 10 != 0)
		ft_putnbr(n / 10);
	if (n % 10 < 0)
		bytes += ft_putchar(-(n % 10) + '0');
	else
		bytes += ft_putchar((n % 10) + '0');
	return (bytes);
}

int	ft_putnbr_unsign(unsigned int n)
{
	static int	bytes;
	int			i;
	char		deci[25];
	long		nb;

	i = 0;
	bytes = 0;
	nb = n;
	if (nb == 0)
		bytes += ft_putchar('0');
	while (nb > 0)
	{
		deci[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
		bytes += ft_putchar(deci[i--]);
	return (bytes);
}

int	ft_hexa(unsigned long long int nb)
{
	int		bytes;
	char	hexa[100];
	char	*base;
	int		i;

	i = 0;
	if (nb == 0)
		return (i += ft_putchar('0'));
	base = "0123456789abcdef";
	while (nb != 0)
	{
		bytes = nb % 16;
		hexa[i] = base[bytes];
		i++;
		nb = nb / 16;
	}
	bytes = 0;
	while (i-- > 0)
		bytes += ft_putchar(hexa[i]);
	return (bytes);
}

int	ft_hexa_up(unsigned long long int nb)
{
	int		bytes;
	char	hexa[100];
	char	*base;
	int		i;

	i = 0;
	if (nb == 0)
		return (i += ft_putchar('0'));
	base = "0123456789ABCDEF";
	while (nb != 0)
	{
		bytes = nb % 16;
		hexa[i] = base[bytes];
		i++;
		nb = nb / 16;
	}
	bytes = 0;
	while (i-- > 0)
		bytes += ft_putchar(hexa[i]);
	return (bytes);
}
