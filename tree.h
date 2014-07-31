#ifndef TREE_H
#define TREE_H

typedef unsigned int NodeType;
enum NodeType {
	Static,
	Param,
	CatchAll,
}

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

int		getMin(int a, int b);
unsigned int	countParams(char *path);
unsigned int	countChildren(t_TreeNode *node);
int		incrementChildPriority(t_TreeNode *node, int i);
void		addRoute(t_TreeNode *node, char *path, void *handle);

#endif /* !TREE_H */
