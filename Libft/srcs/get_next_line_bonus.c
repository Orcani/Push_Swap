/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:37:48 by desambou          #+#    #+#             */
/*   Updated: 2025/02/20 13:40:25 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!stash[fd] || !ft_strchr(stash[fd], '\n'))
	{
		if (!read_and_combine(fd, &stash[fd]))
		{
			if (stash[fd] && *stash[fd])
				break ;
			free(stash[fd]);
			stash[fd] = NULL;
			return (NULL);
		}
	}
	line = extract_line(&stash[fd]);
	return (line);
}
// #include <stdio.h>

// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Error opening file\n");
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//         sleep(1);  // Sleep for 1 second between each line
//     }

//     close(fd);
//     return (0);
// }
