/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:49:21 by anisabel          #+#    #+#             */
/*   Updated: 2025/05/31 00:49:21 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if (buffer[0])
	{
		line = ft_join_free(line, buffer);
		if (!line)
			return (NULL);
	}
	line = read_and_append(fd, line, buffer);
	if (!line || *line == 0)
		return (free(line), NULL);
	result = extract_line(line);
	if (!result)
		return (free(line), NULL);
	update_buffer(buffer);
	free(line);
	return (result);
}

char	*read_and_append(int fd, char *line, char *buffer)
{
	int	bytes_read;

	while (ft_find_nl(line) == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		line = ft_join_free(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*extract_line(char *line)
{
	int		i;
	int		len;
	char	*new_line;

	if (!line)
		return (NULL);
	len = ft_find_nl(line);
	if (len == -1)
		len = ft_strlen(line);
	else
		len += 1;
	new_line = malloc((len + 1) * sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	i = -1;
	while (++i < len)
		new_line[i] = line [i];
	new_line[len] = 0;
	return (new_line);
}

/* static char	*ft_handle_nl(char *buffer, char *line)
{
	int	index;

	if (!line)
		return (NULL);
	index = ft_find_nl(line);
	if (index >= 0)
		line[++index] = '\0';
	ft_prep_buffer(buffer);
	return (line);
}

static char	*ft_read_file(int fd, char *buffer, char *line)
{
	int	bytes_read;

	ft_prep_buffer(buffer);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_join_free(line, buffer);
		if (!line)
			return (NULL);
		if (ft_find_nl(buffer) >= 0)
			break ;
		ft_prep_buffer(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if (buffer[0] != '\0')
		line = ft_join_free(line, buffer);
	if (ft_find_nl(buffer) >= 0)
	{
		if (!line)
			return (NULL);
		return (ft_handle_nl(buffer, line));
	}
	line = ft_read_file(fd, buffer, line);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (ft_handle_nl(buffer, line));
}
 */