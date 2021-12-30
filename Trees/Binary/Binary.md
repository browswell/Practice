# Intro

A binary tree is a structure consisting of a collection of nodes, which have references to left and right children, which can be null.  This structure is useful in several ways, as it can reflect hierarchical relationships, and is helpful in sorting and efficiently searching through datasets.

## Traversal

Traversal is a characteristic of trees, in which search is conducted.  It's primarily broken into two types, Bredth First Search (BFS) and Depth First Search (DFS), which can be further simplified into traversing the tree via a stack or a queue.  Want BFS?  Go ahead and queue up children and then recurse.  Want DFS?  Go ahead an recurse directly, using the call stack to iterate natively for you.

### BFS Pseudocode

    node* bfs(node *root, int search){
        list<node*> queue;
        queue.push_back(root);
        while(!queue.empty()){
            node* curr = queue.pop_front();
            if(curr->val == search){
                return curr;
            }
            else{
                queue.push_back(curr->left);
                queue.push_back(curr->right);

            }
        }
    }

### DFS Pseudocode

    node* dfs(node *root, int search){
        if(root->val == search){
            return root;
        }
        else{
            dfs(root->left, search);
            dfs(root->right, search);
        }
    }

### Traversal extended

Note that we took the property of having a left and a right child for granted for these searches.  This can be further generalized by looping through all children, thus getting an n-ary tree.  In the same fashion it can be generalized for graphs by marking nodes that have been visited in a skip list, or a visited list.

Also note the order of the calls to queue or recurse are somewhat arbitrary, and determine if this is in prefix, postfix, or infix notation...  That is, do we consider left child, root, right child (infix), left right root (prefix), or root left right (postfix).