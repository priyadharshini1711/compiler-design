#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
} *top = NULL;

#define MAX 5

void push();
void pop();
void empty();
void print_top();
void stack_full();
void stack_count();
void destroy();
int st_count();

int main(){
    int choice;
    while(1){
        printf("1. push an element \n");
        printf("2. pop an element \n");
        printf("3. check if stack is empty \n");
        printf("4. check if stack is full \n");
        printf("5. count elements in stack \n");
        printf("6. empty and destroy stack \n");
        printf("7. print top of stack \n");
        printf("8. exit \n");
        scanf("%d", &choice);
        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: empty(); break;
            case 4: stack_full(); break;
            case 5: stack_count(); break;
            case 6: destroy(); break;
            case 7: print_top(); break;
            case 8: exit(0);
            default: printf("wrong choice \n");
        }
    }
}

void push(){
    int val, count;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    count = st_count();
    if(count <= MAX - 1){
        printf("enter the element \n");
        scanf("%d", &val);
        temp->data = val;
        temp->link = top;
        top = temp;
    } else {
        printf("stack is full \n");
    }
}

void pop(){
    struct node *temp;
    if(top==NULL){
        printf("stack is empty \n");
    } else {
        temp = top;
        printf("value popped out is %d \n", temp->data);
        top = top->link;
        free(temp);
    }
}

void empty(){
    if(top==NULL){
        printf("stack is empty \n");
    } else {
        printf("stack is not empty \n");
    }
}

void stack_full(){
    int count  = 0;
    count  = st_count();
    if(count == MAX){
        printf("stack is full \n");
    } else {
        printf("stack is not full \n");
    }
}

int st_count(){
    int count = 0;
    struct node *temp;
    temp = top;
    while(temp!=NULL){
        temp = temp->link;
        count++;
    }
    return count;
}

void stack_count(){
    int count = 0;
    struct node *temp;
    temp = top;
    while(temp!=NULL){
        printf("data : %d\n", temp->data);
        temp = temp->link;
        count++;
    }
    printf("stack size : %d \n", count);
}

void destroy(){
    struct node *temp;
    temp = top;
    while(temp!=NULL){
        pop();
        temp = temp->link;
    }
    printf("stack destroyed \n");
}

void print_top(){
    if(top == NULL){
        printf("stack is empty \n");
    }else{
        printf("top : %d \n", top->data);
    }
}

/*
output:
1. push an element
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
5
stack size : 0 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
2
stack is empty 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
3
stack is empty 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
7
stack is empty 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
1
enter the element 
10
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
1
enter the element 
20
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
1
enter the element 
30
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
1
enter the element 
40
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
1
enter the element 
50
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
5
data : 50
data : 40
data : 30
data : 20
data : 10
stack size : 5 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
4
stack is full 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
2
value popped out is 50 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
2
value popped out is 40 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
2
value popped out is 30 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
6
value popped out is 20 
value popped out is 10 
stack destroyed 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
1
enter the element 
25
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
55
wrong choice 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
5
data : 25
stack size : 1 
1. push an element 
2. pop an element 
3. check if stack is empty 
4. check if stack is full 
5. count elements in stack 
6. empty and destroy stack 
7. print top of stack 
8. exit 
8
*/