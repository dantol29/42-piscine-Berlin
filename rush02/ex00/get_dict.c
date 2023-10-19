/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmejbar <mmejbar@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:50:19 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/10/15 21:00:47 by mmejbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

void	fill_array_numbers(char **numbers, char buffer[B_SIZE], int len)
{
	int	k;
	int	i;
	int	j;

	i = 0;
	k = 0;
	while (k < len)
	{
		j = 0;
		while (buffer[i] == '\n')
			i++;
		while (buffer[i] == ' ' || buffer[i] == '\t')
			i++;
		while (buffer[i] >= '0' && buffer[i] <= '9')
		{
			numbers[k][j] = buffer[i];
			i++;
			j++;
		}
		numbers[k][j] = '\0';
		while (buffer[i] != '\n')
			i++;
		k++;
		i++;
	}
}

void	fill_array_words(char **words, char buffer[B_SIZE], int len)
{
	int	k;
	int	i;
	int	j;

	i = 0;
	k = 0;
	while (k < len)
	{
		j = 0;
		while (buffer[i] == '\n')
			i++;
		while ((buffer[i] >= '0' && buffer[i] <= '9') \
			|| buffer[i] == ':' || buffer[i] == ' ' || buffer[i] == '\t')
			i++;
		while (buffer[i] != '\n')
		{
			words[k][j] = buffer[i];
			j++;
			i++;
		}
		k++;
		i++;
	}
}

void	assign_memory_numbers(char buffer[B_SIZE], char **numbers, int len)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	i = 0;
	while (k < len)
	{
		j = 0;
		while (buffer[i] == '\n')
			i++;
		while (buffer[i] >= '0' && buffer[i] <= '9')
		{
			i++;
			j++;
		}
		while (buffer[i] != '\n')
			i++;
		numbers[k] = (char *)malloc(sizeof(char) * j);
		k++;
		i++;
	}
}

void	assign_memory_words(char buffer[B_SIZE], char **words, int len )
{
	int	i ;
	int	j;
	int	k;

	i = 0;
	k = 0;
	i = 0;
	while (k < len)
	{
		j = 0;
		while (buffer[i] == '\n')
			i++;
		while ((buffer[i] >= '0' && buffer[i] <= '9')
			|| buffer[i] == ':' || buffer[i] == ' ')
			i++;
		while (buffer[i] != '\n')
		{
			i++;
			j++;
		}
		words[k] = (char *)malloc(sizeof(char) * j);
		k++;
		i++;
	}
}

void	get_dict(char *str, char *dict_path)
{
	char	buffer[B_SIZE];
	int		len;
	int		fd;

	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error", 10);
		return ;
	}
	len = read(fd, buffer, sizeof(buffer));
	while (len > 0)
	{
		buffer[len] = '\0';
		len = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
	call_com(buffer, str);
}
