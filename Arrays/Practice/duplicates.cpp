#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


int duplicates(int arr[], int len){
	int unique = 0;
	for(int i = 0; i < len; i++){
		if(arr[i] != arr[i+1]){
			arr[unique] = arr[i];
			unique++;
		}

	}
	if(arr[unique] != arr[len - 1]){
		arr[unique] = arr[len - 1];
		unique++;
	}
	return(unique);

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

        int count = duplicates(arr, row_size - 1);

        for(int i = 0; i < count - 1; i++){
	    std::cout << arr[i] << ",";
        }
	std::cout << arr[row_size - 1] << "\n";
	std::cout << count << "\n";
        
    }
    return(0);
}

