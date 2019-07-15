# Object Oriented Programming
Object Oriented Programming (OOP) is a programming paradigm where the complete software operates as a bunch of objects talking to each other. <br>
OOP makes overall system easier to understand and makes it easier to maintain.

Some important points to know about OOP :
* OOP treats data as a critical element and emphasis is on data rather than procedure.
* Decomposition of the problem into simpler modules.
* Doesn’t allow data to freely flow in the entire system, ie localized control flow.
* Data is protected from external functions.

Advantages of OOP –
* It models the real world very well.
* With OOP, programs are easy to understand and maintain.
* OOP offers code reusability. Already created classes can be reused.
* OOP facilitates the quick development of programs where parallel development of classes is possible.
* With OOP, programs are easier to test, manage and debug.

Disadvantages of OOP –
* With OOP, classes sometimes tend be over-generalised.
* The relations among classes become superficial at times.
* The OOP design is tricky and requires appropriate knowledge. Also, one needs to do proper planning and design for OOP programming.

## Abstraction
Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation. <br>
The main goal is to handle complexity by hiding unnecessary details from the user. <br>
Advantages -
* Helps the user to avoid writing the low level code. 
* It reduces the complexity of viewing the things.
* Avoids code duplication and increases reusability.
* `Can change internal implementation of class independently without affecting the user.`
* Helps to increase security of an application or program as only important details are provided to the user.

## Modularity
Modularity is dividing a system into well-defined modules, which can be built, used and examined separately.
* Modularity enables re-usability and minimizes duplication. It also makes concurrent development of different modules easier.
* Modularity also makes it easier to fix problems as bugs can be traced to specific system modules.
  
## Polymorphism
Polymorphism literally means having many forms, or ability to have more than one form. <br>
An operation may exhibit different behaviors in different instances/situations. The behavior depends upon the types of data used in the operation. <br>
**Compile Time Polymorphism**
* `Function Overloading` - Same function with different signature can do different tasks. <br>
* `Operator Overloading` - Same operator can exihibit different behaviour with different data types.
* `Templates`
  
**Runtime Polymorphism**
* `Function Overriding` - When derived class has a different definition of a function of the base class. Done using `Virtual Functions`. Virtual functions are called according to the type of object pointed or referred, not according to the type of pointer or reference. In other words, virtual functions are resolved late, at runtime.


## Information Hiding 
Information Hiding is hiding the data belonging to an object from the other objects. We know WHAT an object can do but not HOW. <br>
Information Hiding increases the level of independence in a system. (Independence of modules is very important in large systems and their maintainence.)

## Encapsulation
Encapsulation is defined as wrapping up of data and methods that manipulate it into a single unit. <br>
Encapsulation leads to data abstraction and Information hiding.

## Encapsulation vs Data Abstraction
Encapsulation is data hiding(information hiding) while Abstraction is detail hiding(implementation hiding). <br>
While encapsulation groups together data and methods that act upon the data, data abstraction deals with exposing the interface to the user and hiding the details of implementation.

## Inheritance 
Inheritance is the ability of one class to inherit capabilities or properties of another class. <br>
Advantages -
* Avoiding code duplication (easier to maintain and change, less chance to introduce bugs in maintainence)
* Increases code reuse.
* Makes code more extendible.
* Makes maintainence easier.
  
**Subtyping** - Objects of subclasses can be used where objects of supertypes are required. 

**Autoboxing** - Change int to Interger class. <br>
**Unboxing** - Change Integer to int.

**Static Type** - The declared type of a variable is its static type. <br>
**Dynamic Type** - The type of object a variable refers to is its dynamic type. <br>
For example, Vehicle v = new Car(); -> Static type is Vehicle but Dynamic type is Car.

## Object
Objects are basic run-time entities in an object-oriented system, objects are instances of a class. They represent real life entities.
Objects contain data and methods to manipulate that data.

## Coupling
Coupling refers to seperate units/modules of a system are linked. We aim for loose coupling.
* If two classes closely depend on many details of each other, they are said to be tightly coupled.
* Loose Coupling makes it easier to 
  * understand one class/module without reading others 
  * change one class without affecting the others.
  
Thus, Loose coupling increases maintainability. In contrast, if there is tight coupling -
* Changes to one class bring a cascade of changes to other classes.
* Classes are harder to understand in isolation.
* Flow of control between objects of different classes is complex.


## Cohesion
Cohesion refers to the number and diversity of tasks a single unit (module, class or method) is responsible for. <br>
If each unit is responsible for a single logical task, its said to have high cohesion. We aim for high cohesion. <br>
* Classes should represent one single, well defined entity.
* Method should be responsible for one and only one well defined task.

High Cohesion makes it easier to - 
* Understand what the class/method does.
* Reuse the classes/methods.
* Use more descriptive names for the class/method.

## Test Driven Development (TDD)
Tests help us avoid/find bugs early and improves our design. <br>
TDD is a simple procedure of writing tests before the actual implementation. Its implemented using the RED-GREEN-REFACTOR cycle. <br>
**Unit Testing** - Its a practice where we test small, individual and isolated units (methods, classes, etc) of code. <br>
RED-GREEN-REFACTOR cycle - 
1. Write a Test. Compile to make sure it fails.
2. Implement code to make it pass.
3. Run all the tests and fix bugs if any fails.
4. Refactor code and do repeat from 3 till no more refactor.
5. Plan new Test, go to 1.
   
**Refactoring** is the process of changing the structure of existing code without changing the external behaviour. <br>
Risky without unit tests. Refactoring is done to -
* Enhance readability 
* Reduce complexity
* Reduce maintainence costs
* Make the code cheaper to extend later.

## Extreme Programming (XP)
Extreme Programming is a light weight method for small to medium sized teams that are developing software with vague/changing requirements. <br>
Rather than planning, analyzing and design for the future, in XP we do all these a little at a time throughout the development.

## SOLID Principles
**S : Single Responsibility Principle** <br>
A software module/unit should have one and only one responsibility. (i.e. it should have only one reason to change). This translates to High Cohesion. <br>
Group together things that change for the same reason, seperate those that dont.

**O : Open Closed Principle** <br>
Modules should be open for extension but closed to modification. Should be able to extend the behaviour of a module without changing it. <br>
Keep things that change frequently seperate from things that dont change. <br>
Things that change frequently should depend only on things that dont change.

**L : Liskov Substitution Principle** <br>
Anything that uses pointer/reference to base class must be able to use derived classes without knowing it. We must be able to substitute derived class with base class without any problems. <br>
Or objects of a superclass shall be replaceable with objects of its subclasses without breaking the application.

**I : Interface Segregation Principle** <br>
Clients should not be forced to depend upon interfaces that they do not use. <br>
ISP splits interfaces that are very large into smaller and more specific ones so that clients will only have to know about the methods that are of interest to them.

**D : Dependency Inversion Principle** <br>
Two parts:
* High-level modules should not depend on low-level modules. Both should depend on abstractions.
* Abstractions should not depend on details. Details should depend on abstractions.
  
The general idea of this principle is as simple as it is important: High-level modules, which provide complex logic, should be easily reusable and unaffected by changes in low-level modules, which provide utility features. To achieve that, you need to introduce an abstraction that decouples the high-level and low-level modules from each other.

**GOOD DESIGN - HIGH COHESION AND LOW COUPLING.**

