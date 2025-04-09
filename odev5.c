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

int function5(node *head, int sayi) {
    int sira = 0;
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == sayi) {
            return sira;
        }
        sira++;
        temp = temp->next;
    }
    return -1;  // eleman bulunamadıysa
}

int main() {
    node *Head5 = NULL;
    Head5 = end_add_node(Head5, 2);
    Head5 = end_add_node(Head5, 4);
    Head5 = end_add_node(Head5, 5);
    Head5 = end_add_node(Head5, 8);
    Head5 = end_add_node(Head5, 1);
    Head5 = end_add_node(Head5, 5);
    Head5 = end_add_node(Head5, 3);

    write_node(Head5);
    printf("\nFunction5 (4'ün sırası) : %d\n", function5(Head5, 4));

    return 0;
}

