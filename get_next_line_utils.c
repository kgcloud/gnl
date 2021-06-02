/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: KgCloud <KgCloud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:52:55 by cloud             #+#    #+#             */
/*   Updated: 2021/06/02 16:08:59 by KgCloud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strn(size_t size)
{
	char	*s;

	s = malloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	while (size != 0)
	{
		s[size] = '\0';
		size--;
	}
	s[0] = '\0';
	return (s);
}

size_t	ft_len(char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	n;

	s = ft_strn((size_t)(ft_len(s1) + ft_len(s2)));
	if (s == NULL)
		return (s);
	n = 0;
	while (s1[n])
	{
		s[n] = s1[n];
		n++;
	}
	while (*s2)
		s[n++] = *s2++;
	s[n] = '\0';
	return (s);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * (ft_len(src) + 1));
	if (new_str == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
