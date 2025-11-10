#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node*left,*right;
};
struct Node* createNode(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;

}
struct Node* insert(struct Node*root,int value){
    if(root==NULL){
        root=createNode(value);
        return root;
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }
        else if(value>root->data)
            root->right=insert(root->right,value);
        
        return root;
}
void inorder(struct Node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    struct Node*root=NULL;
    int n,value;
    printf("Enter number of nodes:");
          scanf("%d",&n);
      printf("Enter values:\n");
      
      for(int i=0;i<n;i++){
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("\nInorder Traversal of BST:");
    inorder(root);
    return 0;
}
