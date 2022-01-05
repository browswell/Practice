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


### Problem

#### Compute the LCA

The LCA is the least common ancestor of 2 nodes.  We'll continue with the example that has a complete binary tree, although other structures of the input data might be more interesting, since we can fulfill this requirement mathematically instead of through traversal.  Thus we will take note that in a heap structure the LCA can be computed since the representation maintains parents, and look in this instance at a traversal approach.

The LCA can be found by finding the most common DFS recursive call is used to find the two nodes in question.  That is it is the call most close to the node that is called in both DFS stack traces.  Which means our first approach is to DFS to a node, noting the trace, and then DFS to the second node, also noting the trace.  The LCA is found by comparing traced indexes, and the last one that is the same is kept.  That means that there are 3 passes, with the same big-O notation as DFS.

dfs_trace will keep an array of indexes that are traversed, where the index of trace is the height of the traversal at that step, and the value is the nodal index.  E.g. a trace of [1, 3, 6] would imply going to node 1 at height 0, node 3 at height 1, and node 6 at height 2.

#### Pseudocode

bool dfs_trace(node *root, int search, int level, int *trace){
    if(root->val == search){
        trace[level] = root->index;
        return(1);
    }
    if (root->left != NULL){
        int left = dfs_trace(root->left, search, level + 1, trace);
        if(left){
            trace[level] = root->left->index;
            return(1);
        }
    }
    if (root->right != NULL){
        int right = dfs_trace(root->right, search, level + 1, trace);
        if(right){
            trace[level] = root->right->index;
            return(1);
        }
    }
    return 0;
}

int lca(node *root, int n0, int n1, int height){
    int *trace = new int[height];
    int *trace2 = new int[height];

    dfs_trace(root, n0, 0, trace);
    dfs_trace(root, n1, 0, trace2);

    int lca_index = 0;
    for(int i = 0; (i < height) && (trace[i] == trace2[i]); i++){
        lca_index++;
    }
    return (lca_index);

}