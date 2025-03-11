/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:35:40 by desambou          #+#    #+#             */
/*   Updated: 2024/11/13 18:18:12 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= ' ' && c <= '~'))
		return (1);
	return (0);
}

// int main(int ac, char *av[])
// {
//     if(ac == 2)
//         printf("%d\n", ft_isprint(av[1]));
//     return (0);
