/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:26:33 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/09/27 13:55:34 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_commas(void)
{
	write(1, ",", 1);
	write(1, " ", 1);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = 47;
	while (a++ <= '7')
	{
		b = '0';
		while (b++ <= '8')
		{
			c = b;
			while (c++ < '9')
			{
				if (a < b && b < c)
				{
					write(1, &a, 1);
					write(1, &b, 1);
					write(1, &c, 1);
					if (!(a == '7' && b == '8' && c == '9'))
						ft_commas();
				}
			}
		}
	}
}
