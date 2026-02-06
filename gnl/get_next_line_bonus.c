/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lretamal <lretamal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:27:38 by lretamal          #+#    #+#             */
/*   Updated: 2026/01/09 18:00:22 by lretamal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_str(char *s1, char *s2)
{
	char	*str;
	int		l1;
	int		l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc(l1 + l2 + 1);
	if (!str)
		return (free_box(s1));
	ft_memcpy(str, s1, l1);
	ft_memcpy(&str[l1], s2, l2);
	str[l1 + l2] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*read_file(int fd, char *box)
{
	char	*str;
	int		read_bt;

	if (exist_n(box))
		return (box);
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (free_box(box));
	read_bt = BUFFER_SIZE;
	while (!exist_n(box) && read_bt == BUFFER_SIZE)
	{
		read_bt = read(fd, str, BUFFER_SIZE);
		if (read_bt == -1)
		{
			free(str);
			return (free_box(box));
		}
		str[read_bt] = '\0';
		if (read_bt != 0)
			box = join_str(box, str);
	}
	free(str);
	return (box);
}

char	*new_line(char *box)
{
	char	*line;
	int		i;

	i = 0;
	if (box[0] == '\0')
		return (NULL);
	while (box[i] && box[i] != '\n')
		i++;
	if (box[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free_box(box));
	ft_memcpy(line, box, i);
	line[i] = '\0';
	return (line);
}

char	*clean_box(char *box)
{
	char	*res;
	char	*temp;

	if (!box)
		return (NULL);
	if (*box == '\0')
		return (free_box(box));
	temp = box;
	while (*temp && *temp != '\n')
		temp++;
	if (*temp == '\0')
		return (free_box(box));
	temp++;
	res = malloc(ft_strlen(temp) + 1);
	if (!res)
		return (free_box(box));
	ft_memcpy(res, temp, ft_strlen(temp));
	res[ft_strlen(temp)] = '\0';
	free(box);
	if (res[0] == '\0')
		return (free_box(res));
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*box[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	box[fd] = read_file(fd, box[fd]);
	if (!box[fd])
		return (NULL);
	line = new_line(box[fd]);
	if (!line)
	{
		box[fd] = NULL;
		return (box[fd]);
	}
	box[fd] = clean_box(box[fd]);
	return (line);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);

	char *ptr; 
	ptr = get_next_line(fd);
	printf("Line1 FD1:");
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd2);
	printf("Line1 FD2:");
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("Line2 FD1:");
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd2);
	printf("Line2 FD2:");
	printf("%s", ptr);
	free(ptr);
	close(fd);
	return(0);
}
