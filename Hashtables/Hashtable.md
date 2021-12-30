# Intro

Hashtables act as an array of references, to a referential hashed value.  In the event that a collision occurs (2 input having the same hashed value), a linked list structure can be used to chain the reference.

This means that the following structure is used

1 - {hash = 1} -> {hash2 = 1} -> etc.
2 - {hash = 2}
3 - {empty}
etc.

Hashtables are a very powerful datastructure in that the general operations are very efficient.  Lookup in the general case is O(1), same with insertion and deletion.  The efficiency of the operations then is tied into the hashing algorithm's ability to evenly spread out references across the allocated space.  That also means that the hash table should contain some meta information about itself, such as the amount of space that has been used, and if reallocation is necessary.  Reallocation, or rehashing, is a relatively expensive operation, where the hashtable changes the allocated memory space, and remaps all used references into the new space.  A lot of the time this operation can be spun up by another thread and handled independent of standard operation, but that depends on the specific implementation.

