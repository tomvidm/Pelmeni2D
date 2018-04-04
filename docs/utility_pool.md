# Pool container
The purpose of the pool container is to limit heap allocation. The Pool class allocated a slice of the stack (In this naive implementation, using std::Array as the underlying container) and lets the user access objects by their index.

The class keeps track of several variables:
* `firstFreeIndex` - refers to the first unused index
* `freeList` - a list of freed indexes
* ``

When an object is removed, the object itself is not removed. The state of the object is flagged as free, and the index is pushed onto the free list, so that the next insertion will take this place. This is to ensure that iterating over the contents will meet as few holes as possible.

## Methods
`T::id push(T&& obj)`

This method starts by looking for a vacant id, moves the argument into the array and returns the index, as well as doing internal bookkeeping.

