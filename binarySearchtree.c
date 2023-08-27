#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}*nn,*root=NULL;

struct TreeNode *createNode(int data) {
    nn = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

struct TreeNode *insert(struct TreeNode *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } 
    
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

void inOrderTraversal(struct TreeNode *root) {
    if (root != NULL) {
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct TreeNode *root) {
    if (root != NULL) {
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct TreeNode *root) {
    if (root != NULL) {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
    }
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. In-order traversal\n");
    printf("3. Pre-order traversal\n");
    printf("4. Post-order traversal\n");
    printf("5. Exit\n");
}

int main() {
    int choice, data;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
             case 1:
             printf("Enter the data to insert: ");
             scanf("%d", &data);
             root = insert(root, data);
             break;
             
             case 2:
             printf("In-order traversal: ");
             inOrderTraversal(root);
             printf("\n");
             break;
             
             case 3:
             printf("Pre-order traversal: ");
             preOrderTraversal(root);
             printf("\n");
             break;
             
             case 4:
             printf("Post-order traversal: ");
             postOrderTraversal(root);
             printf("\n");
             break;
             
             case 5:
             printf("Exiting the program...\n");
             break;
             
             default:
             printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}




