/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:22:26 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/03 11:40:51 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	temp;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	temp = nb;
	i = 1;
	while (power > i)
	{
		nb = nb * temp;
		i++;
	}
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_iterative_power(5, 0));
}*/
