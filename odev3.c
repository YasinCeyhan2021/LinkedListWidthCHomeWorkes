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

node *function3(node *head, int sil) {
    // Baştaki silinecek elemanlar için
    while (head != NULL && head->data == sil) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    // Ortadaki / sondaki silinecek elemanlar için
    node *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == sil) {
            node *temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}

int main() {
    node *Head3 = NULL;
    Head3 = end_add_node(Head3, 1);
    Head3 = end_add_node(Head3, 3);
    Head3 = end_add_node(Head3, 7);
    Head3 = end_add_node(Head3, 4);
    Head3 = end_add_node(Head3, 3);
    Head3 = end_add_node(Head3, 7);
    Head3 = end_add_node(Head3, 2);

    Head3 = function3(Head3, 7);
    write_node(Head3);

    return 0;
}

