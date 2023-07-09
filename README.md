
# Implementation of heap
## Table of contents
* [Description](#Description "Goto Description")
## Description
* Created the heap management schema and implemented the following garbage collection methods to find the garbage nodes in the given heap.
* **Reference Counting method**
In this method, every object has a reference count associated with it. When a reference to an object is created, the reference count is incremented. Conversely, when a reference is no longer needed or goes out of scope, the reference count is decremented. When the reference count of an object reaches zero, it means there are no more references to that object, indicating it is no longer in use.
* **Mark and Sweep method**
The method consists of two main phases: marking and sweeping. During the marking phase, the garbage collector traverses the object graph starting from the roots (such as global variables, stack frames, and registers) and marks all objects that are reachable. This is typically done by setting a mark bit or flag in each object.
Once the marking phase is complete, the sweeping phase begins. In this phase, the garbage collector scans through the entire memory heap, examining each object. Objects that are marked as reachable are considered live and are left untouched. Objects that are not marked (i.e., unreachable) are considered garbage and can be safely deallocated and reclaimed.
<img src="https://github.com/Gajanan-Sapsod/Heap-Implementation/assets/105559761/574ce099-4494-4d9f-b958-e7133a3a15ba"  width="600" height="300">

