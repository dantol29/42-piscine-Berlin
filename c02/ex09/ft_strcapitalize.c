/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:12:19 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/04 15:24:31 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_check(char *str, int i)
{
	if (!(str[i - 1] >= 48 && str[i - 1] <= 57))
		if (!(str[i - 1] >= 65 && str[i - 1] <= 90))
			if (!(str[i - 1] >= 97 && str[i - 1] <= 122))
				str[i] = str[i] - 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] >= 65 && str[i] <= 90)
		{
			if (str[i - 1] >= 97 && str[i] <= 122)
				str[i] = str[i] + 32;
			else if (str[i - 1] >= 48 && str[i - 1] <= 57)
				str[i] = str[i] + 32;
			else if (str[i] >= 65 && str[i] <= 90)
				str[i] = str[i] + 32;
		}
		if (str[i] >= 97 && str[i] <= 122)
		{
			ft_check(str, i);
		}
		i++;
	}
	return (str);
}
/*
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

int	main(void)
{
	ft_putstr(ft_strcapitalize(str));
}*/
