/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloud <cloud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:53:15 by cloud             #+#    #+#             */
/*   Updated: 2020/11/21 18:53:18 by cloud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int		get_next_line(int const fd, char **line);
char	*ft_strn(size_t size);
size_t	ft_len(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);

#endif
