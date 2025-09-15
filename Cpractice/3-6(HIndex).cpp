#include <iostream>
using namespace std;
int HIndex(int* cit,int n) {
    int MaxH=0,num=0;
    for (int i=0;i<=n;i++) {
        for (int j=0;j<n;j++) {
            if (cit[j]>=i) num++;
        }
        if (num>=i) MaxH=i;
        num=0;
    }
    return MaxH;
}
int main() {
    int n=0;
    cin>>n;
    int cit[n];
    for (int i=0;i<n;i++) {
        cin>>cit[i];
    }
    cout<<HIndex(cit,n)<<endl;
}