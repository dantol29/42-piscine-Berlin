/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:27:23 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/01 12:24:24 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	k;

	len = 0;
	while (dest[len])
		len++;
	k = 0;
	while (src[k])
	{
		dest[len] = src[k];
		k++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
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
	char src[] = "FUCK";
	char dest[12] = "MOther ";
	ft_strcat(dest, src);
	ft_putstr(dest);
}*/
