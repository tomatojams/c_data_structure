typedef struct treeNode{

    int key;
    char data;
    struct treeNode* left;
    struct treeNode* right;
} treeNodeType;

treeNodeType* root;

void initTree() { root = NULL;}

int isEmpty() { return (root == NULL);}

treeNodeType* searchBST(treeNodeType* bstree, int x )
{
    if(bstree == NULL) return NULL; //루트가 널
    if(bstree->key == x) return bstree; // 키값이 일치하면 해당 노드반환
    if(bstree->key< x) //키값보다 x가크면 오른쪽 재귀함수 호출
        return searchBST(bstree->right, x);
    else // 키값보다 x가 작으면 왼쪽서치 재귀함수 호출
        return searchBST(bstree->left, x);
}

treeNodeType* searchBST_iter(treeNodeType* bstree, int x)
{
    while(bstree != NULL){ // 노드가 널이 아닐대까지
        if(bstree->key == x) return bstree;

        if(bstree->key < x) 
            bstree = bstree->right; // x가 키값보다 크면 오른쪽으로 이동해서 다시 while문 실행
        else
            bstree = bstree->left;
        }
        return NULL;
}

treeNodeType* insertBST( treeNodeType* bstree, int x)
{
    treeNodeType* newnode; // 새로운 노드의 포인터만 생성

    if(bstree == NULL){ // NULL 자리일때 그 자리에 생성
        newnode = (treeNodeType*)malloc(sizeof(treeNodeType)); // 메모리 할당
        newnode->key = x;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode; // 새로운 노드를 리턴
    }

    // NULL이 아니면 탐색
    else if( x < bstree->key) bstree->left = insertBST(bstree->left,x);
    // x가 키값보다 작으면 왼쪽이동하고 다시 호출
    else if( x > bstree->key) bstree->right = insertBST(bstree->right, x);
    else printf("\n 이미 같은 키가 있습니다.\n");

    return bstree;
}

void deleteNode( treeNodeType* bstree, int x) //      bstree 에는 루트값이 보통 들어감
{
    treeNodeType *parent, *node, *succ, *succ_parent, *child;
    
    parent = NULL; // 부모노드 파악이 필요함
    node = bstree; // 루트에서 탐색시작

// 키값 탐색과정 부모노드와 현재노드를 변경하며 탐색
    while( node != NULL && node->key != x){ 
        parent = node; // 탐색하며 부모노드를 변경
        if( x< node->key) node = node->left; // 현재노드는 비교해서 왼쪽 자식노드로 변경
        else node = node->right; // 큰 경우 오른쪽 자식노드로 변경

    }

    if(node == NULL){
        printf("찾는 키가 이진트리에 없습니다.\n");
        return;
    }
// 여기까지 내려오면 키값이 일치했다는 것임 현재 node가 키값이 일치하는 노드임 케이스 1,2,3모두
//키값을 찾고 삭제구현 케이스1 -단말노드

if(node->left == NULL && node->right ==NULL){
    if(parent == NULL) root = NULL; //루트노드일 경우
    else{
        if(parent->left == node) parent->left = NULL; // 부모 왼쪽인 경우 왼쪽 링크삭제
        else parent->right = NULL; // 부모 오른쪽일 경우 오른쪽 노드 삭제
    }
}

 // 케이스2 - 자식노드 1개

 else if(node->left ==NULL || node->right == NULL){ //둘다 널일 경우는 위에서 했으므로 하나만 널인경우만
    
    if(node->left != NULL) child = node->left; // 노드왼쪽에 자식이 있으면 자식노드 표시
    else child = node->right; // 노드오른쪽에 자식이 있으면 자식표시

    if( parent == root) root = child; // 루트일때 루트를 지우고 자식을 할당
    else{

        if(parent->left == node) parent->left = child; // 부모왼쪽에 있을때 자식을 부모의 왼쪽에 할당
        else parent->right = child; // 오른쪽할당
    }
 } else {
// 케이스3 - 자식노드 2개

     succ_parent = node; // 키값을 찾은를 일단 승계자의 부모노드로 표시 
     succ = node->left; // 임으로 선택 왼쪽 오른쪽 하나를 선택해서 왼쪽인경우 최대, 오른쪽일 경우 최소
     // 왼쪽을 선택했으므로 최대값을 찾는다

     while( succ->right == NULL){// 오른쪽으로만 이동해도 최대값이 나오므로 오른쪽으로 이동
         succ_parent = succ; // 승계노드를 승계부모노드로 이동
         succ = succ->right; // 위에서 왼쪽을 선택했으므로 최대값을 찾기위해 오른쪽을 탐색
        }
    // 


    if(succ_parent->left == succ) succ_parent->left = succ->left; 
    // 루트일 경우에는 루트의 왼쪽에 연결해야함
    else succ_parent->right = succ->left; // 루트가 아닐경우 후계자의 자손들을 후계자 부모의 오른쪽에 연결

    node->key = succ->key; //후계자의 키값을 현재 노드의 값으로 이동
    node = succ;  // 임시 노드 포인터를 삭제할 후계자를 지정


 }
free(node);
 
}

void Inorder(treeNodeType* tree_ptr)
{
    if(tree_ptr != NULL)
    {
        Inorder(tree_ptr->left);
        printf("노드의 값은 %d입니다.\n", tree_ptr->key);
        Inorder(tree_ptr->right);
    }
}


