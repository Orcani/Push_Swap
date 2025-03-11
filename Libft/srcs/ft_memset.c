/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:58:32 by desambou          #+#    #+#             */
/*   Updated: 2024/11/13 13:43:35 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	value;
	size_t			i;

	p = s;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p[i] = value;
		i++;
	}
	return (s);
}

// int main(int ac, char *av[])
// {

//     if(ac == 5)
//     {
//         printf("%s\n", av[1]);
//         printf("%p\n", ft_memset(av[2], *av[3], *av[4]));
//         printf("%p\n", memset(av[2], *av[3], *av[4]));
//     }
//     return (0);
// }
