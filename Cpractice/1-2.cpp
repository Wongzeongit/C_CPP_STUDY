#include  <iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    cout<<a<<"=";
    for (int i=2;i<=a;){
    	if (a%i==0) {
    		cout<<i;
    		a/=i;
    		if (a==1) break;
    		else {
				cout<<"*";
			}
		}
		else {
			i++;
		}
	}
    return 0;
}