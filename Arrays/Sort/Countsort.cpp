#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


void countsort (int arr[], int len){

	int range = 0;
	int *output = new int[len];
	for(int i = 0; i < len; i++){
		if(arr[i] > range){
			range = arr[i];
		}
	}

	int *count = new int[range + 1];

	for(int j = 0; j < range + 1; j++){
		count[j] = 0;
	}

	for(int i = 0; i < len; i++){
		count[arr[i]]++;
	}

	for(int j = 1; j < range + 1; j++){
		count[j] += count[j-1];
		std::cout << count[j] << " ";
	}
	std::cout << "\n";

	for(int i = len - 1; i >= 0; i--){
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for(int i = 0; i < len; i++){
		arr[i] = output[i];
//		std::cout << output[i] << " ";
	}
//	std::cout<< "\n";
	
	
	return;




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

        countsort(arr, row_size);

        for(int i = 0; i < row_size - 1; i++){
	    std::cout << arr[i] << ",";
        }
	std::cout << arr[row_size - 1] << "\n";
        
    }
    return(0);
}

