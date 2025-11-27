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

// int	main(void)
// {
// 	char	*line1;
// 	char	*line2;

// 	int fd1, fd2;
// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if (fd1 < 0 || fd2 < 0)
// 	{
// 		perror("Erreur d'ouverture");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		if (!line1 && !line2)
// 			break ;
// 		if (line1)
// 		{
// 			printf("Fichier 1: %s", line1);
// 			free(line1);
// 		}
// 		if (line2)
// 		{
// 			printf("Fichier 2: %s", line2);
// 			free(line2);
// 		}
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
//  echo -e "Ligne1\nLigne2" > test1.txt
// echo -e "LigneA\nLigneB\nLigneC" > test2.txt
