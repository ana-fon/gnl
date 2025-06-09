/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:48:36 by anisabel          #+#    #+#             */
/*   Updated: 2025/05/25 11:48:36 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> 

char	*get_next_line(int fd);

int		ft_strlen(char *s);
char	*ft_join_free(char *line, char *buffer);
int		ft_find_nl(char *str);
void	update_buffer(char *buffer);
char	*extract_line(char *line);
char	*read_and_append(int fd, char *line, char *buffer);
void	free_buffer(char *buffer);

#endif /* GET_NEXT_LINE_H */