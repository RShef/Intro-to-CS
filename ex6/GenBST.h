/******************************************
 * Student name:          Roy Shefi
 * Student ID:            204845929
 * Course Exercise Group:   Mor 05
 * Exercise name:            ex6
 ******************************************/
#ifndef GenBST_h
#define GenBST_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef void* Elm;
typedef void* BST;
typedef void* BST_ROOT;
typedef enum {SUCEESS, OUT_OF_MEM, BAD_ARGS, FAILURE,ROOT } Result;

BST_ROOT BSTCreate( Elm root_val,Elm (*create_elm)(),void (*cpy_elm) (Elm, Elm),
                    int (*cmp_elm) (Elm, Elm),void (*free_elm) (Elm),
                    void print_elm(Elm));

void BSTDestroy (BST_ROOT root);
Result BSTRemoveElement (BST_ROOT root, Elm node);
Result BSTAddElement (BST_ROOT root, Elm node);
Elm BSTFindElement (BST_ROOT root, Elm node);
Elm PrintBST(BST_ROOT root);

#endif /* GenBST_h */
