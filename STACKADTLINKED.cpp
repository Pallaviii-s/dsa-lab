//Stack adt using a singly linked list
#include <iostream>
#include <cstdio>
using namespace std;

class list{
    private:
    struct node{
        int data;
        node* next;
    }*top;
    public:
    list(){
        top=nullptr;
    }
    void push(int);
    void pop();
    void peek();
};

int main(){
    int value,choice;
    list list1;
    do{
        cout<<"\n MENU \n1.Push \n2.Pop \n3. Peek \n4.Exit \n ";
        cout<<"Enter choice:  \n";
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"Enter element to be pushed in stack: \n";
                cin>>value;
                list1.push(value);
                break;
            case 2:
                list1.pop();
                break;
            case 3:
                list1.peek();
                break;
            case 4:
                cout<<"Exiting operation..... \n";
                break;
            default:
                "Invalid input. \n";
                break;
        }
    }while(choice!=4);
    return 0;
}

//Pushing element into the stack.
void list::push(int value){
    node* newnode=(node*)malloc(sizeof(node));
    if(!newnode){
        cout<<"Mmeory allocation failed";
        return;
    }
    newnode->data=value;
    newnode->next=top;
    top=newnode;
}

//Deleting the topmost element of stack
void list::pop(){
    if(top==NULL){
        cout<<"Stack underflow";
        return;
    }
    cout<<top->data;
    node* temp=top;
    top=top->next;
    free(temp);
    
}

// Displaying the top element of stack
void list::peek(){
    if(top==NULL){
        cout<<"Stack  underflow";
        return;
    }
    cout<<"The topmost element is: "<<top->data;
}

