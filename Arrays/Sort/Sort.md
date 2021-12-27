# Intro
Sorting is the process of taking a datastructure and ordering it in some meaningful way.  There are several approaches to sorting, from naive bubble sort (Compare each element to every other element), to divide-and-conquer algorithms such as Mergesort and Quicksort, to number theory applications such as countingsort.  Expectations generally are to have an array with unknown ordering, and placing them either in ascending or descending order.  That does imply the underlying types should be comparable.

## Mergesort
Mergesort involves recursion by breaking the array down into halves, and then calling a merge function.  This process of breaking the array down and then working on a smaller problem reduces the time complexity based on the size of the partition, and since mergesort chooses the middle element of the array, it halves the size of the problem at each step.  Which is a classic behavior for logarithmic time.
Average Running time: O(n log(n))

Pseudocode:

    Mergesort(int[] input, int begin, int end){
        if(begin >= end)
            return;
        
        int mid = begin + (end - begin) / 2;

        Mergesort(input, begin, mid);
        Mergesort(input, mid, end);

        Merge(input, begin, mid, end);
        }
    }

    Merge(int[] input, int begin, int mid, int end){
        //We handle inplace writing to the base array here by dividing the array and then comparing.
        int left = mid - begin + 1;
        int right = end - mid;

        int leftarr[] = input[begin:left];
        int rightarr[] = input[left:end];

        //Ok, we've divided the input into 2 sides, now to perform the comparison an write.
        int i, j = 0;
        int write = left;
        for(; i + j < min(left, right);){
            if(leftarr[i] <= rightarr[j]){
                input[write] = leftarr[i];
                i++;
            }
            else{
                input[write] = rightarr[j];
                j++;
            }
            write++;
        }

        //Now we just need to clean up if there are any remaining indexes

        if(i < left){
            for(; i < left; i++){
                input[write] = leftarr[i];
                write++;
            }
        }
        if(j < right){
            for(; j < right; j++){
                input[write] = rightarr[j];
                write++;
            }
        }
    }

## Quicksort

Quicksort is similar to mergesort, except instead of choosing the middle of the array, it chooses a pivot element with which to rotate the entire array against.  This sorts the array relative to the pivot, and subsequent calls to the subarray handle that smaller responsibility.  Since the length of the array isn't always even, the runtime is dominated based on the choice of the pivot.

Average runtime: O(N log(N))
Worst case: We choose an extrema as the pivot, O(N^2)

Pseudocode:

    Quicksort(int[] input, int start, int end){
        if (start < end)){
            pivot = partition(input, start, end);

            Quicksort(input, start, pivot - 1);
            Quicksort(input, pivot, end);
        }
    }

    partition(int[] input, int start, int end){
        //There are many ways of choosing a pivot for partitioning, and unless you know something about your input it's somewhat arbitrary, so we'll choose the first index as our pivot.

        pivot = input[start];

        i = (start - 1);
        for(int j = start; j <= end - 1; j++){
            if(input[j] < pivot){ // Index needs to be placed to the right of the pivot, so do it!
                i++;
                swap(input[i], input[j]);
            }
        }
        swap(input[i+1], input[start]); //We've found the element to swap relative to the pivot, so do it!
        return (i+1);
    }


## Countsort

Countsort is a bit different, it works best if the range of the inputs is small.  It creates a count array of values, which keep track of when a value in the sorted array should change, and then writes those based on count to an output array.  By incrementing the original value as the index of the count array, you get the number of that value's incidents.  And then by taking the count array and making a running sum of incidents you get the correct index in the sorted array.

Average runtime: O(n+k), n is the size of the array and k is the range of values of the array.
It does also use extra space because there's another array made, that which keeps track of the digits.

Pseudocode:

    Countingsort(int[] input, int range, int len){

        int i, j = 0;
        int count[range + 1];
        int output[len];

        //Initialize the count array
        for(; i <= range; i++){
            count[i] = 0;
        }
        //Store count of elements
        for(; j< len; j++){
            count[input[j]] = count[input[j]] + 1;
        }

        //Shift the count to the actual positions

        for(i = 1; i < range+1; i++){
            count[i] = count[i] + count[i-1];
        }

        //Now we have the number of inflection points of the array, and how many elements are in each bucket.

        //Time to make the output
        for(j = len - 1; j >= 0; j--){
            output[count[input[j]]-1] = input[j];
            count[input[j]] = count[input[j]] - 1;
        }
    }