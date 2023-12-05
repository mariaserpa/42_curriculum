/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:19:58 by mrabelo-          #+#    #+#             */
/*   Updated: 2023/12/05 15:10:34 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list*lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*new_nod;
	void	*new_content;

	if (!lst || !f || !del)
		return (0);
	new_lst = 0;
	while (lst)
	{
		new_content = f(lst -> content);
		new_nod = ft_lstnew(new_content);
		if (!new_nod)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_nod);
		lst = lst -> next;
	}
	return (new_lst);
}
