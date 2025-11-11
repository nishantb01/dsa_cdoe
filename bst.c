#include <stdio.h>
#include <stdlib.h>

// Define a node
struct node {
    int data;
    struct node *left, *right;
};

// ---------- Create new node ----------
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ---------- Insert ----------
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// ---------- Search ----------
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// ---------- Inorder ----------
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// ---------- Preorder ----------
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// ---------- Postorder ----------
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// ---------- Find Minimum ----------
struct node* findMin(struct node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// ---------- Find Longest Path (Height) ----------
int height(struct node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// ---------- Mirror the BST ----------
void mirror(struct node* root) {
    if (root == NULL)
        return;
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// ---------- Delete a Node ----------
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ---------- MAIN ----------
int main() {
    struct node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n");
        printf("6. Find Min\n7. Height (Longest Path)\n8. Mirror Tree\n9. Delete Node\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("%d found in BST.\n", value);
                else
                    printf("%d not found.\n", value);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6: {
                struct node* minNode = findMin(root);
                if (minNode)
                    printf("Minimum value = %d\n", minNode->data);
                else
                    printf("Tree is empty!\n");
                break;
            }

            case 7:
                printf("Height (Longest Path) = %d\n", height(root));
                break;

            case 8:
                mirror(root);
                printf("BST mirrored successfully!\n");
                break;

            case 9:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Node deleted if it existed.\n");
                break;

            case 10:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
