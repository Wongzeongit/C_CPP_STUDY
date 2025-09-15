#include <iostream>
using namespace std;
int main() {
    int i=0;
    cin>>i;
    long long n=i*i*i;
    for (int j=1;j<=n;j+=2) {
        int a=0;
        for (int k=j;a<=n;k+=2) {
            a+=k;
            if (a==n) {
                cout<<n<<"=";
                for (int l=j;l<=k;l+=2) {
                    cout<<l;
                    if (l<k) cout<<"+";
                    else cout<<endl;
                }
                return 0;
            }
        }
    }
    return 0;
}