#include<iostream>
using namespace std;

void update(int x=99,int y=90,int z=100){
	cout<<"X: "<<x<<endl;
	cout<<"Y: "<<y<<endl;
	cout<<"Z: "<<z<<endl;
}



int main(){
	int val=10;
	update(10,20);
	cout<<"Val: "<<val<<endl;
	return 0;
}

