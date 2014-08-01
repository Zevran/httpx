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

char	*strsub(char const *s1, unsigned int start, size_t len)
{
	size_t	slen;
	char	*p_s1;
	char	*p_ret;
	char	*ret;

	slen = strlen(s1);
	if (((start + len) > slen))
		return (NULL);
	ret = (char *) malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	p_s1 = (char *)(s1 + start);
	p_ret = ret;
	while (len--)
		*(p_ret++) = *(p_s1++);
	*p_ret = '\0';
	return (ret);
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

int			arraylen(char **array)
{
	int		index;

	index = 0;
	while (array && *array)
		index++;
	return (index);
}

char			**arraycpy(char **dest, char **src)
{
	int	len;

	len = arraylen(src);
	dest = (char **) malloc(sizeof(char *) * len);
	while (dest && src && *src)
		strcpy(*(dest++), *(src++));
	*dest = '\0';
	return (dest);
}

int				nodearraylen(t_TreeNode **node)
{
	int	index;

	index = 0;
	while(node && *node)
		index++;
	return (index);
}

t_TreeNode		**nodearraycpy(t_TreeNode **dest, t_TreeNode **src)
{
	int len;

	len = nodearraylen(src);
	dest = (t_TreeNode **) malloc(sizeof(t_TreeNode *) * len);
	while (dest && src && *src)
		*dest++ = &(*src++);
	return (dest);
}

void			updateMaxParams(t_TreeNode *node)
{
	int	i;

	i = 0;
	while (node->Children[i])
	{
		if (node->Children[i]->MaxParams > node.MaxParams)
			node->MaxParams = node->Children[i]->MaxParams;
		i++;
	}
}

t_TreeNode		**addChild(t_TreeNode **children, t_TreeNode *child)
{
	int			len;
	t_TreeNode	**tmpChildren;

	len  = nodearraylen(children);
	if (len == 0)
	{
		children = (t_TreeNode **) malloc(sizeof(t_TreeNode) * 1);
		*children = child;
	}
	else if (len > 0)
	{
		tmpChildren = (t_TreeNode **) malloc(sizeof(t_TreeNode) * (len + 1));
		while (children && *children)
			*tmpChildren++ = *children++;
		*tmpChildren = child;
		free(children);
		children = tmpChildren;
	}
	return (children);
}

char		**addIndice(char **indices, char *indice)
{
	int		len;
	char	**tmpArray;

	len = arraylen(indices);
	if (len == 0)
	{
		indices = (char **) malloc(sizeof(char **) * 1);
		strcpy(*indices, indice);
	}
	else if (len > 0)
	{
		tmpArray = (char **) malloc(sizeof(char *) * (len + 1));
		while (indices && *indices)
			strcpy(*tmpArray++, *indices++);
		*tmpArray = indice;
		free(indices);
		indices = tmpArray;
	}
	return (indices);
}

void		addRoute(t_TreeNode *node, char *path, void *handle)
{
	int		numParams, i, j;
	char	delimiter;
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
				child->Handle = node->Handle;
				child->Priority = node->Priority - 1;

				updateMaxParams(child);

				addChild(node->Children, &child);
				addIndice(node->Indices, node.Path[i]);
				node.Path = &path[i];
				node.Handle = NULL;
				node.WildChild = false;
			}
			if (i < strlen(path))
			{
				path = &path[i];
				if (node->WildChild == true)
				{
					node = node->Children[0];
					node->Priority++;
					node->MaxParams = (numParams > node->MaxParams) ? numParams :;
					numParams--;

					if (strlen(path) >= strlen(node->Path) && strcmp(node->Path, &path[strlen(node->Path)]))
					{
						if (strlen(node->Path) >= strlen(path) || path[strlen(node->Path) == '/'])
							continue ;
					}
					exit(-1);
				}
				delimiter = path[0];
				if (node->NodeType == Param && delimiter == '/' && nodearraylen(node->Children) == 1)
				{
					node = node->Children[0];
					node->Priority++;
					continue ;
				}
				j = 0;
				while (node->Indices[j])
				{
					if (delimiter == node->Indices[j])
					{
						i = incrementChildPriority(i);
						node = node->Children[j];
						continue ;
					}
					j++;
				}
				if (delimiter != '*' || delimiter != ':')
				{
					addIndice(node->Indices, delimiter);
					child = (* t_TreeNode) malloc(sizeof(t_TreeNode));
					child->MaxParams = numParams;
					addChild(node->Children, child);
					incrementChildPriority(arraylen(node->Indices) - 1);
					node = child;
				}
				insertChild(node, numParams, path, handle);
				return ;
			}
			else if (i == strlen(path))
			{
				if (node->Handle != NULL)
					exit(-1);
				node->Handle = handle;
			}
			return ;
		}
	}
	else
	{
		insertChild(node, numParams, path, handle);
	}
}

void	insertChild(t_TreeNode *node, int numParams, char *string, void handle)
{
	int 		offset, index, max, end;
	char		delimiter;
	t_TreeNode	*child;

	index = 0;
	max = strlen(path);
	while (numParams > 0)
	{
		delimiter = path[i];
		if (delimiter != ':' && delimiter != '*')
		{
			i++;
			continue ;
		}
		if (nodearraylen(node->Children) > 0)
			exit(-1);
		end = i + 1;
		while (end < max && path[end] != '/')
			end++;
		if ((end - i) < 2)
			exit(-1);
		if (delimiter == ':')
		{
			if (i > 0)
			{
				node->Path = strsub(path, offset, i);
				offset = i;
			}
			child = (t_TreeNode *) malloc(sizeof(t_TreeNode));
			child->NodeType = Param;
			child->MaxParams = numParams;
			addChild(node->Children, child);
			node->WildChild = true;
			node = child;
			node->Priority++;
			numParams--;
			if (end < max)
			{
				node->Path = strsub(path, offset, i);
				offset = end;
				child = (t_TreeNode *) malloc(sizeof(t_TreeNode));
				child->MaxParams = numParams;
				child->Priority = 1;
				addChild(node, child);
				node = child;
			}
		}
		else
		{
			if (end != max || numParams > 1)
				exit(-1);
			if (strlen(node.Path) > 0 && node.Path[strlen(node.Path) - 1] == '/')
				exit(-1);
			i--;
			if (path[i] != '/')
				exit(-1);
			node->Path = strsub(path, offset, i);
			child = (t_TreeNode *) malloc(sizeof(t_TreeNode));
			child->WildChild = true;
			child->NodeType = CatchAll;
			child->MaxParams = 1;
			addChild(node->Children, child);
			addIndice(node->Indices, &path[i]);
			node = child;
			node->Priority++;

			child = (t_TreeNode *) malloc(sizeof(t_TreeNode));
			child->Path = &path[i];
			child->NodeType = CatchAll;
			child->MaxParams = 1;
			child->Handle = handle;
			child->Priority = 1;
			addChild(node->Children, child);
			return ;
		}
		i++;
	}
	node->Path = &path[offset];
	node->Handle = handle;
}
