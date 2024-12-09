# CPP_Advanced
Advanced C++ program knowledge. Pointers, Object Pointers, Data Structures, Design Patterns and Algorithms

## Syntax for ceating pointer
```cpp
char* p_data = &existing_variable;
char* p_data = malloc(sizeof(char)*n);
...
free(p_data)
```
Allocating memory using the malloc requires a size, which is normally the size of the type by the number of locations.
Freeing memory is done with the free command, which cannot be called on a null pointer!

- Pointer Arithmetic
```cpp
char* p_data = malloc(sizeof(n));
*(p_data +2) = 'c'; // Set the value of data at an offset of 2
...
free(p_data);

```


## Object pointer
❑An object initialized as a pointer.
❑Initialized with the `new `keyword.
❑A class constructor is called after the `new` keyword.
❑This automatically allocates memory without `malloc`.
❑A destructor is called when the pointer is out of scope and automatically frees up memory through the garbage collector.
 
 ➢ **Why?**
 ❑Object pointers are useful for implementing design patterns where one class requires Object pointers are useful for implementing design patterns where one class requires a reference to an instance of another.
 ❑Reference to an instance of another.

 **example**
 ```c++
class ClassName {
    ClassName() { … }
    ~ClassName() { … }
};
// In the above example, ClassName is a constructor and 
// ~ClassName is a destructor.
ClassName *object = new ClassName();
 …
 delete object; // Optional call to destructor.
 ```

When using an object pointers, members are no longer 
accessed with the dot “.” notation! Object pointers use the arrow `->` notation instead.
```cpp
class ClassName {
 ClassName() { … }
 ~ClassName() { … }
 void member_function() { … }
 };
 ClassName *object = new ClassName();
 object->member_function();
```


## Friends 
In C++ the `friend` keyword is another way to interface objects and classes. A `friend` is a class or a function that has access to private and protected members of a class. A `friend` function requires a pass-by-reference to an object.