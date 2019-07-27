## String Classes
* String class is immutable. s = s + "something" creates a new creates a new string. It only changes the reference.
* StringBuilder is mutable. Faster when changing things.
* StringBuffer is same as StringBuilder but its thread safe.

## Finally Block
The `finally()` in try-catch-finally is always executed. Its executed even if there is a return statement in the try or catch block. <br>
`finally()` is not executed if System.exit() is called first.

## Daemon Thread
Daemon thread is a low priority thread that runs in background to perform tasks such as garbage collection.
* They can not prevent the JVM from exiting when all the user threads finish their execution.
* JVM terminates itself when all user threads finish their execution

## Garbage Collector
[GFG Link](https://www.geeksforgeeks.org/garbage-collection-java/) <br>
Garbage Collector frees heap memory by destroying unreachable objects. Garbage Collector is a Daemon Thread as it is always running in the background.
* Any object is said to be unreachable if any active object in the program has no reference to it.
* Island of isolation is a group of objects that reference each other but they are not referenced by any active object in the application. Strictly speaking, even a single unreferenced object is an island of isolation too. 
* [Mark and Sweep Algo is used to find objects to be deleted](https://www.geeksforgeeks.org/mark-and-sweep-garbage-collection-algorithm/)

We can explicitly call the garbage collector using `System.gc()`

## Finalize
`finalize()` is a method in the Object class. Its called by the garbage collector on all objects before destorying the object. <br>
Its used to perform cleanup activities, release resources, files, etc.

## Static Methods
* Static Methods can be `overloaded`. (Overloading is static/compile time polymorphism)
* Static Methods cannot be `overridden`. (Overriding is run-time polymophism but static methods are resolved at compile time) <br> If a derived class defines a static method with same signature as a static method in base class, the method in the derived class hides the method in the base class. 

Important points for method overriding and static methods 
1. For class (or static) methods, the method according to the type of reference is called, not according to the object being referred, which means method call is decided at compile time.
2. For instance (or non-static) methods, the method is called according to the type of object being referred, not according to the type of reference, which means method calls is decided at run time.
3. An instance method cannot override a static method, and a static method cannot hide an instance method.

## Static Block
Code inside static block is executed only once: the first time you access a static member of that class or the first time you make an object of that class (before the constructor). <br>
Generally used for static initializations.
```java
class Test { 
    static int i; 
      
    static { 
        i = 10; 
        System.out.println("static block called "); 
    } 
} 
```

## Initializer Block
Initializer block contains the code that is always executed whenever an instance is created. It is used to declare/initialize the common part of various constructors of a class. <br>
Its executed whenever a constructor is invoked, before the constructor's code.
```java
public class GFG 
{ 
    // Initializer block starts.. 
    { 
        // This code is executed before every constructor. 
        System.out.println("Common part of constructors invoked !!"); 
    } 
    // Initializer block ends 
  
    public GFG() { 
        System.out.println("Constructor invoked"); 
    } 
}
```

## Object Cloning
Object cloning means to create an exact copy of the original object. <br>
For a class to support cloning, it must implement the `Cloneable` interface and override the `clone` method.

## How are Java objects stored in memory?
In Java, all objects are dynamically allocated on Heap. This is different from C++ where objects can be allocated memory either on Stack or on Heap. In C++, when we allocate abject using new(), the object is allocated on Heap, otherwise on Stack if not global or static.

## Static Nested (nested) and Non-Static Nested (inner) Class
[GFG Link](https://www.geeksforgeeks.org/static-class-in-java/)
* Top level classes cant be static, only nested classes can be static.