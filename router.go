package tradix

/*

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const unsigned int

typedef struct	s_TreeNode
{
	char*			*Path;
	bool			WildChild;
	unsigned int		NodeType;
	unsigned int		MaxParams;
	unsigned char		**Indices
	struct s_TreeNode	**Children;
	void			*Handle;
	unsigned int		Priority;
}		t_TreeNode;

int getMin(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

unsigned int countParams(char *path)
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

*/

import "C"
