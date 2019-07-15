# Software Development Lifecycle Models
## Classical Waterfall Model
Classical Waterfall Model divides the lifecycle into a set of sequential (cannot be done parallely) phases. The phases are -
1. `Feasiability study` <br> 
   Find if any solution financially and technically feasible to develop the software. Best solution is chosen.
2. `Requirement analysis and Specification`  <br>
   Gather and understand the exact requirements of the customer. Document them properly in an SRS (Software requirement specification) document.
3. `Design` <br>
   Make a structure suitable for implementation from the SRS.
4. `Coding and Unit Testing` <br>
   Code each module and test them to see if they work indepently.
5. `Integration and System Testing` <br>
   Integration of various modules is carried out incrementally over a number of steps, resultant system is tested after each step. <br>
   System Testing is done after this in 3 parts -
   1. `Alpha Testing` - Testing by development team.
   2. `Beta Testing` - Testing by a set of friendly customers.
   3. `Acceptance Testing` - Customers feedback as to if the finished product is acceptable.
6. `Maintainence` <br>
   60% of the total effort. Types - corrective (remove errors), adaptive (new systems).

Drawbacks - 
1. No feedback or correction mechanism.
2. Difficult to accomodate any change. (Requirement should be complete at start)
3. Phases cant be done parallely.
   
## Iterative Waterfall Model
Its the same as Classical Waterfall Model but there are feedback paths from each phase to all preceding phases. If an error is detected, we go back to the phase with the error and redo it. This has many of the drawbacks of the classical model.

## Agile Software Development
Agile is a time-bound, iterative approach to software delivery that builds software incrementally from the start of the project, instead of trying to deliver all at once. Its principles -
1. Highest priority is to satisfy the customer through early and continuous delivery of valuable software.
2. Deliver working software frequently (every few weeks).
3. It welcomes changing requirements, even late in development.
4. Regular face-to-face meetings with and within the development team.

An agile process focuses more on code development rather than documentation. <br> 
Advantages of Agile -
* Deployment of software is quicker.
* Can adapt to rapidly changing requirements and respond faster.
* Helps in better immideate feedback which helps improve in the next increment.
  
Disadvantages of Agile -
* More code focused and less documentation produced.
* Heavily dependent on constumer input. (Ambguitity can get project off track)
* May be difficult for new programmers to make the decisions required.
* Face-to-Face communication is hard in large organizations.