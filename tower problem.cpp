// A program that ensures that the first tower contains the greatest number of testcases 
#include<cstdio>

void insertion_sort(int array[], int length);//sorting all the elements of the array except the first one (arr[0])
int solve();//Ensures that the first tower has the greatest number of blocks

int main(){
    int test_cases;
    int buffer;
    printf("Enter the number of test cases: ");
    scanf("%d",&test_cases);
    int i=1;
    while (test_cases!=0){
        printf("%d\n",test_cases);
        buffer=solve();
        printf("The largest element of %d th tower is %d\n",i,buffer);
        test_cases--;
        i++;
    }

}

int solve(){
    int size;
    printf("Enter the number of towers: ");
    scanf("%d",&size);//Obtains the number of blocks

    int arr[size];
    int blocks;
    //The array contains the number of blocks in each tower
    for (int i=0;i<size;i++){
        printf("Enter the value of each block: ");
        scanf("%d",&blocks);
        arr[i]=blocks;
    }

    //To make sure that the first tower contains the greatest number of blocks
    insertion_sort(arr,size);
    
    //decrementing and incrementing the values accordingly
    int first=arr[0];
    int next;
    for (int i=1;i<size;i++){
        next=arr[i];
        while(first<next){
            first++;
            next--;
        }
    }
    return first;
}
//sorting all the elements of the array except the first one (arr[0])
void insertion_sort(int array[], int length){
    int temp;
    int data;
    int j;
    
    for (int i=2;i<length;i++){
        temp=array[i];
        j=i-1;
        while (j>=1 && temp<=array[j]){
            data=array[j+1];
            array[j+1]=array[j];
            array[j]=data;
            j--;
        }
        array[j+1]=temp;
    }
}