/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:56:17 by desambou          #+#    #+#             */
/*   Updated: 2024/11/16 16:04:18 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned int	len_s;
	unsigned int	len_d;

	i = 0;
	len_s = ft_strlen(src);
	len_d = ft_strlen((const char *)dst);
	if (size <= len_d)
		return (len_s + size);
	while (src[i] != '\0' && i + len_d < size - 1)
	{
		if (size > 0)
		{
			dst[len_d + i] = src[i];
			i++;
		}
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}
