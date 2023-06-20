#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int N;
    cin>>N;
 
    int A[50];
    int B[50];
    int chk[50]={0,};
 
    for(int i=0; i<N; i++) {
        cin>>A[i];
    }
 
    for(int i=0; i<N; i++) {
        cin>>B[i];
    }
 
    chk[N]={0,};
    sort(A, A+N);
 
    int sum=0;
    for(int i=0; i<N; i++) {
        int temp=0;
        int idx=0;
        for(int i=0; i<N; i++) {
            if(temp<B[i] && chk[i] == 0) {
                temp=B[i];
                idx=i;
            }
        }
        chk[idx] = 1;
        sum+=A[i]*temp;
    }
 
    cout<<sum;
 
    return 0;
}
