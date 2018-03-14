/*
 2_2. Выведите элементы в порядке pre-order (сверху вниз)
 
*/

#include <iostream>
#include<stack>
#include <assert.h>
using std::cin;
using std::cout;




struct TreeRoot
{
    struct CBinaryNode * root=NULL;	// указатель на корень дерева
    int count;
    void PrintDown();

};
struct CBinaryNode {
    int Data;
    CBinaryNode* Left; // NULL, если нет.
    CBinaryNode* Right; // NULL, если нет.
   // CBinaryNode* Parent; // NULL, если корень.
    //void deleteNode(CBinaryNode*&Tree);
    //void PrintTree();
    void PrintTree();
};


int insert(TreeRoot * searchTree, int item)
{
    CBinaryNode * searchNode=NULL;
    CBinaryNode**newNode;
    
    newNode = &searchTree->root;
    searchNode = searchTree->root;
    
    for(;;)
    {
        if(searchNode == NULL)
        {
            searchNode = *newNode = new CBinaryNode( * searchNode);
            if(searchNode != NULL)
            {
                searchNode->Data = item;
                searchNode->Left = searchNode->Right=NULL;
                searchTree->count++;
                return 1;
            }
            else return 0;
        }
        else if(item == searchNode->Data) return 2;
        else if(item > searchNode->Data)
        {
            newNode = &searchNode->Right;
            searchNode = searchNode->Right;
        }
        else
        {
            newNode = &searchNode->Left;
            searchNode = searchNode->Left;
        }
    }
}




 struct Stack {
    size_t size;
    size_t limit;
    Node **data;
} 

Stack* createStack() {
    Stack *tmp = (Stack*) malloc(sizeof(Stack));
    tmp->limit = STACK_INIT_SIZE;
    tmp->size = 0;
    tmp->data = (Node**) malloc(tmp->limit * sizeof(Node*));
    return tmp;
}


void preOrderTravers(Node* root, void (*visit)(Node*, void*), void *params) {
    if (root) {
        visit(root, params);
        preOrderTravers(root->left, visit, params);
        preOrderTravers(root->right, visit, params);
    }
}


int Delete( TreeRoot * searchTree, int ** item)
{
     CBinaryNode  ** first,*second;
    
    first=&searchTree->root;
    second=searchTree->root;
    //поиск удаляемого элемента
    for(;;)
    {
        if(second == NULL) return 0;
        else if(item == (int **)second->Data) break;
        else if(item > (int **)second->Data)
        {
            first = &second->Right;
            second = second->Right;
        }
        else
        {
            first = &second->Left;
            second = second->Left;
        }
    }
    
    // непосредственное удаление элемента
    if(second->Right == NULL) *first = second->Left;
        else
        {
             CBinaryNode * firstWay = second->Right;
            if(firstWay ->Left == NULL)
            {
                firstWay ->Left = second->Left;
                *first-firstWay ;
            }
            else
            {
               CBinaryNode * secondWay=firstWay->Left;
                while(secondWay->Left != NULL)
                {
                    secondWay = firstWay;
                    secondWay = firstWay->Left;
                }
                firstWay->Left = secondWay->Right;
                firstWay->Left = second->Left;
                firstWay->Right = second->Right;
                *first=firstWay;
            }
        }
    
    searchTree->count --;
   delete(second);
    return 1;
}


void CBinaryNode::PrintTree()
{

    std::cout << Data << " ";
    if ( Left != NULL )
    {
        Left->PrintTree();
    }
    if ( Right != NULL )
    {
        Right->PrintTree();
    }

}

void TreeRoot::PrintDown()
{
    root->PrintTree();
}




int main() {
    int N=0;
    cin>>N;
    assert(N>0);
    int copy=N;
    int buffer=0;
    TreeRoot *object = nullptr;
    while (copy!=0)
    {
        cin>>buffer;
        insert(object, buffer);
        --copy;
    }
    object->PrintDown();
    return 0;
}
