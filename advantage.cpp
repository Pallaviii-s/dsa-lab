//Program to solve the CodeForces Problem(Lab 9, Q 2, Advantage)

#include <iostream>
#include <vector>
using namespace std;

void solve();

int main(){
    
    ios_base::sync_with_stdio(false); //Unlinks synchronization between C and C++ I/O streams making input and output faster.
    cin.tie(NULL); //Unlinks cin with cout preventing automatic flushing of cout before cin input
    cout.tie(NULL); //Unlinks cout from other output streams for faster execution.
    
    int testcase=0;
    cin>>testcase;
    while(testcase--){
        solve();
    }
    return 0;
}

void solve(){
    int num;
    cin>>num;
    int max1=0;
    int max2=0;
    vector <int> s(num);
    for(int i=0; i<num; i++){
        cin>>s[i];
        if(s[i]>=max1){
            max2=max1;
            max1=s[i];
        }
        else if(s[i]>=max2){
            max2=s[i];
        }
    }

    for(int j=0; j<num; j++){
        if(s[j]==max1){
            cout<<s[j]-max2<<" ";
        }
        else{
            cout<<s[j]-max1<<" ";
        }
    }
    cout<<"\n";
}