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
        printf("\n\n--------------- Linked Link List ---------------\n\n");
        while (temp != NULL) {
            printf("%d %p\n", temp->data, (void *)temp->next);
            temp = temp->next;
        }
        printf("\n\n-----------------------------------\n\n");
    }
}

int function4(node *head, int aranan) {
    int sayac = 0;
    if (head == NULL) {
        printf("head boş");
        return -1;
    }
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == aranan) {
            sayac++;
        }
        temp = temp->next;
    }
    return sayac;
}

int main() {
    node *Head4 = NULL;
    Head4 = end_add_node(Head4, 1);
    Head4 = end_add_node(Head4, 3);
    Head4 = end_add_node(Head4, 7);
    Head4 = end_add_node(Head4, 4);
    Head4 = end_add_node(Head4, 3);
    Head4 = end_add_node(Head4, 7);
    Head4 = end_add_node(Head4, 2);

    write_node(Head4);
    printf("\nFunction4 (10 sayısı adedi): %d\n", function4(Head4, 10));

    return 0;
}

