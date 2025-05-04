#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int findmin(int arr[],int n){
    int found = 0 ;
    int index;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i]==arr[j]){
                index =  i+1 ;
                found = 1;
            }
        }
    }

    if (found==0){
        return 0;
    }
    else{
        return index;
    }
}

int main(){
    int t;
    printf("Enter number of testcases:");
    scanf("%d",&t);
    while (t){
        int n;
        printf("Enter the number of elements:");
        scanf("%d",&n);
        int arr[n];
        for (int i=0;i<n;i++){
            printf("Enter the number:");
            scanf("%d",&arr[i]);
        }
        printf("%d\n",findmin(arr,n));
        t--;
    }
}