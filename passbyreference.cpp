#include<iostream>
using namespace std;

void update(int x){
	x=x+10;}


int main(){
	int val=10;
	cout<<"Val before changes: "<<val<<endl;
	update(val);
		cout<<"Val after changes: "<<val<<endl;
		
	return 0;
}
