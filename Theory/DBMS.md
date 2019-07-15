# DBMS
A DBMS is a powerful tool for creating and managing large amounts of data efficiently and allowing it to persist over long periods of time, safely. <br>
A Database is a collection of data managed by a DBMS. <br>
Features expected of a DBMS -
1. Provide a Data-Definition Language (DDL) to create databases and schemas.
2. Provide a Data-Manipulation Language (DML) to query and modify the data.
3. Store very large amounts of data for a long time and provide efficient access.
4. Provide `Durability` - recovery of database in case of failure, error or misuse.
5. Allow concurrent access to many users.

## Advantages of DBMS
* Minimized Redunancy. Better Data consistency.
* Simplified Data access.
* We can create multiple views of the same data depending on the user's needs.
* Concurrent access.
* Backup and Recovery mechanism.
* Data security through authorization and encrytion.
   
**Information Integration** <br>
Joining information stored in many related databases into a whole.

**Transactions** <br>
Transactions are units that must be executed atomically and independently from one another.

## Three-Level ANSI-SPARC Architecture
* `Internal/Physical Level` - How the data is stored in the database.
* `Conceptual Level` - What data is stored in the database and relationships in the data.
* `External Level` - User's view of the database.
  
One of the main goals of this is `Data Independence`, Upper levels should not be affected by the changes in lower levels. <br>
`Logical Data Independence` is between Conceptual and External Levels. <br>
`Physical Data Independence` is between Internal and Conceptual Levels.

## Keys
* `Super Key` - Its a set of one or more attributes (col) whose values can uniquely determine each entity (row).
* `Candidate Key` - Its the minimal Super Key.
* `Primary Key` - One of the Candidate Keys is chosen as the primary key.
* `Foreign Key` - A column or a combination of columns whose values match a Primary Key in a different table. It ensures refferal integrity of data.
* `Composite Key` - A key consists of more than one attribute.
* `Alternate Key` - Candidate keys that are not selected as the Primary Key.
  
`Weak Entity` - An entity for which a key attribute can't be defined.

## Relational Algebra
* `Projection` - Gives the specified columns of a relation, removes others. Represented by pi sybmol with the columns in subscript.
* `Selection` - Gives the rows of the relation which match the condition. Represented by sigma with the condition in subscript.
* `Cartesian Product` - Pairs every row in the first relation with every row in the second relation. Represented as cross product.
* `Theta Join` - Repesented by a bowtie symbol with a condition as subscript. This does a cartesian product and gives rows which obey the condition.
* `Natural Join` - Represented by a bowtie symbol. Joins two relation based on the common attributes.
* `Division` - See lect 8-10 slide 44

## Redundant Data
Data is said to be redundant if same data is copied at many places. Has to be updated at many places. Data is said to be `inconsistent` if multiple copies of same data does not match with each other.
* Waste of storage capacity.
* Introduces anomolies in updation, insertion, and deletion.
* Redunant data may be beneficial for fast performance.
  
Normalization is used to eliminate redundancy.

## Functional Dependencies
A set of attributes X functionally determines a set of attributes Y if the value of X determines a unique value for Y. <br>
Functional Dependencies also satisfy `transitivity`.
* A functional dependency A->B is a `full functional dependency` if removal of any attribute from A results in the dependency no longer existing.
* A functional dependency A->B is a `partial dependency` if there is some attribute that can be removed from A and yet the dependency still holds.

## Normalization
1. `Unnormalized Form (UNF)` <br>
   A table that contains one or more repeating groups. <br>
   (A repeating group is a set of attributes that occurs with multiple values for a single occurence of the chosen key).
2. `First Normal Form (1NF)` <br>
   Remove the repeating groups in UNF.
3. `Second Normal Form (2NF)` <br>
   Remove all partial dependencies from 1NF. <br>
   So, Every non-candidate key attribute is fully functionally dependent on the candidate key.
4. `Third Normal Form (3NF)` <br>
   Remove all transitive dependencies from 2NF. <br>
   So, no non-candidate key attribute is transitively dependent on the candidate key.
5. `Boyce Codd Normal Form (BCNF)` <br>
   Remove all functional dependencies A->B where A is not a candidate key.
6. `Fourth Normal Form (4NF)` <br>
   Remove Multi-valued dependencies.
7. `Fifth Normal Form (5NF)` <br>

## Equivalence of FDs
Two sets of functional dependencies are said to be equivalent if their closure are the same.

# Transaction Managemen
A transaction is a unit of program execution that access and/or updates data items.

`Abort` - Aborting a transaction involves rolling back all changes made by it.

## ACID Properties
* `Atomicity` <br>
  A transaction is either fully executed or not at all. Never Partially.
* `Consistency` <br>
  Integrity constraints must be maintained so that the database is consistent before and after the transaction.
* `Isolation` <br>
  All transactions are independent, i.e. there is no interference from other simultaneous transactions.
* `Durability` <br>
  Once committed, the effects of a transaction on data should persist and should be recoverable even in case of a system failure.

## Schedules
Order of operations to be performed when we want to execute one/more transactions.
* `Serial Schedule`<br>
  Operations of different transactions are not interleaved. <br>
  A transactions happens wholly before or after another transaction.
* `Non-Serial Schedule` <br>
  Operations of different transactions are interleaved.

`Serializable Schedule` <br>
A schedule is serializable if it is equivalent to/has the same effect as some serial schedule.

## Two-Phase Locking
[GFG Link](https://www.geeksforgeeks.org/dbms-concurrency-control-protocols-two-phase-locking-2-pl/) <br>
There are two phases, `growing phase` where new locks can be acquired but none can be released and `shrinking phase` where locks can be released but new locks cannot be acquired. <br>
This ensures serializability but cascading aborts, deadlock and starvation are still possible.

## Strict Two-Phase Locking
Each transaction must obtain a shared lock on object before reading, and an exclusive lock on object before writing. All locks are released when the transaction completes. <br>
This removes the possibility of cascading aborts.

## Problems with concurrency
* `Lost Update Problem` - When one transaction updates a value but another transaction reads that data before its written.
* `Dirty Read Problem` - When one transaction updates and writes a value and then the transaction fails but another transaction uses that data before it is rolled back.

## Indexing
[GFG Link](https://www.geeksforgeeks.org/indexing-in-databases-set-1/)

# B-Tree
Its a self-balancing binary search tree. The main goal of B-Tree is to reduce the number of disk accesses by making the tree `fat` i.e. keeping a low height and storing as many keys as possible in a single node.
* All leaves are at the same level.
* Size of node is generally kept the same as a disk block size.
* Its defined by degree **`t`**, all nodes except root must have atleast t-1 keys and at most 2t-1 keys.
* All keys in a node are sorted in increasing order. The child between keys k1 and k2 will have all keys in range k1 to k2.
* Most operations are logarithmic.
  
[GFG Link for Set 1 - Intro](https://www.geeksforgeeks.org/indexing-in-databases-set-1/) <br>
[GFG Link for Set 2 - Insert](https://www.geeksforgeeks.org/b-tree-set-1-insert-2/) <br>
[GFG Link for Set 3 - Delete](https://www.geeksforgeeks.org/b-tree-set-3delete/)

## B+ Tree
B+ Tree stores all data pointers to disk block in the leafs. <br>
[GFG Link](https://www.geeksforgeeks.org/database-file-indexing-b-tree-introduction/)