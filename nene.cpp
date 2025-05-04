//Program to solve the CodeForces Problem(Lab 9, Q 1, Nene's Game)

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
    int el_seq,queries;
    cin>>el_seq>>queries;
    vector <int> a(el_seq);
    for(int i=0;i<el_seq;i++){
        cin>>a[i];
    }
    while(queries--){
        int num;
        cin>>num;
        cout<<min(num,a[0]-1)<<" ";
    }
    cout<<"\n";
}