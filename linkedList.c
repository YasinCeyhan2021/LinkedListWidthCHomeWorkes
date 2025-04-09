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

node *add_node(node *head, int data, int sira) {
    node *nn = create_node(data);
    if (head == NULL) {
        if (sira == 1)
            return nn;
        else {
            printf("Yanlýþ sýra no\n");
            free(nn);
            return head;
        }
    }

    if (sira == 1) {
        nn->next = head;
        return nn;
    }

    node *temp = head;
    int i;
    for (i = 1; i < sira - 1; i++) {
        if (temp->next == NULL) {
            printf("Yanlýþ sýra no\n");
            free(nn);
            return head;
        }
        temp = temp->next;
    }

    nn->next = temp->next;
    temp->next = nn;
    return head;
}

node *front_add_node(node *head, int data) {
    node *nn = create_node(data);
    nn->next = head;
    return nn;
}

node *end_add_node(node *head, int data) {
    node *nn = create_node(data);
    if (head == NULL)
        return nn;

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nn;
    return head;
}

node *delete_node(node *head, int sira) {
    if (head == NULL) {
        printf("Eleman Yok\n");
        return head;
    }

    if (sira == 1) {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node *temp = head;
    int i; 
    for (i = 1; i < sira - 1; i++) {
        if (temp->next == NULL || temp->next->next == NULL) {
            printf("Yanlýþ sýra no\n");
            return head;
        }
        temp = temp->next;
    }

    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return head;
}

node *del_node(node *head, int eleman) {
    if (head == NULL) {
        printf("Eleman Yok\n");
        return head;
    }

    if (head->data == eleman) {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node *temp = head;
    while (temp->next != NULL && temp->next->data != eleman) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Silmek istediðiniz eleman yok\n");
        return head;
    }

    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return head;
}

void write_node(node *head) {
    if (head == NULL) {
        printf("\nEleman Yok\n");
    } else {
        node *temp = head;
        printf("\n\n--------------- Linked List ---------------\n\n");
        while (temp != NULL) {
            printf("%d -> %p\n", temp->data, temp->next);
            temp = temp->next;
        }
        printf("\n\n------------------------------------------\n\n");
    }
}

int main(void) {
    node *Head = NULL;
    int data, sira, islem, islem2;

    while (1) {
        printf("\n\n--------------- Panel ---------------\n\n");
        printf("1 - Ekle\n2 - Sil\n3 - Goster\n4 - Cikis\nIslem : ");
        scanf("%d", &islem);

        if (islem == 1) {
            printf("\n\n1 - Basa Ekle\n2 - Sona Ekle\n3 - Siraya Ekle\nIslem : ");
            scanf("%d", &islem2);
            printf("Data : ");
            scanf("%d", &data);

            if (islem2 == 1) {
                Head = front_add_node(Head, data);
            } else if (islem2 == 2) {
                Head = end_add_node(Head, data);
            } else if (islem2 == 3) {
                printf("Sira : ");
                scanf("%d", &sira);
                Head = add_node(Head, data, sira);
            } else {
                continue;
            }

        } else if (islem == 2) {
            printf("1 - Sira\n2 - Eleman\nIslem : ");
            scanf("%d", &islem2);

            if (islem2 == 1) {
                printf("Sira : ");
                scanf("%d", &sira);
                Head = delete_node(Head, sira);
            } else if (islem2 == 2) {
                printf("Eleman : ");
                scanf("%d", &data);
                Head = del_node(Head, data);
            } else {
                continue;
            }
        } else if (islem == 3) {
            write_node(Head);
        } else if (islem == 4) {
            break;
        } else {
            continue;
        }
    }

    return 0;
}
