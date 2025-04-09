#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<locale.h>

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

void function6(node *head, int sayi) {
    if (head == NULL) {
        printf("head boþ");
    } else {
        node *temp = head;
        while (temp != NULL) {
            temp->data += sayi;
            temp = temp->next;
        }
    }
}

int main() {
	setlocale(LC_ALL, "Turkish"); 
    node *Head6 = NULL;
    Head6 = end_add_node(Head6, 1);
    Head6 = end_add_node(Head6, 5);
    Head6 = end_add_node(Head6, 12);
    Head6 = end_add_node(Head6, 9);
    Head6 = end_add_node(Head6, 7);
    Head6 = end_add_node(Head6, 16);

    function6(Head6, 20);  // Listedeki tüm elemanlara 20 ekler
    write_node(Head6);

    return 0;
}

