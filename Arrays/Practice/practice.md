# Intro

This markdown will be used to take a problem, laid out in sections, and provide thought processes for solutions as well as pseudocode.  The actual code will be written into its own file.

## Problems

1. (delete duplicates)[#del_duplicates]


## Delete duplicates
<a source="del_duplicates"></a>

Given a sorted array, remove all duplicate values, shifting unique values into the empty spaces.

### Example scenario

{1,1,1,3,4,4,6,6,9,9,9,9} => {1,3,4,6,9}

### Thoughts

We can easily do this by creating a new array, placing unique elements in as we go.  The naive approach would take O(n^2) time, and take space of O(n), by looking at each element in input, and considering if it exists in output.  But this is pretty expensive, and we can do better.

Let's use the fact that we know the input array is sorted, this means the adjacent elements are either the same value as the current index, or not.  Assuming a linear scan, let's see what the comparison looks like...

Let's consider only taking interest in the inflection points, that is when the index and it's next index are not the same.  Then we're looking at the following places in the scan:

Index 2: 1,3  Index 3: 3,4 Index 5: 4,6, Index 7: 6,9.

Hey look, by taking only the inflection points, we've found all of the unique values.  Now all we'd have to do is capture the indexes of the inflection points in an array.  But is that even necessary?

Since we know that the array scan is done, and we aren't scanning the array anymore, we can overwrite the indexes earlier when we hit an inflection point, as such:

int unique = 0;

for(int i = 0; i < len; i++){
    if(arr[i] != arr[i+1]){
        arr[unique] = arr[i];
        unique++;
    }

}

And now we just have to do a bit of cleanup for the last element...

if(arr[unique] != arr[len - 1]){
    arr[unique] = arr[len - 1];
    unique++;
}

And finally we just can get rid of the rest of the array
return(arr[0:unique]);

