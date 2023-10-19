/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:08:12 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/09/27 19:13:39 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 97 && str[i] <= 122))
		{
			if (!(str[i] >= 65 && str[i] <= 90))
				return (0);
		}
		i++;
	}
	return (1);
}