/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:14:48 by lle-briq          #+#    #+#             */
/*   Updated: 2020/11/27 17:07:57 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	utoX_size(unsigned int nb)
{
	if (nb < 16)
		return (1);
	return (1 + utoX_size(nb / 16));
}

char		*ft_utoxx(unsigned int n)
{
	char	*res;
	char	*base;
	int		i;
	int		l;

	l = utoX_size(n);
	base = "0123456789ABCDEF";
	res = malloc((l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n == 0)
		res[0] = '0';
	i = l - 1;
	while (i >= 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	return (res);
}
