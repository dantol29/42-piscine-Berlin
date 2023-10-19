/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:58:58 by nandreev          #+#    #+#             */
/*   Updated: 2023/10/01 15:06:39 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_top_or_bottom(int x)
{
	int	counter;

	counter = 0;
	ft_putchar('A');
	while (x - 2 > counter)
	{
		ft_putchar('B');
		counter++;
	}
	if (x > 1)
		ft_putchar('C');
}

void	ft_middle(int x)
{
	int	counter;

	counter = 0;
	ft_putchar('B');
	while (x - 2 > counter)
	{
		ft_putchar(' ');
		counter++;
	}
	if (x > 1)
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0 || i + 1 == y)
			ft_top_or_bottom(x);
		else
			ft_middle(x);
		ft_putchar('\n');
		i++;
	}
}
