/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloud <cloud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:52:19 by cloud             #+#    #+#             */
/*   Updated: 2020/11/24 12:03:41 by cloud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read(char **str, int fd)
{
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	tmp = *str;
	*str = ft_strjoin(*str, buf);
	free(tmp);
	tmp = NULL;
	return (ret);
}

static int		ft_one(char **str, char **line, char *s)
{
	char *tmp;

	*s = '\0';
	*line = ft_strdup(*str);
	tmp = *str;
	*str = ft_strdup(s + 1);
	free(tmp);
	tmp = NULL;
	return (1);
}

static int		ft_zero(char **line, char **str, int fd)
{
	*line = ft_strdup(str[fd]);
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	long		ret;
	char		*s;

	if (!line || BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	ret = BUFFER_SIZE;
	while (1)
	{
		s = str[fd];
		while (*s || ret < BUFFER_SIZE)
		{
			if (*s == '\n')
				return (ft_one(&str[fd], line, s));
			if (ret == 0 || *s == 0)
				return (ft_zero(line, str, fd));
			s++;
		}
		if ((ret = ft_read(&str[fd], fd)) == -1)
			return (-1);
	}
	return (0);
}
