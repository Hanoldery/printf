/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <pgerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:34:03 by Pierre            #+#    #+#             */
/*   Updated: 2018/01/05 18:13:51 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *lstnew)
{
	t_list	*temp;

	if (!lstnew)
		return ;
	(lstnew)->next = *alst;
	*alst = lstnew;
}
