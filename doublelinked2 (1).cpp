//Creating a doubly linked list with a tail and performing operations.
#include <iostream>
#include <cstdio>
using namespace std;


class list{
    private:
        struct node{
            int data;
            node* next;
            node* previous;
        }*head, *tail;
    public:
        list(){
            head=nullptr;
            tail=nullptr;
        }
        void insert_begin(int);
        void insert_end(int);
        void insert_position(int,int);
        void delete_begin();
        void delete_end();
        void delete_position(int);
        void search(int);
        void display();
};
int main(){
    class list list1;
    int value,position,choice;
    do{
        cout<<"\n MENU:\n";
        cout<<"1. Insert at beginning \n";
        cout<<"2. Insert at end \n";
        cout<<"3. Insert at position \n";
        cout<<"4. Delete beginning \n";
        cout<<"5. Delete at the end \n";
        cout<<"6. Delete element at a position \n";
        cout<<"7. Search element \n";
        cout<<"8. Display array\n";
        cout<<"9. Exit \n";
        cout<<"Enter your choice \n";
        cin>>choice;
        
        switch(choice){
            case 1:
                cout<<"Enter the value: ";
                cin>>value;
                list1.insert_begin(value);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>value;
                list1.insert_end(value);
                break;
            
            case 3:
                cout<<"Enter position: ";
                cin>>position;
                cout<<"Enter value: ";
                cin>>value;
                list1.insert_position(position,value);
                break;
            case 4:
                list1.delete_begin();
                break;
            case 5:
                list1.delete_end();
                break;
            case 6:
                cout<<"Enter the position of element to be deleted: \n";
                cin>>position;
                list1.delete_position(position);
                break;
            case 7:
                cout<<"Enter element you want to search: ";
                cin>>value;
                list1.search(value);
                break;
            case 8:
                list1.display();
                break;
            case 9:
                cout<<"Exiting program";
                break;
            default:
                printf("Invalid input \n");
                break;

            }   
}while(choice!=9);
return 0;
}

//Insert at beginning
void list::insert_begin(int value){
    node* newnode=(node*)malloc(sizeof(node));
    if(!newnode){
        cout<<"Memory allocation failed";
        return;
    }
    newnode->data=value;
    newnode->previous=NULL;
    if(!head){
        newnode->next=NULL;
        tail=newnode;
    }
    else{
        newnode->next=head;
        head->previous=newnode;
    }  
    head=newnode;  
}

//Display entire list
void list::display(){
    if(!head){
        cout<<"Empty list \n";
        return;
    }
    //list in forward direction
    cout<<"List in forward: \n";
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    //list in reverse
    temp=tail;
    cout<<"List in reverse: \n";
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->previous;
    }
}


//Insert at the end
void list::insert_end(int value){
    node* newnode= (node*)malloc(sizeof(node));
    if(!newnode){
        cout<<"Memory allocation failed. \n";
        return;
    }
    if(!tail){
        insert_begin(value);
        return;
    }
    newnode->data=value;
    newnode->previous=tail;
    newnode->next=NULL;
    tail->next=newnode;
    tail=newnode;
}

//Insert at a position 
void list::insert_position(int position, int value){
    node* newnode= (node*)malloc(sizeof(node));
    if(!newnode){
        cout<<"Memory allocation failed. \n";
        return;
    }

    if(position<1){
        cout<<"Invalid position. \n";
        return;
    }
    if(position==1){
        insert_begin(value);
        return;
    }
    node* temp=head;
    for(int i=1;temp && i<(position-1);i++){
        temp=temp->next;
    }
    if(temp==tail){
        insert_end(value);
        return;
    }
    newnode->data=value;
    newnode->previous=temp;
    newnode->next=temp->next;
    temp->next->previous=newnode;
    temp->next=newnode;
}

//Delete the element at the beginning
void list::delete_begin(){
    if(!head){
        cout<<"Empty list.";
        return;
    }
    node* temp= head;
    if(head==tail){
        cout<<temp->data<<endl;
        free(temp);
    }
    else{
        head->next->previous=NULL;
        head=head->next;
    }
    cout<<temp->data<<endl;
    free(temp);
}

//Delete the element at the end
void list::delete_end(){
    if(!tail){
        cout<<"Empty list.";
        return;
    }
    node* temp=tail;
    if(head==tail){
        cout<<temp->data<<endl;
        free(temp);
    }
    else{
        tail->previous->next=NULL;
        tail=tail->previous;
    }
    cout<<temp->data<<endl;
    free(temp);
}

//Delete element at a certain position
void list::delete_position(int position){
    if(position<1){
        cout<<"Invalid position. \n";
        return;
    }
    if(position==1){
        delete_begin();
        return;
    }
    node* temp=head;
    for(int i=1; temp && i<position; i++){
        temp=temp->next;
    }
    if(temp==tail){
        delete_end();
        return;
    }
    temp->previous->next=temp->next;
    temp->next->previous=temp->previous;
    cout<<temp->data<<endl;
    free(temp);
}

//Search for a particular element
void list::search(int value){
    if(!head){
        cout<<"Empty list. \n";
        return;
    }
    node* temp=head;
    int pos=0;
    while(temp || temp->next){
        if(temp->data==value){
            cout<<"Element found \n";
            return;
        }
        temp=temp->next;
        pos++;
    }
    cout<<"Element not found \n";
}