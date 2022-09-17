/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_muavin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:48:28 by aozcelik          #+#    #+#             */
/*   Updated: 2022/02/17 10:48:30 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dnstr_s(char *lst)
{
	int	i;

	i = -1;
	if (!lst)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (lst[++i])
		write(1, &lst[i], 1);
	return (i);
}

int	dnstr_p(long unsigned int lst, char *taban)
{
	int	symk;

	symk = 2;
	write(1, "0x", 2);
	symk += ortak_taban(lst, taban, 16);
	return (symk);
}

int	dnstr_d(int lst)
{
	int	symk;

	symk = 0;
	if (lst == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (lst < 0)
	{
		write(1, "-", 1);
		lst *= -1;
		symk++;
	}
	symk += ortak_taban((long unsigned int)lst, "0123456789", 10);
	return (symk);
}

int	dnstr_i(int lst)
{
	return (dnstr_d(lst));
}
