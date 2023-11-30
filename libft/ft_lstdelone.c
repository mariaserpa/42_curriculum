
#include "libft.h"

void	ft_lstdelone(t_list*lst, void (*del)(void*))
{
	del(lst -> content);
	free(lst);
}

/*#include <stdio.h>

void deleteContent(void *content) {
    free(content);
}

int main()
{
	t_list *head = ft_lstnew("Node 1");
	if (!head)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		return (1);
	}
	ft_lstdelone(head, deleteContent);
	return (0);
}*/
