#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
#define EMPTY -1

void insert(int hash_table[], int key);
int search(int hash_table[], int key);
void display(int hash_table[]);

int main() {
    int hash_table[TABLE_SIZE];
    int choice, key, index;

    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = EMPTY;
    }

    do {
        printf("\nHashing Menu:\n1. Insert Key\n2. Search Key\n3. Display Hash Table\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a key to insert: ");
                scanf("%d", &key);
                insert(hash_table, key);
                break;
            case 2:
                printf("Enter a key to search: ");
                scanf("%d", &key);
                index = search(hash_table, key);
                if (index != -1) {
                    printf("Key %d found at index %d\n", key, index);
                } else {
                    printf("Key %d not found in the hash table\n", key);
                }
                break;
            case 3:
                display(hash_table);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void insert(int hash_table[], int key) {
    int index = key % TABLE_SIZE;
    int original_index = index;
    int i = 0;

    while (hash_table[index] != EMPTY) {
        if (i >= TABLE_SIZE) {
            printf("Hash table is full! Cannot insert key %d\n", key);
            return;
        }
        index = (original_index + ++i) % TABLE_SIZE;
    }

    hash_table[index] = key;
    printf("Key %d inserted at index %d\n", key, index);
}

int search(int hash_table[], int key) {
    int index = key % TABLE_SIZE;
    int original_index = index;
    int i = 0;

    while (hash_table[index] != EMPTY) {
        if (hash_table[index] == key) {
            return index;
        }
        if (i >= TABLE_SIZE) {
            break;
        }
        index = (original_index + ++i) % TABLE_SIZE;
    }

    return -1;
}

void display(int hash_table[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != EMPTY) {
            printf("Index %d: %d\n", i, hash_table[i]);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}
