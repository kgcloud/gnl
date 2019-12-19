/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnjuguna <cnjuguna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:58:42 by bsouchet          #+#    #+#             */
/*   Updated: 2019/12/16 19:09:54 by cnjuguna         ###   ########.fr       */
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
	return (1);
}

static int		ft_zero(char **line, char **str, int fd)
{
	*line = ft_strdup(str[fd]);
	free(str[fd]);
	str[fd] = ft_strdup("");
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

// int		main(int argc, char **argv)
// {
// 	int fd = open("test_rh.dict", O_RDONLY);
// 	char *line;
// 	char **str = &line;
	
// 	int fd2 = open("test.dict", O_RDONLY);
// 	char *line2;
// 	char **str2 = &line2;
// 	while (1)
// 	{
// 		int ret = get_next_line(fd, &line);
// 		free(line);
// 		int ret2 = get_next_line(fd2, &line2);
// 		free(line2);
// 		if (!ret2)
// 			return (0);
// 	}
// }

// // 	// 	while (1)
// // 	// {
// // 	// 	int ret2 = get_next_line(fd2, &line2);
// // 	// 	//printf("%d |%s|\n", ret, line);
// // 	// 	free(line2);
// // 	// 	if (!ret2)
// // 	// 		return (0);
// // 	// }
// // }