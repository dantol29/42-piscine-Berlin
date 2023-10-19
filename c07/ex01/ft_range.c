/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:17:39 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/09 11:39:21 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*new;
	int	i;

	if (min >= max)
		return ((void *)0);
	len = max - min;
	new = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (min < max)
	{
		new[i] = min;
		min++;
		i++;
	}
	return (new);
}
/*
#include <stdio.h>
int	main()
{
	int	*new;
	int	i;

	new = ft_range(19,9);
	i = 0;
	while (i < 9 + 2)
	{
		printf("%d, ", new[i]);
		i++;
	}
}*/
