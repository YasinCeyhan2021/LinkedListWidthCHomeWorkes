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
        printf("\n\n--------------- Linked List ---------------\n\n");
        while (temp != NULL) {
            printf("%d %p\n", temp->data, (void *)temp->next);
            temp = temp->next;
        }
        printf("\n\n------------------------------------------\n\n");
    }
}

node *function2(node *head, int sil) {
    if (head == NULL) {
        printf("Head boş\n");
        return head;
    }

    node *temp = head;

    if (head->data == sil) {
        head = head->next;
        free(temp);
        return head;
    }

    while (temp->next != NULL) {
        if (temp->next->data == sil) {
            node *temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main() {
	setlocale(LC_ALL, "Turkish"); 
    node *Head2 = NULL;

    Head2 = end_add_node(Head2, 1);
    Head2 = end_add_node(Head2, 3);
    Head2 = end_add_node(Head2, 7);
    Head2 = end_add_node(Head2, 4);
    Head2 = end_add_node(Head2, 3);
    Head2 = end_add_node(Head2, 7);
    Head2 = end_add_node(Head2, 2);

    Head2 = function2(Head2, 7); // İlk 7 silinir
    write_node(Head2);

    return 0;
}

