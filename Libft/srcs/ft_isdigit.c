/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:57:18 by desambou          #+#    #+#             */
/*   Updated: 2024/11/13 18:12:19 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// int main(int ac, char *av[])
// {
//     if(ac == 2)
//         printf("%d\n", ft_isdigit(av[1]));
//     return (0);
// }