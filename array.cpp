#include<iostream>
using namespace std;

void fun(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<endl;
	}
}


	





int main(){
int arr[]={1,2,3,};
int size=sizeof(arr)/sizeof(arr[0]);
fun(arr,size);
}
