/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:15:38 by desambou          #+#    #+#             */
/*   Updated: 2024/11/16 16:03:59 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// mem is the location of the data (adress)

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (d == s || n == 0)
		return (dest);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dest);
}

// int main(void)
// {
//     char test [] = "Oh non de zeus";
//     char test2 [] = "";
//     printf("%s\n", test);
//     printf("%p\n", memmove(test2, test, 1));
//     printf("%p\n", ft_memmove(test2, test, 1));
//     return (0);
// }