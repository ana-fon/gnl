/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:43:45 by anisabel          #+#    #+#             */
/*   Updated: 2025/05/31 00:43:45 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_nl(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_join_free(char *line, char *buffer)
{
	char	*new_line;
	int		i;
	int		j;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = 0;
	}
	new_line = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = -1;
	j = 0;
	while (line[++i])
		new_line[i] = line [i];
	while (buffer[j])
		new_line[i++] = buffer[j++];
	new_line[i] = 0;
	return (free(line), new_line);
}

void	update_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = ft_find_nl(buffer);
	if (j == -1)
	{
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
		return ;
	}
	j++;
	while (j < BUFFER_SIZE && buffer[j])
		buffer[i++] = buffer [j++];
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
}

/* void	ft_prep_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = ft_find_nl(buffer) + 1;
	if (j < 0)
	{
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
		return ;
	}
	j++;
	while (buffer[i + j])
	{
		buffer[i] = buffer [j];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer [i++] = 0;
} */
