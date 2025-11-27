/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:46:53 by aghalmi           #+#    #+#             */
/*   Updated: 2025/11/17 17:31:54 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*line_extracting(char *save)
{
	size_t	i;
	size_t	len;
	char	*new_line;
	char	*str;

	i = 0;
	len = 0;
	new_line = ft_strchr(save, '\n');
	if (new_line == NULL)
		return (ft_strdup(save));
	else
	{
		len = new_line - save + 1;
		str = malloc(len + 1);
		if (!str)
			return (NULL);
		while (i < len)
		{
			str[i] = save[i];
			i++;
		}
		str[len] = '\0';
	}
	return (str);
}

static char	*line_update(char *save)
{
	char	*next_line;
	char	*next_str;

	next_line = ft_strchr(save, '\n');
	if (!next_line)
	{
		free(save);
		return (NULL);
	}
	else if (*(next_line + 1) == '\0')
	{
		free(save);
		return (NULL);
	}
	else
	{
		next_str = ft_strdup(next_line + 1);
		free(save);
		return (next_str);
	}
}

static char	*all_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

static char	*line_read(int fd, char *save)
{
	char	*read_buff;
	char	*str;
	size_t	len_read;

	len_read = 1;
	read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buff)
		return (NULL);
	while (len_read > 0 && (!ft_strchr(save, '\n')))
	{
		len_read = read(fd, read_buff, BUFFER_SIZE);
		if (len_read == (size_t) - 1)
			return (all_free(read_buff, save));
		if (len_read == 0)
			break ;
		read_buff[len_read] = '\0';
		str = ft_strjoin(save, read_buff);
		if (!str)
			return (all_free(read_buff, save));
		free(save);
		save = str;
	}
	free(read_buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = line_read(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = line_extracting(save[fd]);
	save[fd] = line_update(save[fd]);
	return (line);
}
