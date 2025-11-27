/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:46:57 by aghalmi           #+#    #+#             */
/*   Updated: 2025/11/17 17:32:05 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

char					*get_next_line(int fd);
char					*ft_strdup(const char *dest);
char					*ft_strchr(const char *s, int c);
char					*ft_strjoin(const char *s1, const char *s2);
size_t					ft_strlen(const char *str);

#endif