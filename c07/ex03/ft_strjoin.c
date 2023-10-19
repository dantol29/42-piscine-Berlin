/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:00:03 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/09 13:18:13 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char **strs)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			len++;
		}
		i++;
	}
	return (len);
}

int	calculate_len(char *sep, char **strs, int size)
{
	int	len_sep;
	int	str_len;
	int	final_len;

	len_sep = 0;
	while (sep[len_sep])
		len_sep++;
	str_len = ft_strlen(strs);
	final_len = str_len + (len_sep * (size - 1));
	return (final_len);
}

int	add_sep(char *new, char *sep, int str_len)
{
	int	len_sep;

	len_sep = 0;
	while (sep[len_sep])
	{
		new[str_len] = sep[len_sep];
		str_len++;
		len_sep++;
	}
	return (str_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new;
	int		j;
	int		str_len;
	int		final_len;

	final_len = calculate_len(sep, strs, size);
	new = (char *)malloc(sizeof(char) * (final_len + 1));
	str_len = 0;
	final_len = 0;
	while (final_len < size)
	{
		j = 0;
		while (strs[final_len][j])
		{
			new[str_len] = strs[final_len][j];
			j++;
			str_len++;
		}
		if (final_len + 1 != size)
			str_len = add_sep(new, sep, str_len);
		final_len++;
	}
	new[str_len] = '\0';
	return (new);
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
int	main(int argc, char **argv)
{
	ft_putstr(ft_strjoin(argc - 1, argv + 1, "..."));
}*/
