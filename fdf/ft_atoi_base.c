/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:16:45 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/10 19:18:38 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

char	*ft_to_uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - (char)32;
		i++;
	}
	return (str);
}

int		ft_atoi_base(char *str, int str_base)
{
	int	i;
	int	minus;
	int	nb;

	nb = 0;
	minus = 0;
	i = 0;
	str = ft_to_uppercase(str);
	while (str[i] < 33)
		++i;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] - 'A' >= 0)
			nb = nb * str_base + (str[i] - 'A' + 10);
		else
			nb = nb * str_base + (str[i] - '0');
		i++;
	}
	if (minus < 0)
		nb = -nb;
	return (nb);
}
