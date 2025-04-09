#include <stdio.h>
#include <stdlib.h>

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

node *function7(node *head, int aranan, int ekle) {
    if (head == NULL) {
        printf("head boş\n");
        return NULL;
    } else {
        node *temp = head;
        while (temp != NULL) {
            if (temp->data == aranan) {
                node *nn = create_node(ekle);
                nn->next = temp->next;
                temp->next = nn;
                temp = nn; // Eklenen düğümden devam et, yoksa aynı düğümde takılır
            }
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    node *Head7 = NULL;

    Head7 = end_add_node(Head7, 2);
    Head7 = end_add_node(Head7, 4);
    Head7 = end_add_node(Head7, 3);
    Head7 = end_add_node(Head7, 2);
    Head7 = end_add_node(Head7, 8);
    Head7 = end_add_node(Head7, 2);
    Head7 = end_add_node(Head7, 1);
    Head7 = end_add_node(Head7, 5);
    Head7 = end_add_node(Head7, 2);

    Head7 = function7(Head7, 2, 10); // 2 değerinden sonra 10 ekle
    write_node(Head7);

    return 0;
}

