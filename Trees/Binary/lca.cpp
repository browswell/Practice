#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct node{
	int index;
	int data;
	node *left;
	node *right;
};



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


bool dfs_trace(node *root, int search, int level, int *trace){
    if(root->data == search){
        trace[level] = root->index;
//	std::cout << trace[level] << " ";
        return(1);

    }
    if (root->left != NULL){
        int left = dfs_trace(root->left, search, level + 1, trace);
        if(left){
            trace[level] = root->index;
//            std::cout << trace[level] << " ";
            return(1);
        }
    }
    if (root->right != NULL){
        int right = dfs_trace(root->right, search, level + 1, trace);
        if(right){
            trace[level] = root->index;
//            std::cout << trace[level] << " ";
            return(1);
        }
    }
    return 0;
}

int lca(node *root, int n0, int n1, int height){
    int *trace = new int[height];
    int *trace2 = new int[height];

    dfs_trace(root, n0, 0, trace);
//    std::cout << "\n";
    dfs_trace(root, n1, 0, trace2);
//    std::cout << "\n";

    int lca_index = 0;
    for(int i = 0; i < height; i++){
	    std::cout << trace[i] << " " ;
    }
    for(int i = 0; i < height; i++){
	    std::cout << trace2[i] << " " ;
    }
    std::cout << "\n";
    for(int i = 0; (i < height) && (trace[i] == trace2[i]); i++){
	std::cout << trace[i] << ":" << trace2[i] << " ";
        lca_index++;
    }
    std::cout << "\n";
    return (trace[lca_index-1]);

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
	std::cout << lca(root,3, 4, 5) << "\n";

        
    }
    return(0);
}

