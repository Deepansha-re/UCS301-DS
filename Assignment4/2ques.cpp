#include<iostream>
using namespace std;

int circular_que[100];
int front = -1, rear = -1;

void enqueue(){
    int val;
    if((front == 0 && rear == 99) || (rear+1)%100 == front){
        cout << "Queue is full";
    }
    else{
        cout << "Enter the value: ";
        cin >> val;
        if(front == -1){
            front = rear = 0;
        } else{
            rear = (rear+1) % 100;
        }
        circular_que[rear] = val;
        cout << val << " enqueued into queue\n";
    }
}

void dequeue(){
    if(front == -1){
        cout << "Queue is Empty";
    }
    else{
       cout << circular_que[front] << " Dequeued from the Queue\n";
       if(front==rear){
            front = rear = -1;
        }
        else{
            front = (front+1) % 100;
        }
    }
}

void isEmpty(){
    if(front == -1){
        cout << "Queue is Empty";
    }
    else{
        cout << "Queue is not Empty";
    }
}
void isFull(){
    if((front == 0 && rear == 99) || (rear + 1) % 100 == front){
        cout << "queue is Full";
    }
    else{
        cout << "queue is not Full";
    }
}
void display(){
    if (front == -1) {
        cout << "Queue is Empty!" << endl;
    } 
    else {
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << circular_que[i] << " ";
            if (i == rear) break;
            i = (i + 1) % 100;
        }
    }
}
void peek(){
   if (front == -1) {
        cout << "Queue is Empty!" << endl;
    } 
    else {
        cout << "Front element is: " << circular_que[front] << endl;
    } 
}

int main(){
    int choice;
    do{
        cout << "\n   Circular Queue Menu    \n";
        cout << "1. enqueue\n2. dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. peek\n7. Exit\n";
        cout << "Enter your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue() ; break;
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