#include <iostream>

int main() {
	    int* array = new int[5]; // Allocate an array of 5 integers
				    
				        // Populate the array
        for (int i = 0; i < 5; ++i) {
               array[i] = i * 10;
		                       }
				     
	// Output the array
	     for (int i = 0; i < 5; i++){
			     std::cout << array[i] << " ";
	     }
	   std::cout << std::endl;
	  delete[] array; // Deallocate the array
	std::cout<<"array deleted"<<std::endl;
	return 0;
}
