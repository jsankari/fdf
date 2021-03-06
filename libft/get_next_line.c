/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:14:00 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/25 17:54:28 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int		ft_result(char **line, char **rmn, int fd, int ret)
{
	size_t		len;
	char		*temp;

	if (ret == 0 && (rmn[fd] == NULL || rmn[fd][0] == '\0'))
		return (0);
	len = ft_strclen(rmn[fd], '\n');
	*line = ft_strsub(rmn[fd], 0, len);
	if (len < ft_strlen(rmn[fd]))
	{
		temp = ft_strsub(rmn[fd], len + 1, ft_strlen(rmn[fd]) - len - 1);
		free(rmn[fd]);
		rmn[fd] = temp;
	}
	else
		ft_strclr(rmn[fd]);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*rmn[FD_SIZE];
	char		*temp;
	int			ret;

	temp = 0;
	if (fd < 0 || fd >= FD_SIZE || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (rmn[fd] == NULL)
			rmn[fd] = ft_strnew(ret);
		temp = ft_strjoin(rmn[fd], buf);
		free(rmn[fd]);
		rmn[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ft_result(line, rmn, fd, ret));
}
