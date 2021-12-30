#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <list>

struct node{
	int index;
	int data;
	node *left;
	node *right;
};


void traverse(node *tree, int s, int type){
	if(tree != NULL){
		
		if(type == 0){
			std::cout << tree->data << "\n";
			traverse(tree->left, s,0);
			traverse(tree->right, s,0);
		}
		else if(type == 1){
			traverse(tree->left, s,1);
			std::cout << tree->data << "\n";
			traverse(tree->right, s,1);
		}
		else if(type == 2){
			traverse(tree->left, s, 2);
			traverse(tree->right, s, 2);
			std::cout << tree->data << "\n";
		}
		
	}
}




node* create_tree(int *arr, int row_size, int index){
	if(index < row_size){
		node *root = new node();
		root->data = arr[index];
		root->index = index;
		root->left = create_tree(arr, row_size, index*2 + 1);
		root->right = create_tree(arr, row_size, index*2 + 2);
		return(root);
	}
	else{
		return(NULL);
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

	node *root = create_tree(arr, row_size, 0);
	std::cout << "prefix" << "\n";
	traverse(root, 3, 0);
	std::cout << "infix" << "\n";
	traverse(root, 3, 1);
        std::cout << "postfix" << "\n";
	traverse(root, 3, 2);
    }
    return(0);
}

