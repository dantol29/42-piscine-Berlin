/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:33:35 by zblume            #+#    #+#             */
/*   Updated: 2023/10/18 12:44:14 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	fill_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] '\n')
		i++;
	if (str[i - 1] == str[i - 3])
		return (str[i - 1]);
}

char	obstacle_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] '\n')
		i++;
	if (str[i - 2] == str[i - 1])
		return (NULL);
	return (str[i - 2]);
}

char	empty_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] '\n')
		i++;
	if (str[i - 3] == str[i - 2])
		return (NULL);
	return (str[i - 3]);
}
