#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char name[20];
    char usn[10];
    char branch[5];
    int sem;
    char phno[10];
    struct node* next;
};
typedef struct node* NODE;
NODE create_node() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->next = NULL;
    printf("\n Name: ");
    scanf("%s", temp->name);
    printf("\n USN: ");
    scanf("%s", temp->usn);
    printf("\n Branch: ");
    scanf("%s", temp->branch);
    printf("\n Sem: ");
    scanf("%d", &temp->sem);
    printf("\n Ph no: ");
    scanf("%s", temp->phno);
    return temp;
}
NODE insert_front(NODE head) {
    NODE temp = create_node();
    if (head == NULL)
        return temp;
    else {
        temp->next = head;
        return temp;
    }
}
NODE insert_rear(NODE head) {
    NODE temp = create_node();
    NODE cur;
    if (head == NULL)
        return temp;
    else {
        cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = temp;
    }
    return head;
}
NODE del_front(NODE head) {
    NODE temp;
    if (head == NULL) {
        printf("\n LL is empty ");
        return head;
    }
    temp = head;
    head = head->next;
    free(temp);
    return head;
}
NODE del_rear(NODE head) {
    NODE prev, cur;
    if (head == NULL) {
        printf("\n LL is empty \n");
        return head;
    } else if (head->next == NULL) {
        printf("Deleted USN: %s\n", head->usn);
        free(head);
        return NULL;
    }
    prev = cur = head;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    printf("Deleted USN: %s\n", cur->usn);
    free(cur);
    return head;
}
void display(NODE head) {
    NODE cur = head;
    int count = 0;
    if (head == NULL) {
        printf("\n LL is empty \n");
        return;
    }
    printf("\n Student info: \n");
    while (cur != NULL) {
        printf("Name: %s\t", cur->name);
        printf("USN: %s\t", cur->usn);
        printf("Branch: %s\t", cur->branch);
        printf("Sem: %d\t", cur->sem);
        printf("Ph no: %s\t", cur->phno);
        printf("\n");
        count++;
        cur = cur->next;
    }
    printf("\n The no. of nodes are %d\n", count);
}
void main() {
    NODE head = NULL;
    int choice;
    while (1) {
        printf("\n\n Enter the choice \n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = insert_front(head);
                break;
            case 2:
                head = insert_rear(head);
                break;
            case 3:
                head = del_front(head);
                break;
            case 4:
                head = del_rear(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("\nWrong choice\n");
        }
    }
}




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char name[20];
    char usn[10];
    char branch[5];
    int sem;
    char phno[10];
    struct node* prev;
    struct node* next;
};
typedef struct node* NODE;
NODE create_node() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->prev = NULL;
    printf("\n Name: ");
    scanf("%s", temp->name);
    printf("\n USN: ");
    scanf("%s", temp->usn);
    printf("\n Branch: ");
    scanf("%s", temp->branch);
    printf("\n Sem: ");
    scanf("%d", &temp->sem);
    printf("\n Ph no: ");
    scanf("%s", temp->phno);
    return temp;
}
NODE insert_front(NODE head) {
    NODE temp = create_node();
    if (head == NULL)
        return temp;
    temp->next = head;
    head->prev = temp;
    return temp;
}
NODE insert_rear(NODE head) {
    NODE temp = create_node();
    NODE cur;
    if (head == NULL)
        return temp;
    cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}
NODE del_front(NODE head) {
    NODE temp;
    if (head == NULL) {
        printf("\n LL is empty ");
        return head;
    }
    temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted USN: %s\n", temp->usn);
    free(temp);
    return head;
}
NODE del_rear(NODE head) {
    NODE cur;
    if (head == NULL) {
        printf("\n LL is empty \n");
        return head;
    } else if (head->next == NULL) {
        printf("Deleted USN: %s\n", head->usn);
        free(head);
        return NULL;
    }
    cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->prev->next = NULL;
    printf("Deleted USN: %s\n", cur->usn);
    free(cur);
    return head;
}
void display(NODE head) {
    NODE cur = head;
    int count = 0;
    if (head == NULL) {
        printf("\n LL is empty \n");
        return;
    }
    printf("\n Student info: \n");
    while (cur != NULL) {
        printf("Name: %s\t", cur->name);
        printf("USN: %s\t", cur->usn);
        printf("Branch: %s\t", cur->branch);
        printf("Sem: %d\t", cur->sem);
        printf("Ph no: %s\t", cur->phno);
        printf("\n");
        count++;
        cur = cur->next;
    }
    printf("\n The no. of nodes are %d\n", count);
}
void main() {
    NODE head = NULL;
    int choice;
    while (1) {
        printf("\n\n Enter the choice \n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = insert_front(head);
                break;
            case 2:
                head = insert_rear(head);
                break;
            case 3:
                head = del_front(head);
                break;
            case 4:
                head = del_rear(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("\nWrong choice\n");
        }
    }
}

