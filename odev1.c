#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *create_node(int veri) {
    node *nn = (node *)malloc(sizeof(node));
    nn->data = veri;
    nn->next = NULL;
    return nn;
}

node *end_add_node(node *head, int data) {
    node *nn = create_node(data);
    if (head == NULL) {
        return nn;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
        return head;
    }
}

void write_node(node *head) {
    if (head == NULL) {
        printf("\nEleman Yok\n");
    } else {
        node *temp = head;
        printf("\n\n--------------- Linked List ---------------\n\n");
        while (temp != NULL) {
            printf("%d %p\n", temp->data, (void *)temp->next);
            temp = temp->next;
        }
        printf("\n\n------------------------------------------\n\n");
    }
}

bool function1(node *head, int aranan) {
    if (head == NULL) {
        printf("head boþ");
        return false;
    } else if (head->data == aranan) {
        return true;
    } else {
        node *temp = head;
        while (temp != NULL) {
            if (temp->data == aranan) {
                printf("Bulundu: %d\n", temp->data);
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}

int main() {
    node *Head1 = NULL;
    Head1 = end_add_node(Head1, 1);
    Head1 = end_add_node(Head1, 4);
    Head1 = end_add_node(Head1, 2);
    Head1 = end_add_node(Head1, 5);

    write_node(Head1);
    printf("\nFunction1 sonucu: %d\n", function1(Head1, 5)); // true -> 1

    return 0;
}

