#include <stdio.h>
#define max_size 10

int queue[max_size];
int rear = -1;
int front = -1;

int is_full(){
    if(rear == max_size - 1){
        printf("Queue is full\n");
        return 1;
    }
    return 0;
}

int is_empty(){
    if(front == -1 || front > rear){
        printf("Queue is empty\n");
        return 1;
    }
    return 0;
}

void show(){
    if(is_empty())
        return;

    for(int i = front; i <= rear; i++){
        printf("%d", queue[i]);
        if(i != rear)
            printf("-");
    }
    printf("\n");
}

void enqueue(int veri){
    if(!is_full()){
        if(front == -1)
            front = 0;
        queue[++rear] = veri;
        show();
    }
}

int dequeue(){
    if(!is_empty()){
        int item = queue[front++];
        show();
        return item;
    }
    return -1;
}

int main(){
    printf("1 - Veri Ekleme\n2 - Veri Çýkarma\n0 - Çýkýþ\n");
    int islem, veri;
    while(1){
        printf("Ýþlem No giriniz: ");
        scanf("%d", &islem);
        if(islem == 1){
            printf("Veri: ");
            scanf("%d", &veri);
            enqueue(veri);
        }else if(islem == 2){
            dequeue();
        }else if(islem == 0){
            break;
        }else{
            printf("Yanlýþ iþlem numarasý\n");
        }
    }

    return 0;
}

