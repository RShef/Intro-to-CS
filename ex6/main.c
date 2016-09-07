/******************************************
 * Student name:          Roy Shefi
 * Student ID:            
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex6
 ******************************************/
/************************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * *************************************************************************/
#include "GenBST.h"
typedef enum {SMALLER,BIGGER,SAME}Compere;
//Int type - fuction declaration.
Elm create_int();
void cpy_int(Elm val ,Elm root_val);
int cmp_int(Elm elm1, Elm elm2);
int Menu_int(void *root,int**node,int*MaxRank);
void print_int(Elm elm);
void free_node(Elm elm);

/**
 Point type - fuction declaration.
 point stuct
 **/
typedef struct BST_P{
    int x;
    int y;
    int pt;
}POINT;
int Menu_point(void *root,POINT**node,int*MaxRank);
Elm create_point();
POINT* AddPoint(POINT*point);
void cpy_point(Elm val ,Elm root_val);
int cmp_point(Elm elm1, Elm elm2);
void print_point(Elm elm);
void free_point(Elm elm);

int main(){
    int choice,dumm;
    void*root = NULL;
    int *node= NULL;
    int * MaxRank = NULL;
    MaxRank = &dumm;
    scanf("%d", &choice);
    if (choice == 0){
        //geting the root of the BT from the user.
        int root_val;
        scanf("%d", &root_val);
        //add if malloc of BSTCrate faiils.
        root = BSTCreate (&root_val, (*create_int), (*cpy_int),
                          (*cmp_int),(*free_node),(*print_int));
        Menu_int(root,&node, MaxRank);
    }
    else{
        int x,y;
        char d;
        POINT *node; //= (BST_POINT*) malloc(1000*sizeof(BST_POINT));
        scanf("%c%c%d%c%d%c",&d,&d,&x,&d,&y,&d);
        POINT * point= (POINT*)malloc(2*sizeof(POINT));
        if (point == NULL) {
            free(point);
            return 0;
        }
        point->x = x;
        point->y = y;
        point = BSTCreate (point, (*create_point), (*cpy_point),
                          (*cmp_point),(*free_node),(*print_point));
        //Recursion function, untli input is 'e'.
        Menu_point(point, &node, MaxRank);
    }
    return 0; 
}
/************************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * *************************************************************************/
Elm create_int(){
    int* val;
    //alocating memorey for root.
    val = (int*) malloc(sizeof(int));
    if(val == NULL){
        free(val);
    }
    return val;
}
/************************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * *************************************************************************/
// sending by addres.
void cpy_int(Elm val ,Elm root_val){
    *((int*)val) = *(int*)root_val;
}
/************************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * *************************************************************************/
int cmp_int(Elm elm1, Elm elm2){
    if(*(int*)elm1 > *(int*)elm2){
        return BIGGER;
    }
    else if (*(int*)elm1 == *(int*)elm2){
        return SAME;
    }
    else{
        return SMALLER;
    }
}
/************************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * *************************************************************************/
void print_int(Elm elm){
    int num = *(int*)elm;
    printf("%05d",num);
}
/************************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * *************************************************************************/
/************************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * *************************************************************************/
int Menu_int(void *root,int**node,int*MaxRank){
    char input;
    scanf("%c", &input);
    int input_int;
    switch (input) {
            //add new node to tree.
        case 'a':
            scanf("%d", &input_int);
            *node = &input_int;
            *MaxRank = BSTAddElement(root,*node);
            if(*MaxRank ==  OUT_OF_MEM){
                return FAILURE;
            }
            break;
            //find if node input is in tree
        case 's':
            scanf("%d", &input_int);
            *node = &input_int;
            if (BSTFindElement(root,&input_int) ==0) {
                printf("FALSE\n");
            }
            else
                printf("TRUE\n");
            break;
            
            //delete a node from the tree.
        case 'd':
            scanf("%d", &input_int);
            *node = &input_int;
            int flag = BSTRemoveElement(&root, &input_int);
            if( flag == ROOT){
                return 0;
                }
            if( flag == BAD_ARGS){
                printf("FALSE");
            }

            break;
            
            //print the tree.
        case 'p':
            PrintBST(root);
            break;
            
            //delete the tree and exit.
        case 'e':
            //BSTDestroy(root);
            return 0;
            
        default:
            break;
    }
    Menu_int(root,node,MaxRank);
    
    return 0;
}


/****POINT FUNCTIONS****/
/******************************************************************************
 * function name: create_point.
 * The Input: None.
 * The output: Pointer to allocated Ddnamic memory.
 * The Function operation: Allocates memory to pointer, returns the pointer.
 * ****************************************************************************/
Elm create_point(){
    //alocating memorey for root.
    POINT * point = (POINT*)malloc(2*sizeof(POINT));
    if(point == NULL){
        free(point);
    }
    return point;
}
/******************************************************************************
 * function name: cpy_point.
 * The Input: Pointer to allocated memory and thr tree input value.
 * The output: None.
 * The Function operation: Copyis input to the specifid value on the BST.
 * ***************************************************************************/
void cpy_point(Elm val ,Elm root_val){
    // Assiginig the root point to the allocated (from create) memory.
    *((POINT*)val) = *(POINT*)root_val;
}
/************************************************************************
 * function name: cmp_point.
 * The input: Two Generic pointers to structures of BST_T.
 * The output: Number, depending on function output.
 * The Function operation:
 * *************************************************************************/
int cmp_point(Elm elm1, Elm elm2){
    int x1 = ((POINT*)elm1)->x;
    int y1 = ((POINT*)elm1)->y;
    long double pt1 = (x1*x1)+(y1*y1);
    int x2 = ((POINT*)elm2)->x;
    int y2 = ((POINT*)elm2)->y;
    long double pt2 = (x2*x2)+(y2*y2);
    if (pt1 > pt2){
        return BIGGER;
    }
    else if (pt1 == pt2){
        return SAME;
    }
    else
        return SMALLER;
}
/******************************************************************************
 * function name: free node.
 * The Input: Generic pointer to structure of a node on the BST.
 * The output: None.
 * The Function operation: frees the pointer it gets.
 * ****************************************************************************/
void free_node(Elm node){
    free(node);
    node = NULL;
}
////
void print_point(Elm elm){
    int x = ((POINT*)elm)->x;
    int y = ((POINT*)elm)->y;
    printf("%02d|",x);
    printf("%02d",y);

}
void free_point(Elm node){
    free(node);
}
/************************************************************************
 * function name: AddPoint
 * The Input: Pointer to dynamic allocated memory of type BST_POINT.
 * The output: Pointer to structure 'point'.
 * The Function operation:
 * *************************************************************************/
POINT* AddPoint(POINT*point){
    int x,y;
    char d;
    scanf("%c%c%d%c%d%c)",&d,&d,&x,&d,&y,&d);
    //Assighing input to structure.
    point->x = x;
    point->y = y;
    return point;
}
/************************************************************************
 * function name:
 * The Input:
 * The output:
 * The Function operation:
 * *************************************************************************/
int Menu_point(void *root,POINT**node,int*MaxRank){
    char input;
    scanf("%c", &input);
    switch (input) {
            //add new node to tree.
        case 'a':
            *node = create_point();
            *node = AddPoint(*node);
            if(BSTAddElement(root, *node) == OUT_OF_MEM){
                return OUT_OF_MEM;
            }
            break;
            //find if node input is in tree
        case 's':
            *node = create_point();
            *node = AddPoint(*node);
            if (BSTFindElement(root,*node) == 0) {
                //printf("FALSE");
            }
            else{
                printf("TRUE");
            }
            break;
            
            //delete a node from the tree.
        case 'd':
            *node = create_point();
            *node = AddPoint(*node);
            int flag = BSTRemoveElement(&root,*node);
            if( flag == ROOT ){
                return 0;
            }
            else if (flag == BAD_ARGS){
                printf("FALSE");
            }
            //free(node);
            break;
            
            //print the tree.
        case 'p':
            PrintBST(root);
            break;
            
            //delete the tree and exit.
        case 'e':
            //BSTDestroy(&root);
            return 0;
            
        default:
            break;
    }
    if(!Menu_point(root,node,MaxRank)){
        return 0;
    }
    
    return 0;
}
