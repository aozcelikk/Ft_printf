/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:49:14 by aozcelik          #+#    #+#             */
/*   Updated: 2022/02/17 10:49:16 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*chr;

	i = -1;
	chr = (char *)s;
	while (chr[++i])
		if (chr[i] == (char)c)
			return (&chr[i]);
	if (!c)
		return (&chr[i]);
	return (NULL);
}

int	ortak_taban(long unsigned int i, char *taban, unsigned int boyut)
{
	int	symk;

	symk = 1;
	if (i % boyut != i)
		symk += ortak_taban(i / boyut, taban, boyut);
	write(1, &taban[i % boyut], 1);
	return (symk);
}

int	dnstr(const char c, va_list *lst)
{
	if (c == 'c')
		return (dnstr_c(va_arg(*lst, int)));
	else if (c == 's')
		return (dnstr_s(va_arg(*lst, char *)));
	else if (c == 'p')
		return (dnstr_p(va_arg(*lst, long unsigned int), "0123456789abcdef"));
	else if (c == 'd')
		return (dnstr_d(va_arg(*lst, int)));
	else if (c == 'i')
		return (dnstr_i(va_arg(*lst, int)));
	else if (c == 'u')
		return (dnstr_u(va_arg(*lst, unsigned int)));
	else if (c == 'x')
		return (dnstr_x(va_arg(*lst, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (dnstr_xx(va_arg(*lst, unsigned int), "0123456789ABCDEF"));
	write(1, "%", 1);
	return (1);
}

int	ara(char klm, va_list *lst)
{
	int	symk;

	symk = 0;
	if (ft_strchr("cspdiuxX%", klm))
		symk += dnstr(klm, lst);
	else
		symk += dnstr_c((int)klm);
	return (symk);
}

int	ft_printf(const char *klm, ...)
{
	va_list	*lst;
	int		i;
	int		symk;

	if (!klm)
		return (0);
	i = -1;
	symk = 0;
	lst = (va_list *)malloc(sizeof(va_list));
	va_start(*lst, klm);
	while (klm[++i])
	{
		if (klm[i] == '%' && klm[i + 1])
			symk += ara(klm[++i], lst);
		else
		{
			write(1, &klm[i], 1);
			symk ++;
		}
	}
	va_end(*lst);
	free(lst);
	return (symk);
}
