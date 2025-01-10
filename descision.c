#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int info;
    struct tnode* llink;
    struct tnode* rlink;
};

typedef struct tnode* TNODE;

TNODE get_node() {
    TNODE temp;
    temp = (TNODE)malloc(sizeof(struct tnode));
    temp->llink = temp->rlink = NULL;
    return temp;
}

TNODE insert(TNODE root, int ele) {
    if (root == NULL) {
        TNODE temp = get_node();
        temp->info = ele;
        return temp;
    }
    if (ele < root->info)
        root->llink = insert(root->llink, ele);
    else if (ele > root->info)
        root->rlink = insert(root->rlink, ele);
    return root;
}

void preorder(TNODE root) {
    if (root != NULL) {
        printf("%d\t", root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void inorder(TNODE root) {
    if (root != NULL) {
        inorder(root->llink);
        printf("%d\t", root->info);
        inorder(root->rlink);
    }
}

void postorder(TNODE root) {
    if (root != NULL) {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t", root->info);
    }
}

int search(TNODE root, int key) {
    if (root != NULL) {
        if (root->info == key)
            return key;
        else if (key < root->info)
            return search(root->llink, key);
        else
            return search(root->rlink, key);
    }
    return -1;
}

void main() {
    TNODE root = NULL;
    int choice, ele, key;

    for (;;) {
        printf("\nEnter your choice: \n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &ele);
                key = search(root, ele);
                if (key == -1)
                    printf("Key not found\n");
                else
                    printf("Key found\n");
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\nInorder: ");
                inorder(root);
                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
}
