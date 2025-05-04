//Program to implement LIST ADT using array size 5.
#include <iostream>
using namespace std;
#define MAX 5
//Defining the class
class List{
//Public can be accessed from outside
    public:

    int size;
    int arr[MAX];
    List(){
        size=0;
    }

    int insertbeginning(int);

    int insertend(int);

    int insertpos(int,int);

    int deletebeginning();

    int deleteend();

    int search(int);

    void display();

};

int main(){
    class List list;
    int choice;
    int val;
    int pos;
    //The Menu loop
    do{
       cout<<"Menu\n";
       cout<<"1. Insert Beginning\n";
       cout<<"2. Insert End\n";
       cout<<"3. Insert Position\n";
       cout<<"4. Delete Beginning\n";
       cout<<"5. Delete End\n";
       cout<<"6. Delete Position\n";
       cout<<"7. Search\n";
       cout<<"8. Display\n";
       cout<<"9. Rotate\n";
       cout<<"10. Exit\n";
       cout<<"Enter your choice:\n";
       cin>>choice;
       //Switching cases according to the menu
       switch(choice){
        
        case 1:
        cout<<"Enter the val you want to insert:\n";
        cin>>val;
        cout<<list.insertbeginning(val)<<"\n";
        break;

        case 2:
        cout<<"Enter the val you want to insert:\n";
        cin>>val;
        cout<<list.insertend(val)<<"\n";
        break;

        case 3:
        cout<<"Enter the val you want to insert:\n";
        cin>>val;
        cout<<"Enter the position (index) where you want to insert:\n";
        cin>>pos;
        cout<<list.insertpos(val,pos)<<"\n";
        break;

        case 4:
        cout<<list.deletebeginning()<<"\n";
        break;

        case 5:
        cout<<list.deleteend()<<"\n";
        break;

        case 7:
        cout<<"Enter the val you want to search:\n";
        cin>>val;
        cout<<list.search(val)<<"\n";
        break;

        case 8:
        cout<<"The list is:\n";
        list.display();
        break;

        case 10:
        cout<<"Exiting...\n";
        break;

        default:
        cout<<"Invalid Option\n";
        break;
        

       }
    }while(choice!=10);
    
}
//Function definition to insert the val in the first position of the list.
int List::insertbeginning(int val){
    if(size==MAX){
        return 0;
    }
    for(int i=size;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=val;
    size++;
    return 1;
}
//Function definition to insert the val in the last position of the list.
int List::insertend(int val){
    if(size==MAX){
        return 0;
        }
    arr[size]=val;
    size++;
    return 1;
}
//Function to insert the val in the desired position/index in the list.
int List::insertpos(int val,int pos){
    if(size==MAX){
        return 0;
        }
    if(pos>=size||pos<0){
        return 0;
    }
    for(int i=size;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=val;
    size++;
    return 1;
}
//Function definition to delete the first element of the list and return the deleted element.
int List::deletebeginning(){
    if(size==0){
        return 0;
        }
    int a=arr[0];
    for(int i=0;i<size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    return a;
}
//Function definition to delete the last element of the list and return the deleted element.
int List::deleteend(){
    if(size==0){
        return 0;
        }
    int a=arr[size-1];
    size--;
    return a;
}

//Function definition to delete an element from a given position.
int List::deletepos(int pos) {
    if (size == 0) {
        return 0; 
    }
    if (pos < 0 || pos >= size) {
        return 0;
    }
    int deletedValue = arr[pos];
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return deletedValue;
}


// Function to rotate the list to the right by k positions using reverse method (O(1) extra space)
void List::rotate(int k) {
    if (size == 0) {
        return;
    }
    k = k % size; 
    if (k == 0) return;
    reverse(arr, arr + size);
    reverse(arr, arr + k);
    reverse(arr + k, arr + size);
}


//Function to search the val asked for and return its index position in the list.
int List::search(int val){
    for(int i=0;i<size;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}
//Function definition to display all the elements of the list.
void List::display(){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
