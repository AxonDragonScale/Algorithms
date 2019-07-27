## C++ Sort
* C++ uses Introsort, a hybrid of Quicksort, heapsort and insertion sort. <br> 
  Introsort begins with quicksort and if the recursion depth goes more than a particular limit it switches to Heapsort to avoid Quicksort’s worse case O(N^2) time complexity. It also uses insertion sort when the number of elements to sort is quite less. [Indepth Link](https://www.geeksforgeeks.org/know-your-sorting-algorithm-set-2-introsort-cs-sorting-weapon/)
* C++ also has stable_sort(), it is an implementation of mergesort.

## Local Static Variables
* A local static variable is a variable whose lifetime doesn’t end with a **function** call where it is declared. It extends for the lifetime of complete program.
*  All calls to the function share the same copy of local static variables. They are retained in memory and don't get redefined every function call.
*  They get initialized with the default value as 0. They can only be initialized with constant literals.
```c
void fun() {
    static int x = 10;
    cout << x++;
}
```

## Static Functions
* In C, functions are global by default. Unlike global functions in C, access to static functions is restricted to the file where they are declared. Therefore, when we want to restrict access to functions, we make them static. 
* Another reason for making functions static can be reuse of the same function name in other files.
```c
static void fun() {
    ...
}
```

## Static Member Variables and Functions in Classes
Same as in Java, static variables are owned by the class not any of its instances. Static member variables and functions can be accessed by the class name directly.
* Static member functions do not have a 'this' pointer.
* Static member functions cannot be virtual.

## l-value and r-value
* **l-value or location value** refers to an expression that can be used on left side of  assignment operator. <br>
 **Non-Modifiable l-value** are l-values that cannot be modified. Const variables are Non-Modifiable l-value. <br>
**Modifiable l-value** are l-values that can be modified.
* **r-value** refers to data value that is stored at some address in memory. <br>
  A r-value is an expression that can’t have a value assigned to it i.e. r-value can appear on right but not on left hand side of an assignment operator.

## Volatile
The volatile keyword prevents the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler (they can be changed by code outside the scope of current code). <br>
The system always reads the current value of a volatile object from the memory location rather than keeping its value in temporary register at the point it is requested, even if a previous instruction asked for a value from the same object.

## Stack and Heap Memory
* Heap is used for dynamic memory allocation while stack is used for storing local variables and arguments of a method.
* In Stack, allocation and deallocation is automatic while in Heap programmer does it manually.
* Stack is more prone to memory shortage while Heap is prone to fragmentation.
* Handling Heap frame is more costlier than stack frame.

## Dynamic Binding
In dynamic binding, the code to be executed in response to function call is decided at runtime. C++ has virtual functions to support this.

# The `virtual` Keyword
[GFG Link](https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-c-set-1-introduction/) <br>
Virtual functions are called according to the type of the object instance pointed to or referenced, not according to the type of the pointer or reference.

## Pure Virtual Functions/Abstract Function
A pure virtual function (or abstract function) in C++ is a virtual function for which we don’t have implementation, we only declare it. A pure virtual function is declared by assigning 0 in declaration. 
```c++
class Test { 
public: 
    virtual void show() = 0; 
}; 
```

## Abstract Class
A class which contains atleast one pure virtual function, is known as abstract class.
* An abstract class can have constructors but we can’t create an object of abstract class but we can have pointers and references of abstract class type. 
*  If we don't override the pure virtual function in derived class, then derived class also becomes abstract class.


## vtable and vptr
* vtable is a table of function pointers. It is maintained per class.
* vptr is a pointer to vtable. It is maintained per object. <br>

Compiler adds additional code at two places to maintain and use vtable and vptr -
1. Code in every constructor. This code sets vptr of the object being created to point to vtable of the class.
2. Code with polymorphic function call (e.g. bp->show()). Wherever a polymorphic call is made, compiler inserts code to first look for vptr using base class pointer or reference. Once vptr is fetched, vtable of derived class can be accessed. 

## Virtual Base Class
[GFG Link](https://www.geeksforgeeks.org/virtual-base-class-in-c/)

## 'this' Pointer
[GFG Link](https://www.geeksforgeeks.org/this-pointer-in-c/) <br>
The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions. It is a constant pointer that holds the memory address of the current object.

## struct vs class
* struct members are public by default while class members are private by default.
* While inheriting if no access specifier is specified, structs inherit as public while classes inherit as private. (Yes, struct support inheritance)

## Friend Class and Friend Functions
[GFG Link](https://www.geeksforgeeks.org/friend-class-function-cpp/) <br>
A friend class/friend function can access private and protected members of other class in which it is declared as friend.
* Friendship is not mutual. If a class A is friend of B, then B doesn’t become friend of A automatically.
* Friendship is not inherited.
```c++
class Node { 
private: 
  int key; 
  Node *next; 
  
  friend class LinkedList; // Now class  LinkedList can access private members of Node 
  friend int List::search(); // Only search() of List class can access private members
}; 
```

## Copy Constructor vs Assignment operator
Copy constructor is called when a new object is created from an existing object, as a copy of the existing object. Assignment operator is called when an already initialized object is assigned a new value from an existing object. 

## Copy Elision
Copy elision (or Copy omission) is a compiler optimization technique that avoids unnecessary copying of objects.

# Links

https://www.geeksforgeeks.org/delete-in-c/