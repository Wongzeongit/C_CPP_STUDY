#include  <iostream>
#include <vector>
using namespace std;
int main(){
    for (int a=2;a<=1000;a++){
    	vector<int> b;
	    b.push_back(1);
	    int c=a;
	    for (int i=2;i<=c;){
	    	if (c%i==0) {
	    		c/=i;
	    		b.push_back(i);
	    		if (c==1) break;
			}
			else {
				i++;
			}
		}
		int n=0;
		for (int i:b){
			n+=i;
		}
		if (n==a) cout<<a;
	}
    return 0;
}