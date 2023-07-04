typedef struct treeNode{

    int data;
    struct treeNode* left;
    struct treeNode* right;
} treeNodeType;

treeNodeType* root;

void initTree() { root = NULL;}

int isEmpty() { return (root == NULL);}

treeNodeType* searchBST(treeNodeType* bstree, int x )
{
    if(bstree == NULL) return NULL;
    if(bstree->data == x) return bstree;
    if(bstree->data < x)
        return searchBST(bstree->right, x);
    else
        return searchBST(bstree->left, x);
}

treeNodeType* searchBST_iter(treeNodeType* bstree, int x)
{
    while(bstree != NULL){
        if(bstree->data == x) return bstree;

        if(bstree->data < x) 
            bstree = bstree->right;
        else
            bstree = bstree->left;
        }
        return NULL;
}

treeNodeType* insertBST( treeNodeType* bstree, int x)
{
    treeNodeType* newnode;

    if(bstree == NULL){
        newnode = (treeNodeType*)malloc(sizeof(treeNodeType));
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    else if( x < bstree->data) bstree->left = insertBST(bstree->left,x);
    else if( x > bstree->data) bstree->right = insertBST(bstree->right, x);
    else printf("\n 이미 같은 키가 있습니다.\n");

    return bstree;
}

void Inorder(treeNodeType* tree_ptr)
{
    if(tree_ptr != NULL)
    {
        Inorder(tree_ptr->left);
        printf("노드의 값은 %d입니다.\n", tree_ptr->data);
        Inorder(tree_ptr->right);
    }
}