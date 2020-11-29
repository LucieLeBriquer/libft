/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:14:48 by lle-briq          #+#    #+#             */
/*   Updated: 2020/10/20 11:14:57 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	itoa_size(unsigned int nb, short int sg)
{
	if (nb < 10)
		return (1 + (sg == -1));
	return (1 + itoa_size(nb / 10, sg));
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	short int		sg;
	char			*res;
	int				i;
	int				l;

	sg = 1 - 2 * (n < 0);
	nb = sg * n;
	l = itoa_size(nb, sg);
	res = malloc((l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (n == 0)
		res[0] = '0';
	if (sg == -1)
		res[0] = '-';
	i = l - 1;
	while (i >= (sg == -1))
	{
		res[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (res);
}
