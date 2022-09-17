/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:48:41 by aozcelik          #+#    #+#             */
/*   Updated: 2022/02/17 10:48:43 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dnstr_c(int lst)
{
	char	c;

	c = (char)lst;
	write(1, &c, 1);
	return (1);
}

int	dnstr_u(unsigned int lst)
{
	return (ortak_taban(lst, "0123456789", 10));
}

int	dnstr_x(unsigned int lst, char *taban)
{
	return (ortak_taban(lst, taban, 16));
}

int	dnstr_xx(unsigned int lst, char *taban)
{
	return (ortak_taban(lst, taban, 16));
}
