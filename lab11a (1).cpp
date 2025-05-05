//Menu Driven Program to implement HashADT with Linear Probing
#include<cstdio>

const int TABLE_SIZE=10;
const int EMPTY=-1;
const int DELETED=-2;
class HashTable{
    private:
    int table[TABLE_SIZE];
    int hash(int key){
        return key%TABLE_SIZE;
    }
    public:
    HashTable(){
        for(int i=0;i<TABLE_SIZE;i++){
            table[i]=EMPTY;
        }
    }
    void insert(int);
    void remove(int);
    void search(int);
    void display();

};

int main(){
    HashTable ht;
    int choice;
    int target;
    int data;
    do{
        printf("\nMenu Driven Program:\n");
        printf("1)Insert\n2)Delete\n3)Search\n4)Display\n5)Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
    switch(choice){
    case 1:
    printf("Enter the key you want to insert in the hashtable: ");
    scanf("%d",&data);
    ht.insert(data);
    break;
    case 2:
    printf("Enter the key you want to delete from the hashtable: ");
    scanf("%d",&data);
    ht.remove(data);
    break;
    case 3:
     printf("Enter the key you want to search in the hashtable: ");
    scanf("%d",&data);
    ht.search(data);
    break;
    case 4:
    ht.display();
    break;
    case 5:
    printf("Exiting Program...\n");
    return 0;
    default:
    printf("Enter a valid choice: ");
    break;
    }
}while(choice!=5);
}


//Function to insert a key to the hashtable
void HashTable::insert(int key){
    int index=hash(key);
    int startindex=index;
    bool inserted=false;
    do{
        if(table[index]==EMPTY||table[index]==DELETED){
            table[index]=key;
            inserted=true;
            printf("%d is inserted at index %d.",key,index);
            return;
        }
        index=(index+1)%TABLE_SIZE;
    }while(index!=startindex);
    if(!inserted){
        printf("Hash Table is full.Cannot insert.\n");
    }
}

//Function to remove a key from the hashtable
void HashTable::remove(int key){
    int index=hash(key);
    int startindex=index;
    do{
        if(table[index]==key){
            table[index]=DELETED;
            printf("%d is deleted from index %d.",key,index);
            return;
        }
        if(table[index]==EMPTY){
            break;
        }
        index=(index+1)%TABLE_SIZE;
    }while(index!=startindex);
    printf("%d is not found in the hashtable.",key);
}

//Function to Search for a key in the hashtable
void HashTable::search(int key){
    int index=hash(key);
    int startindex=index;
    do{
        if(table[index]==key){
            printf("%d is found at index %d.",key,index);
            return;
        }
        if(table[index]==EMPTY){
            break;
        }
        index=(index+1)%TABLE_SIZE;
    }while(index!=startindex);
    printf("%d is not found in the hashtable.",key);
}

//Function to display the elements of the HashTable
void HashTable::display(){
    printf("\n---HASH TABLE---\n");
    for(int i=0;i<TABLE_SIZE;i++){
        if(table[i]==EMPTY){
            printf("[%d]:EMPTY\n",i);
        }
        else if(table[i]==DELETED){
            printf("[%d]:DELETED\n",i);
        }
        else{
            printf("[%d]:%d\n",i,table[i]);
        }
    }
}