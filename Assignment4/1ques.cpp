#include<iostream>
using namespace std;

int que[100];
int front = -1, rear = -1;

void enqueue(){
    int val;
    if(rear==99){
        cout << "Queue is full";
    }
    else{
        cout << "Enter the value: ";
        cin >> val;
        if(front == -1) front = 0;
        rear++;
        que[rear] = val;
        cout << val << " enqueued into queue\n";
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        cout << "Queue is Empty";
    }
    else{
       cout << que[front] << " Dequeued from the Queue\n";
       front++;
    }
}

void isEmpty(){
    if(front == -1 || front > rear){
        cout << "Queue is Empty";
    }
    else{
        cout << "Queue is not Empty";
    }
}
void isFull(){
    if(rear == 99 ){
        cout << "queue is Full";
    }
    else{
        cout << "queue is not Full";
    }
}
void display(){
    if (front == -1 || front > rear) {
        cout << "Queue is Empty!" << endl;
    } 
    else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << que[i] << " ";
        }
    }
}
void peek(){
   if (front == -1 || front > rear) {
        cout << "Queue is Empty!" << endl;
    } 
    else {
        cout << "Front element is: " << que[front] << endl;
    } 
}

int main(){
    int choice;
    do{
        cout << "\n    Queue Menu    \n";
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