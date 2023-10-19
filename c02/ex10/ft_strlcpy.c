/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:37:57 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/05 10:44:41 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
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
#include <stdio.h>
int	main(void)
{
	char dest[20]; // Destination buffer with ample space

    // Test case 1: Copy "hello" (5 characters) into dest (size=5)
    // Expected behavior: "hello" is fully copied, dest is null-terminated
    unsigned int len1 = ft_strlcpy(dest, "hello", 5);
    printf("Test case 1: Copied %d characters, dest='%s'\n", len1, dest);

    // Test case 2: Copy "terra" (5 characters) into dest (size=3)
    // Expected behavior: Only "ter" is copied, dest is null-terminated
    unsigned int len2 = ft_strlcpy(dest, "terra", 3);
    printf("Test case 2: Copied %d characters, dest='%s'\n", len2, dest);

    // Test case 3: Copy "hello" (5 characters) into dest (size=10)
    // Exddpected behavior: "hello" is fully copied, dest is null-terminated
    unsigned int len3 = ft_strlcpy(dest, "hello", 10);
    printf("Test case 3: Copied %d characters, dest='%s'\n", len3, dest);

    return 0;
}*/
