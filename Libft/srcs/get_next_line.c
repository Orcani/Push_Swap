/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:37:48 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 13:54:55 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (!bytes_read)
	{
		free(buffer);
		return (NULL);
	}
	if (bytes_read < 0)
	{
		free(*stash);
		*stash = NULL;
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*combine_stash(char **stash, char *buffer)
{
	char	*rest;

	if (*stash)
	{
		rest = malloc((ft_strlen(*stash) + ft_strlen(buffer) + 1)
				* sizeof(char));
		if (!rest)
		{
			free(buffer);
			return (NULL);
		}
		rest[0] = '\0';
		ft_strlcpy(rest, *stash, ft_strlen(*stash) + 1);
		ft_strlcpy(rest + ft_strlen(*stash), buffer, ft_strlen(buffer) + 1);
		free(*stash);
		*stash = rest;
	}
	else
		*stash = ft_strdup(buffer);
	free(buffer);
	return (*stash);
}

char	*read_and_combine(int fd, char **stash)
{
	char	*buffer;

	buffer = read_buffer(fd, stash);
	if (buffer == NULL)
		return (NULL);
	return (combine_stash(stash, buffer));
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*found;
	char	*rest;

	found = ft_strchr(*stash, '\n');
	if (found)
	{
		line = ft_substr(*stash, 0, found - *stash + 1);
		rest = ft_strdup(found + 1);
		free(*stash);
		*stash = rest;
	}
	else
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!stash || !ft_strchr(stash, '\n'))
	{
		buffer = read_buffer(fd, &stash);
		if (!buffer)
		{
			if (stash && *stash)
				break ;
			free(stash);
			stash = NULL;
			return (NULL);
		}
		stash = combine_stash(&stash, buffer);
	}
	line = extract_line(&stash);
	return (line);
}
