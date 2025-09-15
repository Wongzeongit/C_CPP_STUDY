#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<char> col;
	string line;
	getline(cin,line);
	for (char i:line) {
		col.push_back(i);
	}
	int n=col.size();
	vector<vector<char>> matrix(n,vector<char>(n,'0'));
	matrix[0]=col;
	for (int i=1;i<n;i++) {
		col.clear();
		line.clear();
		getline(cin,line);
		for (char i:line) {
			col.push_back(i);
		}
		matrix[i]=col;
	}
	int m=0;
	char flag='0';
	cout<<n<<" ";
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (matrix[i][j]==flag) {
				m++;
			} else {
				cout<<m<<" ";
				m=1;
				if (flag=='0') flag='1';
				else flag='0';
			}
		}
	}
	cout<<m; 
    return 0;
}