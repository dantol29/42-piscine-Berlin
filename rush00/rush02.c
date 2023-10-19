/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahorod <azahorod@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:56:56 by azahorod          #+#    #+#             */
/*   Updated: 2023/10/01 17:40:32 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_middle(int x)
{
	int	spacesize;

	spacesize = x - 2;
	ft_putchar('B');
	while (spacesize > 0)
	{
		ft_putchar(' ');
		spacesize--;
	}
	if (x > 1)
		ft_putchar('B');
}

void	ft_first(int x)
{
	int	r;

	r = 0;
	ft_putchar('A');
	while (x - 2 > r)
	{
		ft_putchar('B');
		r++;
	}
	if (x > 1)
		ft_putchar('A');
}

void	ft_last(int x)
{
	int	r;

	r = 0;
	ft_putchar('C');
	while (x - 2 > r)
	{
		ft_putchar('B');
		r++;
	}
	if (x > 1)
		ft_putchar('C');
}

void	rush(int x, int y)
{
	int	i;
	int	r;

	i = 0;
	while (i < y)
	{
		r = 0;
		if (i == 0)
			ft_first(x);
		else if (i + 1 == y)
			ft_last(x);
		else 
			ft_middle(x);
		ft_putchar('\n');
		i++;
	}
}
