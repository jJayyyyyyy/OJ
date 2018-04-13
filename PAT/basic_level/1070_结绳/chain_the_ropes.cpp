#include <iostream>
#include <algorithm>
#define MAX 100004
using namespace std;

int a[MAX]={0};

int main(){
    int n, i, len;
    cin>>n;
    for( i=0; i<n; i++ ){
        cin>>a[i];
    }
    
    sort(a, a+n);
    
    len = a[0];
    for( i=1; i<n; i++ ){
        len = (len + a[i])/2;
    }
    
    cout<<len;
    return 0;
}