#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int value) {
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;  
    node->left = node->right = NULL; 
    return node;
}

struct Node *insert(struct Node *root, int value) {
	if(root == NULL) {
		return newNode(value);
	}
	
	if(value < root->data) {
		root->left = insert(root->left, value);
	} else if(value > root->data) {
		root->right = insert(root->right, value);
	}
	
	return root;
}

void postOrderTraversal(struct Node *root) {
    if(root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
	int n;
    scanf("%d", &n);

    struct Node *root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }

    postOrderTraversal(root);
	
	return 0;
}
