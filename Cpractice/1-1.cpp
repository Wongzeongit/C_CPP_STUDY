#include  <iostream>
using namespace std;
int main(){
    for (int i=1;i<=100;i++){
        int j=i*i;
        if (i<=10) {
            if (i==j%10) {
                cout<<i<<" "<<j<<endl;
            }
        }
        else if (i>10){
            if (i==j%100) {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    return 0;
}