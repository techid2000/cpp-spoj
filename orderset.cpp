#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    int height;
    int subtreeLHeight;
    int subtreeRHeight;
    int totalNodes;
    node* nodeL;
    node* nodeR;
    node(int _value){
        totalNodes = 1;
        value=_value;
        height=subtreeLHeight=subtreeRHeight=0;
        nodeL=nodeR=NULL;
    }
};

void updateData(node* _node){
    _node->subtreeLHeight = _node->nodeL ? _node->nodeL->height+1 : 0;
    _node->subtreeRHeight = _node->nodeR ? _node->nodeR->height+1 : 0;
    _node->height = max(_node->subtreeLHeight,_node->subtreeRHeight);

    _node->totalNodes = (_node->nodeL ? _node->nodeL->totalNodes : 0) +
                        (_node->nodeR ? _node->nodeR->totalNodes : 0) + 1;
}

node* rotateLeft(node* _node){
    node* tmp = _node->nodeL;
    _node->nodeL = tmp->nodeR;
    tmp->nodeR = _node;
    updateData(_node);
    updateData(tmp);
    return tmp;
}

node* rotateRight(node* _node){
    node* tmp = _node->nodeR;
    _node->nodeR = tmp->nodeL;
    tmp->nodeL = _node;
    updateData(_node);
    updateData(tmp);
    return tmp;
}

node* Modified(node* _node){
    updateData(_node);
    if(_node->subtreeLHeight - _node->subtreeRHeight > 1){
        if(_node->nodeL->subtreeRHeight > _node->nodeL->subtreeLHeight){
            _node->nodeL = rotateRight(_node->nodeL);
        }
        _node = rotateLeft(_node);
    }
    if(_node->subtreeRHeight - _node->subtreeLHeight > 1){
        if(_node->nodeR->subtreeLHeight > _node->nodeR->subtreeRHeight){
            _node->nodeR = rotateLeft(_node->nodeR);
        }
        _node = rotateRight(_node);
    }
    return _node;
}

node* Insert(node* currentNode,int value){
    if(currentNode==NULL){
        return new node(value);
    }
    if(value < currentNode->value)
        currentNode->nodeL = Insert(currentNode->nodeL, value);
    if(value > currentNode->value)
        currentNode->nodeR = Insert(currentNode->nodeR, value);
    return Modified(currentNode);
}

node* GetMinNode(node* _node){
    if(_node->nodeL==NULL)
        return _node;
    return GetMinNode(_node->nodeL);
}

node* Delete(node* currentNode, int value){
    if(currentNode==NULL){
        return NULL;
    }
    if(value < currentNode->value){
        currentNode->nodeL = Delete(currentNode->nodeL, value);
    }
    if(value > currentNode->value){
        currentNode->nodeR = Delete(currentNode->nodeR, value);
    }
    if(value == currentNode->value){
        node* tmp = NULL;
        if(currentNode->nodeL != NULL && currentNode->nodeR != NULL){
            tmp = GetMinNode(currentNode->nodeR);
            currentNode->value = tmp->value;
            currentNode->nodeR = Delete(currentNode->nodeR, tmp->value);
        } else {
            if(currentNode->nodeL!=NULL) tmp=currentNode->nodeL;
            if(currentNode->nodeR!=NULL) tmp=currentNode->nodeR;
            delete currentNode;
            return tmp;
        }
    }
    if(currentNode == NULL)
        return NULL;
    return Modified(currentNode);
}

int Kth(node* currentNode,int sum, int index){
    int nodesLeftSubtree = currentNode->nodeL ? currentNode->nodeL->totalNodes : 0;
    if(currentNode->nodeL != NULL && index < sum + nodesLeftSubtree + 1) {
        return Kth(currentNode->nodeL, sum, index);
    } else if(currentNode->nodeR != NULL && index > sum + nodesLeftSubtree + 1){
        return Kth(currentNode->nodeR, sum + nodesLeftSubtree + 1, index);
    } else {
        return currentNode->value;
    }
}

int CountSmaller(node* currentNode,int value){
    if(currentNode==NULL)return 0;
    int nodesLeftSubtree = currentNode->nodeL ? currentNode->nodeL->totalNodes : 0;
    if(currentNode->nodeL!=NULL && value <= currentNode->value) {
        return CountSmaller(currentNode->nodeL, value);
    }
    if(currentNode->nodeR!=NULL && value > currentNode->value) {
        return nodesLeftSubtree+1 + CountSmaller(currentNode->nodeR, value);
    }
    if(currentNode->value < value)
        return nodesLeftSubtree+1;
    return 0;
}

node* avl;

int countAll(){
    return avl ? avl->totalNodes : 0;
}


//void tour(node* _node){
//    printf("At node %d\n",_node->value);
//    if(_node->nodeL!=NULL) tour(_node->nodeL);
//    if(_node->nodeR!=NULL) {
//        printf("GoRight from %d\n",_node->value);
//        tour(_node->nodeR);
//    }
//}

int main()
{
    int oper,x;
    char cmd;
    scanf("%d",&oper);
    while(oper--){
        scanf(" %c %d",&cmd,&x);
        if(cmd=='I') avl = Insert(avl,x);
        if(cmd=='D') avl = Delete(avl,x);
        if(cmd=='C') printf("%d\n",CountSmaller(avl,x));
        if(cmd=='K') {
            if(x > countAll()){
                printf("invalid\n");
            } else {
                printf("%d\n",Kth(avl,0,x));
            }
        }
    }
    return 0;
}
