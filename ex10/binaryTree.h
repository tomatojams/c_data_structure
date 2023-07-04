typedef struct treeNode{
    char data;
    struct treeNode* left;
    struct treeNode* right;

} treeNodeType;

treeNodeType* root;

void initTree(){ root = NULL;}

int isEmpty(){ return( root == NULL);}

treeNodeType* createTree( char elem_data, treeNodeType* left, treeNodeType* right)
{
    treeNodeType* n = (treeNodeType*)malloc(sizeof(treeNodeType));
    n->data = elem_data;
    n->left = left;
    n->right = right;

    return n;
}

void Inorder(treeNodeType* tree_ptr)
{
    if(tree_ptr != NULL)
    {
        Inorder(tree_ptr->left);
        printf("노드의 값은 %c입니다.\n", tree_ptr->data);
        Inorder(tree_ptr->right);
    }
}

void Postorder(treeNodeType* tree_ptr)
{
    if(tree_ptr != NULL)
    {
        Postorder(tree_ptr->left);
        Postorder(tree_ptr->right);
        printf("노드의 값은 %c입니다.\n", tree_ptr->data);
    }
}

void Preorder(treeNodeType* tree_ptr)
{
    if(tree_ptr != NULL)
    {
        printf("노드의 값은 %c입니다.\n", tree_ptr->data);
        Preorder(tree_ptr->left);
        Preorder(tree_ptr->right);
    }
}

int TreeSize(treeNodeType* T)
{
    int Count =0;
    if( T != NULL)
    {

        Count = TreeSize(T->left) +TreeSize(T->right) + 1;
        
    }
    
    return Count;
}