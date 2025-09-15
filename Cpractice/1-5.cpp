#include  <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    vector<int> num;
    for (int i=1;i<=100;i++){
    	num.push_back(2020000+i);
	}
	vector<int> A,B;
	for (int i:num) {
		switch(rand()%2){
		case 0:
			LABEL_CASE0:
			if (A.size()==50) goto LABEL_CASE1;
			A.push_back(i);
			break;
		case 1:
			LABEL_CASE1:
			if (B.size()==50) goto LABEL_CASE0;
			B.push_back(i);
			break;
		}
	}
	cout<<"A:"<<endl;
	int n=0;
	for (int i:A){
		cout<<i<<" ";
		n++;
		if(n==8){
			cout<<endl;
			n=0;
		}
	}
	n=0;
	cout<<endl<<"B:"<<endl;
	for (int i:B){
		cout<<i<<" ";
		n++;
		if(n==8){
			cout<<endl;
			n=0;
		}
	}
    return 0;
}