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
	char*				*Path;
	bool				WildChild;
	unsigned int		NodeType;
	unsigned int		MaxParams;
	unsigned char		**Indices
	struct s_TreeNode	**Children;
	void				*Handle;
	unsigned int		Priority;
}		t_TreeNode;

int				getMin(int a, int b);
unsigned int	countParams(char *path);
unsigned int	countChildren(t_TreeNode *node);
int				incrementChildPriority(t_TreeNode *node, int i);
int				getLongestPrefix(char *nodepath, char *path);
int				arraylen(char **array);
char**			arraycpy(char **dest, char **src);
int				nodearraylen(t_TreeNode *node);
t_TreeNode**	nodearraycpy(t_TreeNode **dest, t_TreeNode **src);
void			updateMaxParams(t_TreeNode *node);
void			addRoute(t_TreeNode *node, char *path, void *handle);

#endif /* !TREE_H */
