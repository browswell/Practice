#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void Merge(int arr[], int begin, int mid, int end){
//    //std::cout << arr;
    //std::cout << "Merge " << begin << " " << mid << " " << end << "\n";
    int left = mid - begin + 1;
    int right = end - mid;

    int *leftarr = new int[left];
    int *rightarr = new int[right];

    int i, j = 0;
    //std::cout <<"Input array ";
    for(int k = begin; k <= end; k++){
	    //std::cout << arr[k] << " ";
    }
    //std::cout << "\n";
    //std::cout << "Sanity " << left << " " <<  arr[begin] << "\n";
    for(i = 0; i < left; i++){
        leftarr[i] = arr[begin+i];
    }
    for(j = 0; j < right; j++){
        rightarr[j] = arr[mid+ 1 +j];
    }

    i = 0;
    j = 0;
    int write = begin;
    //std::cout << "Left: ";
    for(int k = 0; k < left; k++){
	    //std::cout << leftarr[k] << " ";
    }
    //std::cout << "\n";
    //std::cout << "Right: ";
    for(int k = 0; k < right; k++){
	    //std::cout << rightarr[k] << " ";
    }
    //std::cout << "\n";
//    int min_len = left < right?left:right;
    for(; i < left && j < right;){
        if(leftarr[i] <= rightarr[j]){
            arr[write] = leftarr[i];
	    //std::cout << "Index " << write <<" to " << leftarr[i] << "\n";
            i++;
        }
        else{
            arr[write] = rightarr[j];
	    //std::cout << "Index " << write <<" to " << rightarr[j] << "\n";
            j++;
        }
        write++;
    }
    for(;i < left;i++){
        arr[write] = leftarr[i];
        write++;
    }

    for(;j < right;j++){
        arr[write] = rightarr[j];
        write++;
    }
}

void Mergesort(int arr[], int begin, int end){
    if(begin >= end){
        return;
    }
    //std::cout << begin << " " << end << "\n";
    int mid = begin + (end - begin) / 2;
    Mergesort(arr, begin, mid);
    Mergesort(arr, mid+1, end);

    Merge(arr, begin, mid, end);


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

        Mergesort(arr, 0, row_size - 1);

        for(int i = 0; i < row_size - 1; i++){
	    std::cout << arr[i] << ",";
        }
	std::cout << arr[row_size - 1] << "\n";
        
    }
    return(0);
}

