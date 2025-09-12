#include <iostream>
using namespace std;
int main(){
    string x[2]={"双","单"};
    string y[2]={"小","大"};
    int input[4];
    for (int i=0;i<4;i++){
        cin>>input[i];
    }
    string a[4];
    string b[4];
    for (int i=0;i<4;i++){
        if (input[i]%2==0) {
            a[i]=x[0];
        } else {
            a[i]=x[1];
        }
        if (input[i]>=0&&input[i]<5) {
            b[i]=y[0];
        } else {
            b[i]=y[1];
        }
    }
    for (int i=0;i<4;i++) {
        cout<<a[i]<< " ";
    }
    cout<<endl;
    for (int i=0;i<4;i++) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}