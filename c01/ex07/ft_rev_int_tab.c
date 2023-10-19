/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:29:01 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/09/30 10:35:45 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	size = size - 1;
	while (i < size)
	{
		temp = tab[size];
		tab[size] = tab[i];
		tab[i] = temp;
		i++;
		size--;
	}
}
