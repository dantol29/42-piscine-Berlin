/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:40:56 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/09 15:27:56 by dtolmaco         ###   ########.fr       */
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

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (*range == NULL)
		return (0);
	return (max - min);
}
/*	
#include <stdio.h>
int	main()
{
	int	*range;
	printf("%d", ft_ultimate_range(&range, -2, -2));
}*/
