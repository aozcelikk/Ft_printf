/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:44:26 by aozcelik          #+#    #+#             */
/*   Updated: 2022/02/17 10:44:30 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *klm, ...);
int	ortak_taban(long unsigned int i, char *taban, unsigned int boyut);
int	dnstr_c(int lst);
int	dnstr_s(char *lst);
int	dnstr_p(long unsigned int lst, char *taban);
int	dnstr_i(int lst);
int	dnstr_d(int lst);
int	dnstr_u(unsigned int lst);
int	dnstr_x(unsigned int lst, char *taban);
int	dnstr_xx(unsigned int lst, char *taban);

#endif
