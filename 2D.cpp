#include<iostream>
using namespace std;

const int r=2;
const int c=2;
void fun(int arr[r][c]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}









int main(){
	int arr[2][2]={
		{1,2},
		{3,4}
		
	};
	fun(arr);
	return 0;
}
	
