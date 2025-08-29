#include<iostream>
using namespace std;

int st[100];
int top = -1;

void push(){
    int val;
    if(top==99){
        cout << "Stack is full";
    }
    else{
        cout << "Enter the value: ";
        cin >> val;
        top++;
        st[top] = val;
        cout << val << " pushed into stack\n";
    }
}

void pop(){
    if(top==-1){
        cout << "stack is empty\n";
    }
    else{
        cout << st[top] << "popped from stack\n";
        top--;
    }
}

void isEmpty(){
    if(top==-1){
        cout << "stack is empty\n";
    }
    else{
        cout << "Stack is not Empty\n";
    }
}

void isFull(){
    if(top==99){
        cout << "Stack is full\n";
    }
    else{
        cout << "Stack is not Full\n";
    }
}

void display(){
    if(top==-1){
        cout << "Nothing to Display Stack is Empty\n";
    }
    else{
        cout << "Stack(top to bottom):\n";
        for(int i=top; i>=0; i--){
            cout << st[i] << " ";
        }
    }
}

void peek(){
    if(top==-1){
        cout << "Stack is empty";
    }
    else{
        cout << st[top] << "is the peek";
    }
}

int main(){
    int choice;
    do{
        cout << "\n    Stack Menu    \n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. peek\n7. Exit\n";
        cout << "Enter your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: push(); break;
            case 2: pop() ; break;
            case 3: isEmpty() ; break;
            case 4: isFull() ; break;
            case 5: display() ; break;
            case 6: peek() ; break;
            case 7: cout << "Exiting....\n" ; break;
            default: cout << "Invalid choice! Try again\n";
        }
    } while(choice != 7);

    cin.ignore();
    cin.get();
    return 0;
}