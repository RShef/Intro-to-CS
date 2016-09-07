  /******************************************
 * Student name:          Roy Shefi
 * Student ID:            204845929
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex6
 ******************************************/
#include "GenBST.h"
typedef enum {SMALLER,BIGGER,SAME}Compere;
typedef struct BST_S {
    Elm val;
    int rank;
    int maxRank;
    struct BST_S* left;
    struct BST_S* right;
    void   (*cpy_elm) (Elm, Elm);
    int    (*cmp_elm)(Elm, Elm);
    void   (*free_elm) (Elm);
    Elm    (*create_elm)();
    void   (*print_elm)(Elm);
} BST_T;
int PrintOuterFunction(int j,BST_ROOT root, int count,Elm node,int*flag,
                       int* s,int*f,int max,int*h,int*p);
int PrintSpaces(BST_T*Node,int count, int j,BST_ROOT root);
static int FindPlace(BST_T* Root, BST_T* Node);

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
BST_ROOT BSTCreate (Elm root_val, Elm (*create_elm)(), void (*cpy_elm)(Elm,Elm),
                    int (*cmp_elm)(Elm, Elm), void (*free_elm)(Elm),
                    void print_elm(Elm)){
    //Alocating memory.
    BST_T *root = (BST_T*) malloc(2*sizeof(struct BST_S));
    if ( NULL != root ){
        root->left = NULL;
        root->right = NULL;
        root->create_elm = create_elm;
        //Insrting elm value in val.
        root->val = create_elm();
        if (root->val == NULL) {
            free(root);
            return 0;
        }
        root->free_elm = free_elm;
        root->cpy_elm = cpy_elm;
        //Copying node val to struct.
        cpy_elm(root->val, root_val);
        root->cmp_elm = cmp_elm;
        root->print_elm = print_elm;
        root->rank =1;
    }
    else{
        free(root);
        return 0;
    }
return root;
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
Result BSTAddElement(BST_ROOT root, Elm node){
    //Converting gneric to specific elment.
    BST_T*Root = (BST_T*)root;
    int curr;
    //Passing type functions to generic one.
    BST_T*Node =  BSTCreate (node, Root->create_elm, Root->cpy_elm,
                             Root->cmp_elm,Root->free_elm ,Root->print_elm);
    curr = FindPlace(Root,Node);
    if (Root->maxRank < curr) {
        Root->maxRank = curr;
    }
    return SUCEESS;
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
static int FindPlace(BST_T* Root, BST_T* Node){
    //chacking where the root shold be placed.
    ((Node->rank))++;
    if (Root->cmp_elm(Root->val, Node -> val) == BIGGER){
        if (Root->left != NULL){
            //recrecive function,cheking where the spcific "son" should be.
            //rec func.
            FindPlace(Root->left, Node);
        }
        else{
            //when his place is found, insert in to place.
            Root->left = Node;
        }
    }
    //checking the right side of node.
    else{
        //recreciveing function,cheking where the spcific "son" should be.
        if (Root->right != NULL){
            //checking where on the rigth side the son should be.
            //rec func.
            FindPlace(Root->right, Node);
            }
        else{
            //when his place is found, insert in to place.
            Root->right = Node;
        }
    }
    return (Node->rank);
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
Elm BSTFindElement(BST_ROOT root, Elm node){
    //Temp helping varieable.
    //Cast generic elm to relevent type.
    BST_T*Root = (BST_T*)root;
    int flag;
    // if they are the same,return the node.
    flag = Root->cmp_elm(node, Root->val);
    if (flag == SAME){
        return (Root);
    }
    //if the node is bigger, call rec func to keep checking.
    else if (flag == SMALLER){
        //rec func base.
        if (Root->left != NULL){
            //return the node or 0 to calling func.
            return  BSTFindElement(Root->left, node);
        }
    }
    //if the node is smaller, call rec func to keep checking.
    else if(flag == BIGGER){
        //rec func base.
        if (Root->right != NULL){
            //return the node or 0 to calling func.
            return  BSTFindElement(Root->right, node);
        }
    }
 //If node not found, return 0.
 return 0;
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
static Elm FindFather(BST_ROOT root,Elm node){
    //Temp helping varieable.
    //Cast generic elm to relevent type.
    BST_T*Root = (BST_T*)root;
    BST_T*Node = (BST_T*)node;
    //Pass type functions to generic one.
    if (Root->left != NULL){
        //if the node is bigger, call rec func to keep checking.
        if (Root->cmp_elm((Root->left)->val, Node->val) == BIGGER){
                //return the node or 0 to calling func.
                return FindFather(Root->left, node);
        }
    }
    else if (Root->right != NULL){
        //if the node is smaller, call rec func to keep checking.
        if(Root->cmp_elm((Root->right)->val, Node->val) == SMALLER){
                //return the node or 0 to calling func.
                return FindFather(Root->right, node);
            }
    }
    if (Root->right && (Root->cmp_elm((Root->right)->val, Node->val) == BIGGER
                        && Root->cmp_elm(Root->val, Node->val) == SMALLER)) {
        return FindFather(Root->right, node);
    }

    if (Root->left&&(Root->cmp_elm((Root->left)->val, Node->val) == SAME)) {
            return Root;
    }
    
    if (Root->right && (Root->cmp_elm((Root->right)->val, Node->val) == SAME)) {
        return Root;
    }
    
    //If node not found, return 0.
    return 0;
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
static Elm FindMinToRemove(BST_T* Node){
    Elm *minNode;
    //If there is a left son.
    if (Node->left) {
        //recusive call to function.
        minNode = FindMinToRemove(Node->left);
        //Return pointer to node that is switched with.
        return minNode;
    }
    else{
        return Node;
    }

    return 0;
    
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
static void OneSon(BST_T* Father, BST_T* Node){
    BST_T*Temp = (BST_T*)malloc(sizeof(BST_T));
    if (!Temp) {
        free(Temp);
    }
    if (!(Node->left)&&(Node->right)){
        if (Father->left == Node) {
            Temp = Node->right;
            //free(Father->left);
            Father->left = Temp;

        }
        else{
            Temp = Node->right;
            //free(Father->right);
            Father->right = Temp;
            Father->right = Node->right;
        }
    }
    else if (!(Node->right)&&(Node->left)){
        if (Father->left == Node) {
            Father->left = Node->left;
            Temp = Node->left;
            //free(Father->left);
            Father->left = Temp;
            Father->left =Node->left;
        }
        else{
            Temp = Node->left;
            //free(Father->right);
            Father->right = Temp;
            Father->right =Node->left;
        }
        Node->left = NULL;
    }
    Temp = NULL;
    free(Temp);
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
static void NoSons(BST_T* Father, BST_T* Node){
    //Father = FindFather(Father, Node);
    if (Father->left == Node) {
        Father->left = NULL;
        //free(Father->left);
    }
    else{
        Father->right = NULL;
        //free(Father->right);
        
    }
    
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
static void TwoSons(BST_T* Root, BST_T* Node,BST_T*Father){
    if (FindMinToRemove(Node)) {
        BST_T*Min = FindMinToRemove(Node->left);
        if(!(Min->left)){
            Father = FindFather(Root,Min);
            if (!(Min->right)){
                NoSons(Father,Min);
            }
            else
                OneSon(Father,Min);
            (*Node).val = (*Min).val;
            
        }
    }
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
Result BSTRemoveElement (BST_ROOT root, Elm node){
    //Converting gneric to specific elment.
    BST_T**Root = (BST_T**)root;
    BST_T*Father = NULL;
    int d=0;
    //Passing type functions to generic one.
    BST_T*Node= BSTFindElement(*Root, node);
    if (!Node){
        return BAD_ARGS;
    }
    else{
        Father = (BST_T*) malloc(sizeof(struct BST_S));
        Father = FindFather(*Root,Node);
        if(!Father){
            if (!Father) {
                Father = (BST_T*) malloc(sizeof(struct BST_S));
                d = 1;
                //Father = (BST_T*) malloc(sizeof(struct BST_S));
                Father->left = *Root;
            }
        }
        //If the node is a the only node in tree.

            if (Father->left == *Root && !(*Root)->left && !(*Root)->right){
                (*Root)->free_elm(*Root);
                return ROOT;
            }
            if (Node->left == Node->right){
                NoSons(Father,Node);
            }
            else if (Node->left || Node->right){
                if (Node->right && Node->left) {
                    TwoSons(*Root,Node,Father);
                }
            else
                OneSon(Father,Node);
            }
            if (d) {
              *Root = (Father->left);
            }
            Node = NULL;
        
        
    }
    return FAILURE;
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
void BSTDestroy (BST_ROOT root){
    BST_T**Root = (BST_T**)root;
    if (!((*Root)->left) && !((*Root)->right)) {
        BSTRemoveElement(&root,Root);
        return;
    }
    if ((*Root)->left){
        BSTDestroy((*Root)->left);
    }
    if ((*Root)->right) {
        BSTDestroy((*Root)->right);
    }
    return;

}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
int CountSpaces(BST_T* root,int count, int j){
    BST_T*Root = (BST_T*)root;
    if (Root == NULL)
        return 0;
    
    if (Root->left != NULL){
        count++;
    }
    if (Root->right!= NULL) {
        count++;
    }
    if (Root->left != NULL) {
        count = CountSpaces(Root->left, count,j);
    }
    if (Root->right!= NULL) {
        count = CountSpaces(Root->right, count,j);
    }
    if ((Root->right== NULL) && (Root->left == NULL)){
        return count;
    }
    
    return count;
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
int PrintNode(int j,BST_ROOT root ,int spaces,int* flag,int*s,int*f,
              int*h,int*p){
    BST_T*Root = (BST_T*)root;
    int count = 0;
    int ret = 0,ret2 =0;
    int d = 0;
    int* flagSp = NULL;
    flagSp = &d;
    if (Root){
        if (j == 1) {
            Root->print_elm(Root->val);
            if (Root->right) {
            (*f) = CountSpaces((Root->right), 0,j);
                *h = Root->rank;

            }
            //(*p) = 0;
            return 0;
        }
        if(!Root->right && j ==2)
            (*p)++;
        if(!Root->left && j ==2)
            (*p)++;
        if (Root->left) {
            if (j == 2) {
                if ((*flag)) {
                    spaces = CountSpaces((Root->left)->left, 1,j)+1;
                    if ((Root->left)->rank == (*h) ) {
                        spaces += (*f);
                    }
                    spaces += (*p);
                }
                else {
                spaces = PrintSpaces(Root->left,count,j,root);
                }
                printf("%*s",5*spaces,"");
                spaces = 0;
                if (!spaces && !(*flagSp)) {
                    (*s) = 0;
                }
            }
            PrintNode(j-1,Root->left, spaces, flag, s,f,h,p);
        }
        else if(j == 2){
            if (!(*s)){
                (*s) = -1;
                *flagSp = 1;
                
            }
                
        }
        
        if (Root->right){
            if ( j == 3)
                (*flag)++;
            
            if (j == 2) {
                spaces = CountSpaces((Root->right)->left, 1,j);
                if ((Root->right)->rank == (*h)) {
                    spaces += (*f);
                }
                spaces += (*p);
                if (!(*flagSp))
                    (*s) =0;
                
                    (*flagSp)++;
                    printf("%*s",5*(spaces+(*s)+1),"");
                (*p) = 0;
                spaces = 0;
            }
            PrintNode(j-1,Root->right, spaces, flag, s,f,h,p);
        }
        
    }
    return ret||ret2;
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
int FindMax(BST_T* Root,int* max){
    if (Root->left || Root->right) {
        (*max)++;
    }
    else
        return (*max);
    
    if (Root->left) {
        FindMax(Root->left,max);
    }
    if (Root->right) {
        FindMax(Root->right,max);
    }
    return (*max);
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
int FindMaxRank(BST_ROOT root){
    BST_T*Root = (BST_T*)root;
    int*max = NULL;
    int x = 1;
    max = &x;
    return FindMax(Root,max);
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
int PrintOuterFunction(int j,Elm root, int count,Elm node,int*flag,
                       int *s,int*f,int max,int*h,int*p){
    int spaces;
    if (max >= j){
        if (j == 1){
            printf("%*s",5*(PrintSpaces(root,count,j,root)),"");

        }
        PrintNode(j,root,spaces,flag,s,f,p,h);
        if ( max != j)
            printf("\n");
        PrintOuterFunction( ++j,root,count,node,flag,s,f,max,h,p);
    }
    return 0;
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
void PrintRightSp(BST_T*Node,int*s){
    int j;
    if (Node->left) {
        int count = CountSpaces(Node,1,j);
        printf("%*s",5*count,"");
    }
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
int PrintSpaces(BST_T*node,int count, int j,BST_ROOT root){
    int flag;
    BST_T*Root = (BST_T*)root;
    BST_T*Node = (BST_T*)node;
    if (!Root) {
        return count;
    }
    flag = Root->cmp_elm(Root->val, Node->val);
    if (flag == SAME){
        if (Root->left) {
        return CountSpaces(Node->left,count,j)+1;
        }
    }
    else if (flag == SMALLER){
        if (Root->left) {
            count = CountSpaces(Root->left,count,j)+1;
        }
        return PrintSpaces(Node, count, j, Root->right)+count;

    }
    else if (flag == BIGGER){
        return PrintSpaces(Node, count, j, Root->left)+count;
    }
    
    return count;
}

/****************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * **************************************************************/
Elm PrintBST(BST_ROOT root){
    int j =1;
    int count = 0,*s = NULL;
    int* flag;
    int dumm = 0,dumm2 = 0,d3 = 0,d4 = 0 , d5 = 0;
    int*f;
    int*h;
    int*p;
    p = &d4;
    h = &d5;
    f = &dumm;
    flag = &dumm2;
    s = &d3;
    int max = FindMaxRank(root);
    Elm node;
    node = root;
    PrintOuterFunction(j, root, count,node,flag,s,f,max,h,p);
    return 0;
}
