// 二叉树的二叉链表结点结构定义
// 结点结构
typedef struct BiTNode
{
	// 结点数据
	TElemType data;
	// 左右孩子指针
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

// 二叉树的前序遍历递归算法
void PreOrderTraverse(BiTree T){
	if(T=NULL)
		return;
	// 显示结点数据，可以更改为其他对结点的操作
	printf("%c",T->data);
	// 再先序遍历左子树
	PreOrderTraverse(T->lchild);
	// 最后先序遍历右子树
	PreOrderTraverse(T->rchild);
}


// 二叉树的中序遍历递归算法
void InOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	// 中序遍历左子树
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);

}


// 二叉树的后序遍历递归算法
void PostOrderTraverse(BiTree T){
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}