#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Stack dolu mu?
int is_full(){
    return top == MAX_SIZE - 1;
}

// Stack boþ mu?
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

// Eleman çýkarma (pop)
int pop(){
    if(is_empty()){
        printf("Stack boþ!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// En üstteki elemaný gösterme (peek)
int peek(){
    if(is_empty()){
        printf("Stack boþ!\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Stack içeriðini göster
void display(){
    if(is_empty()){
        printf("Stack boþ!\n");
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
    printf("1 - Push\n2 - Pop\n3 - Peek\n4 - Göster\n0 - Çýk\n");

    while(1){
        printf("\nÝþlem numarasý: ");
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
                    printf("Çýkarýlan veri: %d\n", veri);
                break;
            case 3:
                veri = peek();
                if(veri != -1)
                    printf("En üstteki veri: %d\n", veri);
                break;
            case 4:
                display();
                break;
            case 0:
                return 0;
            default:
                printf("Geçersiz iþlem numarasý!\n");
        }
    }

    return 0;
}

