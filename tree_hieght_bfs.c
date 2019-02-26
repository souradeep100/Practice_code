#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node * left;
    struct node * right;
};
typedef struct node Node;

Node* insert(Node * root,int data) {
    if (root==NULL) {
        root = malloc(sizeof(Node));
        root->val = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else {
        if(data > root->val) {
            root->right = insert(root->right,data);
        }
        else {
            root->left = insert(root->left,data);
        }
        
    }
    return root;
}
int height(Node * root) {
    int ldepth;
    int rdepth;
    if(root==NULL) {
            return 0;
        }
    else {
        ldepth=height(root->left);
        printf("ldepth %d val %d",ldepth,root->val);
        rdepth=height(root->right);
        printf("rdepth %d val %d",rdepth,root->val);
        if (ldepth>rdepth)
            return (ldepth+1);
        else
        {
            return(rdepth+1);
        }
        
    }
}
int size(Node * root) {
    if(root==NULL){
        return 0;
    }
    else {
        return (size(root->left)+1+size(root->right));
    }
}

Node *tree_mirror(Node * root) {
    Node * new1=NULL;
    if(root==NULL) {
        return NULL;
    }
    else {
        new1 =  malloc(sizeof(Node));
        new1->val = root->val;
        new1->left=tree_mirror(root->right);
        new1->right=tree_mirror(root->left);
    }
    return new1;
}
int visited_nodes[10];
int top=0;
void root_to_leaves(Node *root) {
    int i=0;
    visited_nodes[top]=root->val;
    top++;
        
    if((root->left==NULL) && (root->right==NULL)) {
        
        for(i=0;i<top;i++) {
            printf("%d ",visited_nodes[i]);
        }
        
        return;
    }
    else {
        if(root->left!=NULL) {
            root_to_leaves(root->left);
            top--;
        }
        if(root->right!=NULL) {
            root_to_leaves(root->right);
            top--;
        }
        
    }

}
main() {
    Node * root=NULL,*root1=NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,22);
    root = insert(root,14);
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,11);
    root = insert(root,3);
    printf("height %d size %d ",height(root),size(root));
    root_to_leaves(root);
    root1 = tree_mirror(root);
    printf("mirror\n");
    root_to_leaves(root1);
}