/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:34:08 by nandreev          #+#    #+#             */
/*   Updated: 2023/10/01 14:56:24 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_top(int x)
{
	int	counter;

	counter = 0;
	ft_putchar('/');
	while (x - 2 > counter)
	{
		ft_putchar('*');
		counter++;
	}
	if (x > 1)
		ft_putchar('\\');
}

void	ft_bottom(int x)
{
	int	counter;

	counter = 0;
	ft_putchar('\\');
	while (x - 2 > counter)
	{
		ft_putchar('*');
		counter++;
	}
	if (x > 1)
		ft_putchar('/');
}

void	ft_middle(int x)
{
	int	counter;

	counter = 0;
	ft_putchar('*');
	while (x - 2 > counter)
	{
		ft_putchar(' ');
		counter++;
	}
	if (x > 1)
		ft_putchar('*');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
			ft_top(x);
		else if (i + 1 == y)
			ft_bottom(x);
		else
			ft_middle(x);
		ft_putchar('\n');
		i++;
	}
}
