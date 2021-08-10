/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcollection2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:50:19 by tshimoda          #+#    #+#             */
/*   Updated: 2021/08/01 20:35:38 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	static int	len;

	len = 0;
	if (n < 0 && n / 10 == 0)
		len += ft_putchar('-');
	if (n / 10 != 0)
		ft_putnbr(n / 10);
	if (n % 10 < 0)
		len += ft_putchar(-(n % 10) + '0');
	else
		len += ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_putnbr_unsign(unsigned int n)
{
	static int	len;
	int			i;
	char		deci[25];
	long		nb;

	i = 0;
	len = 0;
	nb = n;
	if (nb == 0)
		len += ft_putchar('0');
	while (nb > 0)
	{
		deci[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
		len += ft_putchar(deci[i--]);
	return (len);
}

int	ft_hexa(unsigned long long int nb)
{
	int		temp;
	char	hexa[100];
	char	*base;
	int		i;

	i = 0;
	if (nb == 0)
		return (i += ft_putchar('0'));
	base = "0123456789abcdef";
	while (nb != 0)
	{
		temp = nb % 16;
		hexa[i] = base[temp];
		i++;
		nb = nb / 16;
	}
	temp = 0;
	while (i-- > 0)
		temp += ft_putchar(hexa[i]);
	return (temp);
}

int	ft_hexa_up(unsigned long long int nb)
{
	int		temp;
	char	hexa[100];
	char	*base;
	int		i;

	i = 0;
	if (nb == 0)
		return (i += ft_putchar('0'));
	base = "0123456789ABCDEF";
	while (nb != 0)
	{
		temp = nb % 16;
		hexa[i] = base[temp];
		i++;
		nb = nb / 16;
	}
	temp = 0;
	while (i-- > 0)
		temp += ft_putchar(hexa[i]);
	return (temp);
}
