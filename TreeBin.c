#include <stdio.h>
#include <stdlib.h>
#include "TreeBin.h"

Node* TreeInitit(){
    return NULL;
}

void FreeTree(Node *root){
    if(root != NULL){
        FreeTree(root->left);
        FreeTree(root->right);
        free(root);
    }
}

Node* InsertNode(Node *root, int value){
    if(root == NULL){
        Node *node = malloc(sizeof(Node));
        node->info = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }else{
        if(value > root->info)
            root->right = InsertNode(root->right, value);
        else if(value < root->info)
            root->left = InsertNode(root->left, value);
    }
    return root;
}

Node* RemoveNode(Node *root, int value){
    if(root == NULL){
        return;
    }else{
        if(value > root->info)
            root->right = RemoveNode(root->right, value);
        else if(value < root->info)
            root->left = RemoveNode(root->left, value);
        else{
            if(root->left == NULL && root->right == NULL){
                printf("Esse valor: %d, estamos atras de: %d\n", root->info, value);
                free(root);
                return NULL;
            }
            else if(root->left != NULL && root->right == NULL){
                Node *node = malloc(sizeof(Node));
                node = root->left;
                free(root);
                return node;
            }
            else if(root->left == NULL && root->right != NULL){
                Node *node = malloc(sizeof(Node));
                node = root->right;
                free(root);
                return node;
            }
            else if(root->left != NULL && root->right != NULL){
                Node *maxDir = malloc(sizeof(Node));
                maxDir = root->left;
                while(maxDir->right != NULL)
                    maxDir = maxDir->right;

                int aux = maxDir->info;
                root = RemoveNode(root, aux);
                root->info = aux;
                return root;
            }
        }
    }
}

void Path(Node* root, int start, int finish){
    if(root != NULL){
        if(finish == root->info)
            printf("%d", root->info);
        else{
            if(start > root->info)
                Path(root->right, start, finish);
            else if(start < root->info)
                Path(root->left, start, finish);
            else{
                printf("%d ", root->info);
                if(finish > root->info)
                    Path(root->right, root->right->info, finish);
                else
                    Path(root->left, root->left->info, finish);
            }
        }
    }
}

int Height(Node *root){
    if(root == NULL)
        return 0;
    int hleft = 0, hright = 0;
    if(root->left != NULL)
        hleft = Height(root->left);
    if(root->right != NULL)
        hright = Height(root->right);
    if(hleft > hright)
        return hleft + 1;
    return hright + 1;
}

void PreOrder(Node *root){
    if(root != NULL){
        printf("%d\n", root->info);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PosOrder(Node *root){
    if(root != NULL){
        PosOrder(root->left);
        PosOrder(root->right);
        printf("%d\n", root->info);
    }
}
