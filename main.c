#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insert(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    if (*head == NULL) {
        *head = temp;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        struct Node* last = (*head)->prev;
        last->next = temp;
        temp->prev = last;
        temp->next = *head;
        (*head)->prev = temp;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    do {
        printf("Address: %p, Data: %d\n", temp, temp->data);
        temp = temp->next;
    } while (temp != head);
}

void sortListAddress(struct Node** head) {
    struct Node *current = *head, *index = NULL;
    int temp;
    
    if (*head == NULL)
        return;
    else {
        do {
            index = current->next;
            while (index != *head) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                    
                    if (current == *head) {
                        *head = index;
                    } else if (index == *head) {
                        *head = current;
                    }
                    
                    if (current->next == index) {
                        struct Node *currentPrev = current->prev;
                        struct Node *indexNext = index->next;
                        
                        currentPrev->next = index;
                        index->prev = currentPrev;
                        
                        index->next = current;
                        current->prev = index;
                        
                        current->next = indexNext;
                        indexNext->prev = current;
                    } else {
                        struct Node *currentNext = current->next;
                        struct Node *currentPrev = current->prev;
                        struct Node *indexNext = index->next;
                        struct Node *indexPrev = index->prev;
                        
                        currentPrev->next = index;
                        index->prev = currentPrev;
                        
                        index->next = currentNext;
                        currentNext->prev = index;
                        
                        current->next = indexNext;
                        indexNext->prev = current;
                        
                        indexPrev->next = current;
                        current->prev = indexPrev;
                    }
                    
                    current = index;
                    break;
                }
                index = index->next;
            }
            current = current->next;
        } while (current != *head);
    }
}

void sortListNumber(struct Node** head) {
    struct Node *current = *head, *index = NULL;
    int temp;

    if (*head == NULL) return;

    do {
        index = current->next;
        while (index != *head) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        index = index->next;
        }
        current = current->next;
    } while (current != *head);
}

int main() {
    struct Node* head = NULL;
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; ++i) {
        int data;
        scanf("%d", &data);
        insert(&head, data);
    }
    
    printf("Before sorting:\n");
    printList(head);
    
    sortListAddress(&head);
    sortListNumber(&head);
    
    printf("After sorting:\n");
    printList(head);
    
    return 0;
}