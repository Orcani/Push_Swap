/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:40:52 by desambou          #+#    #+#             */
/*   Updated: 2024/11/15 16:04:22 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (n == 0 || (!dest && !src))
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}

// int main(void)
// {
//     char test [] = "Oh non de zeus";
//     char test2 [] = "mdr";
//     printf("%s\n", test);
//    // printf("%p\n", ft_memcpy2(test2, test, 5));
//     printf("%p\n", ft_memcpy(test2, test, 5));
//     printf("%p\n", memcpy(test2, test, 5));

//     return (0);
// }