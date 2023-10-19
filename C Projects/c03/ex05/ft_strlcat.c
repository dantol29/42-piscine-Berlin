/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:03:40 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/05 11:48:50 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	srclen;

	len = 0;
	while (dest[len] && len < size)
		len++;
	if (size - len == 0 || len >= size)
		return (len + ft_strlen(src));
	i = len;
	while (src[i - len] && i < size - 1)
	{
		dest[i] = src[i - len];
		i++;
	}
	dest[len] = '\0';
	srclen = 0;
	while (src[srclen])
		srclen++;
	return (len + srclen);
}
/*
#include <unistd.h>
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
	char dest[9] = "he";
	char src[] = "y";
	ft_strlcat(dest, src, 3);

	ft_putstr(dest);
}*/
