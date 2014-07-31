#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tree.h"

int		getMin(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

unsigned int	countParams(char *path)
{
	unsigned int	i;

	i = 0;
	while (i < strlen(path)) {
		if (path[i] != ':' && path[i] != '*')
			continue;
		i++;
	}
	if (i >= 255)
		return (255);
	return ((unsigned int) n);
}

unsigned int	countChildren(t_TreeNode *node)
{
	int		i;

	i = 0;
	while (node.Children[i] != NULL)
		i++;
	return (i);
}

int		incrementChildPriority(t_TreeNode *node, int i)
{
	int		priority, j;
	t_TreeNode	*tmpN, *tmpI;
	
	if (node == NULL)
		return (0);
	priority = ++node->(Children[i])->Priority;
	j = i - 1;
	while (j >= 0 && node->(Children[j])->Priority < priority && node->Children[j] != NULL)
	{
		tmpN = node->Children[j];
		node->Children[j] = node->Children[i];
		node->Children[i] = tmpN;
		tmpI = node->Indices[j];
		node->Indices[j] = node->Indices[i];
		node->Indices[i] = tmpI;	
		j--;
	}
	return (i);
}

int		getLongestPrefix(char *nodepath, char *path)
{
	int	max, i;

	max = getMin(strlen(path), strlen(nodepath));
	i = 0;
	while (i < max && path[i] == nodepath[i])
		i++;
	return (i);
}

char**		arraycpy(char **dest, char **src)
{
	char	**ptr;
	int	len;

	ptr = dest;
	while (src && *str && **str)
	{

	}
	return (dest);
}

t_TreeNode**	nodearrycpy(t_TreeNode **dest, t_TreeNode **src)
{
	return (dest);
}

void		addRoute(t_TreeNode *node, char *path, void *handle)
{
	int		numParams, i;
	t_TreeNode	*child;

	if (node == NULL)
		return ;
	node->Priority++
	numParams = countParams(path);
	if (strlen(node->Path) > 0 && countChildren(node) > 0)
	{
		while (true)
		{
			node->MaxParams = (numParams > node->MaxParams) ? numParams :;
			i = getLongestPrefix(node->Path, path);
			if (i < strlen(node->Path))
			{
				child = (* t_TreeNode) malloc(sizeof(t_TreeNode));
				if (child != NULL)
					return ;
				strcpy(child->Path, &node.Path[i]);
				child->WildChild = node.WildChild;
				arraycpy(child->Indices, node.Indices);
				nodearraycpy(child->Children, node.Children);

			}
			
		}
	}	
}

