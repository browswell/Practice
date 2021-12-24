#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Pivot takes in the array, the index being pivoted, the start and end indexes
//Pivot returns the sorted index of the pivot
int pivot(int input[], int start, int end){
	int p = input[end];

	int i = start - 1;
//        std::cout << "Pivoting on " << start << " " << end << "\n";
	for(int j = start; j <= end - 1; j++){
		if(input[j] <= p){
			i++;
			swap(&input[i], &input[j]);

		}
	}
	swap(&input[i+1], &input[end]);
	return(i+1);

}

//Quicksort takes in the array, the start and the end indexes
//

void quicksort(int input[], int start, int end){

	if(start < end){

		int p_index = pivot(input, start, end);

		quicksort(input, start, p_index - 1);
		quicksort(input, p_index + 1, end);
	}
}

int main(){
    //Here we're just going to drive some test cases in, and see what the output looks like.
    //Since we control what the file structure of the test cases are, let's just assume that the list is on a single line, comma delimited.
    //Different test cases will be on a new line.
    //And since the point of this is to test the sort, and not to test OS compatibility, assume newline ends with \n

    std::fstream testfile;
    testfile.open("test.csv");
    
    std::vector<std::string> row;
    std::string line, word;

    while (!testfile.eof()){
        row.clear();

        getline(testfile, line);
	std::stringstream s;
        s << line;
        while(std::getline(s, word, ',')){
            row.push_back(word);
        }

        int row_size = row.size();
//	//std::cout << row_size;
        int *arr = new int[row_size];
        for(int i = 0; i < row_size; i++){
            arr[i] = std::stoi(row[i]);
	    if(i != row_size - 1){
    	        std::cout << arr[i] << ",";
	    }
        }
	std::cout << arr[row_size - 1] << "\n";

        quicksort(arr, 0, row_size - 1);

        for(int i = 0; i < row_size - 1; i++){
	    std::cout << arr[i] << ",";
        }
	std::cout << arr[row_size - 1] << "\n";
        
    }
    return(0);
}

