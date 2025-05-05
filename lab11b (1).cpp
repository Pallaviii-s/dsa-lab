//Menu Driven Program to implement HashADT with Quadratic Probing
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
            printf("Enter a key to be inserted into the HashTable: ");
            scanf("%d",&data);
            ht.insert(data);
            break;
            case 2:
            printf("Enter a key to be deleted from the HashTable: ")
            scanf("%d",&data);
            ht.remove(data);
            break;
            case 3:
            printf("Enter a key to be searched in the HashTable: ")
            scanf("%d",&data);
            ht.search(data);
            break;
            case 4:
            ht.display();
            break;
            case 5:
            printf("Exiting Program.....\n");
            return 0;
            default:
            printf("Enter a valid choice...\n");
            break;
        }
    }while(choice!=5);
}

//Function yo insert an element into the HashTable
void HashTable::insert(int key){
    int index=hash(key);
   
    bool inserted=false;
    for(int i=0;i<TABLE_SIZE;i++){
        int probeindex=(index+i*i)%TABLE_SIZE;
        if(table[probeindex]==EMPTY||table[probeindex]==DELETED){
            table[probeindex]=key;
            inserted=true;
            printf("%d is inserted at index %d.",key,probeindex);
            return;
        }
        index=(probeindex+1)%TABLE_SIZE;
    }
    if(!inserted){
        printf("Hash Table is full.Cannot insert.");
    }
}

//Function to remove a key from the hashtable
void HashTable::remove(int key){
    int index=hash(key);
    for(int  i=0;i<TABLE_SIZE;i++){
        int probeindex=(index+i*i)%TABLE_SIZE;
        if(table[probeindex]==key){
            table[probeindex]=DELETED;
            printf("%d is deleted from index %d.",key,index);
            return;
        }
        if(table[probeindex]==EMPTY){
            break;
        }
        index=(probeindex+1)%TABLE_SIZE;
    }
    printf("%d is not found in the hashtable.\n",key);
}

//Function to Search for a key in the hashtable
void HashTable::search(int key){
    int index=hash(key);
    for(int  i=0;i<TABLE_SIZE;i++){
        int probeindex=(index+i*i)%TABLE_SIZE;
        if(table[probeindex]==key){
            printf("%d is found at index %d.",key,index);
            return;
        }
        if(table[probeindex]==EMPTY){
            break;
        }
        index=(probeindex+1)%TABLE_SIZE;
    }
    printf("%d is not found in the hashtable.\n",key);
}

//Function to display the elements of the HashTable
void HashTable::display(){
    printf("\n---HASHTABLE---\n");
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
