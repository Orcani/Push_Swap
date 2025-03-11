/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:22:41 by desambou          #+#    #+#             */
/*   Updated: 2024/11/21 12:28:36 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;

	p = s;
	uc = c;
	while (n--)
	{
		if (*p == uc)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

// uc pour Unsigned Char
// int main(void)
// {
//     char test [] = "Oh non de zeus";
//     char test2 = 110;
//     printf("%s\n", test);
//     printf("%p\n", memchr(test, test2, 8));
//     printf("%p\n", ft_memchr(test, test2, 8));
//     return (0);
// }