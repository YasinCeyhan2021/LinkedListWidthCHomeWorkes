#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Stack dolu mu?
int is_full(){
    return top == MAX_SIZE - 1;
}

// Stack bo� mu?
int is_empty(){
    return top == -1;
}

// Eleman ekleme (push)
void push(int veri){
    if(is_full()){
        printf("Stack dolu!\n");
    } else {
        stack[++top] = veri;
        printf("%d eklendi.\n", veri);
    }
}

// Eleman ��karma (pop)
int pop(){
    if(is_empty()){
        printf("Stack bo�!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// En �stteki eleman� g�sterme (peek)
int peek(){
    if(is_empty()){
        printf("Stack bo�!\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Stack i�eri�ini g�ster
void display(){
    if(is_empty()){
        printf("Stack bo�!\n");
    } else {
        printf("Stack: ");
        for(int i = top; i >= 0; i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int islem, veri;
    printf("1 - Push\n2 - Pop\n3 - Peek\n4 - G�ster\n0 - ��k\n");

    while(1){
        printf("\n��lem numaras�: ");
        scanf("%d", &islem);

        switch(islem){
            case 1:
                printf("Veri gir: ");
                scanf("%d", &veri);
                push(veri);
                break;
            case 2:
                veri = pop();
                if(veri != -1)
                    printf("��kar�lan veri: %d\n", veri);
                break;
            case 3:
                veri = peek();
                if(veri != -1)
                    printf("En �stteki veri: %d\n", veri);
                break;
            case 4:
                display();
                break;
            case 0:
                return 0;
            default:
                printf("Ge�ersiz i�lem numaras�!\n");
        }
    }

    return 0;
}

