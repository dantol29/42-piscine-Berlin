/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:17:17 by zblume            #+#    #+#             */
/*   Updated: 2023/10/18 13:17:43 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#define BUFFERSIZE 5555

int	ft_maplen(char *str)
{
	int	i;
	int	count;
	int	j;
	int	line_length;

	i = 0;
	count = 0;
	j = 0;
	line_length = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (line_length != 0 && count != line_length)
				return (0);
			line_length = count;
			count = -1;
		}
		count++;
		i++;
	}
	return (line_length);
}

int	ft_linecount(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*ft_read_map(char *argv)
{
	int		m;
	ssize_t	bytes_read;
	char	*buf;
	int		len;

	if ((buf = (char *)malloc(sizeof(char) * BUFFERSIZE)) == NULL)
		return (NULL);
	m = open(argv, O_RDONLY);
	if (m == -1)
		return (NULL);
	bytes_read = read(m, buf, BUFFERSIZE);
	ft_maplen(buf);
	len = ft_linecount(buf);
	close(m);
	return (buf);
}

char	**map_memory(char *str)
{
	int		i;
	char	**map;

	i = 0;
	if ((map = (char **)malloc(sizeof(char *) * (ft_linecount(str)))) == NULL)
		return (NULL);
	while (ft_linecount(str) > i)
	{
		if ((map[i] = (char *)malloc(sizeof(char) * ft_maplen(str))) == NULL)
			return (NULL);
		i++;
	}
	return (map);
}

void	fill_map(char *str, char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			k = 0;
			j++;
		}
		map[j][k] = str[i];
		i++;
		k++;
	}
}
