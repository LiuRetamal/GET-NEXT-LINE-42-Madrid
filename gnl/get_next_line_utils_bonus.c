/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lretamal <lretamal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:42:04 by lretamal          #+#    #+#             */
/*   Updated: 2025/12/20 13:45:57 by lretamal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	exist_n(char *s)
{
	if (s)
	{
		while (*s)
		{
			if (*s == '\n')
				return (1);
			s++;
		}
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	ft_memcpy(char *dst, char *src, size_t n)
{
	if (dst && src)
	{
		while (n > 0)
		{
			*dst = *src;
			dst++;
			src++;
			n--;
		}
	}
}

char	*free_box(char *box)
{
	free(box);
	return (NULL);
}
