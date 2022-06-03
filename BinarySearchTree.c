//Binary Search Tree
#include<stdio.h>
#include<stdlib.h>
    struct treeNode {
        int data;
        struct treeNode *left;
        struct treeNode *right;
    };
    struct treeNode *root = NULL;
    // int numberOfNode = 0;
    // insert 
    // delete
    // search
    //traverse

    int insert(int element){
        struct treeNode *child = (struct treeNode*)malloc(sizeof(struct treeNode));

        child -> data = element;
        child -> left = NULL;
        child -> right = NULL;

        if(root == NULL){
            root = child;
        }
        else{
            struct treeNode *temp = root;
            struct treeNode *parent = NULL;
            while(temp != NULL){
                parent = temp;
                if(element == temp -> data){
                    printf("duplicate element \n");
                    return 0;
                }
                else if(element < temp -> data){
                    temp = temp -> left;
                }
                else {
                    temp = temp -> right;
                }
            }
            if(element < parent -> data){
                parent -> left = child;
            }
            else{
                parent -> right = child;
            }

        }
        return 1;

    }

    int search(int element){
        struct treeNode * temp = root;
        int flag = 0;
        while(temp != NULL){
            if(temp -> data == element){
                printf("element found \n");
                flag = 1;
               break;

            }
            else if(element < temp -> data){
                temp = temp -> left;
            }
            else{
                temp = temp -> right;
            }
        }
        return flag;
       
    }
    void preOrder(struct treeNode *subTree){
        //root
        //left
        //right
        if(subTree != NULL){
          printf("%d, ", subTree -> data);
          preOrder(subTree -> left);
          preOrder(subTree -> right);
        }

    }
    void inOrder(struct treeNode *subTree){
        //left
        //root
        //right
        if(subTree != NULL){
            inOrder(subTree -> left);
            printf("%d, ", subTree -> data);
            inOrder(subTree -> right);
        }
    }
    
    
    void main(){
        if(insert(200)){
            printf("node inserted\n");
        }
        else {
            printf("node NOT inserted\n");
        }

        if(insert(100)){
            printf("node inserted\n");
        }
        else {
            printf("node NOT inserted\n");
        }

        if(insert(400)){
            printf("node inserted\n");
        }
        else {
            printf("node NOT inserted\n");
        }

        if(insert(150)){
            printf("node inserted\n");
        }
        else {
            printf("node NOT inserted\n");
        }
        if(insert(200)){
            printf("node inserted\n");
        }
        else {
            printf("node NOT inserted\n");
        }
        if(insert(20)){
            printf("node inserted\n");
        }
        else {
            printf("node NOT inserted\n");
        }
        if(insert(25)){
            printf("node inserted\n");
        }
        else {
            printf("node NOT inserted\n");
        }

        if(search(20)){
            printf("node found\n");
        }
        else{
            printf("node NOT found\n");
        }

        printf("preorder traversal\n");
        preOrder(root);

        printf("In-order traversal\n");
        inOrder(root);
    }
