/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:09:05 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/03 14:25:37 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (nb < 2147483647)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (2147483647);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_find_next_prime(90));
}*/
