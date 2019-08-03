# Operating Systems
[GFG Last Minute Notes](https://www.geeksforgeeks.org/last-minute-notes-operating-systems/) <br>

## Process
A process is a program in execution. Each Process has a PCB (Process Control Block) which has -
Process State, Program Counter, registers, scheduling info, Memory management info, i/o info, accounting info.

## Thread
A thread is a lightweight process and forms the basic unit of CPU utilization.
* A thread has its own program counter, register set, and stack.
* A thread shares resources with other threads of the same process the code section, the data section, files and signals.

Threads are lightweight compared to processes, are more economical to create. <br>
Context Switch in threads are more efficient compared to Context Switch in processes. <br>
Thread don't need IPC, they can communicate to each other with invoking the kernel.

**CPU-bound process** – spends more time doing computations, few very long CPU bursts <br>
**I/O-bound process** – spends more time doing I/O than computations,
many short CPU bursts

## Schedulers
* Long-term scheduler (or job scheduler)
  * Selects which processes should be brought into the ready queue
  * Controls the degree of multiprogramming
  * Invoked infrequently. (Allowed to be slow)

* Short-term scheduler (or CPU scheduler)
  * Selects which process should be executed next.
  * Invoked very frequently. (Must be very fast)
  * Invoked when an event occurs - Clock interrupts, I/O interrupts, OS calls, Signals

* Dispatcher <br>
  Dispatcher module gives control of the CPU to the process selected by the short-term scheduler, this involves: switching context, switching to user mode, jumping to the proper location in the user program
  * Dispatch latency – time it takes for the dispatcher to stop one process and start another.
  
* Medium Term Scheduler <br>
  Used in swapping function. Its used control the degree of multiprogramming.

# Deadlock
Deadlock can occur only if the following 4 conditions hold simultaneously - 
* `Mutual Exclusion` <br>
  Only one process may use an instance of a resource at a time.
* `Hold and Wait` <br>
  A process holding a resource is waiting for a resource held by another process. <br>
  Prevention - 
  1. Dont allow processes to hold resources to request resources.
  2. Make process request all resources when it begins execution.
* `No Preemption` <br>
  Resources cannot be pre-empted. (Resources can only be released by processes willingly). <br>
  Prevention -
  1. If process holding a resource cant get new resource, then preempt all resources it holds. Restart it only when all needed resources are available
* `Circular Wait` <br>
  There is a set of processes such that, first waits for second, second waits for third,... and  last waits for first. <br>
  Prevention -
  1. Impose a total ordering of all resource types, and require that each process requests resources in an increasing order of enumeration.

### Disadvantages of Deadlock prevention -
1. Low Device Utilization.
2. Reduced system throughput.

## Deadlock Avoidance
In Deadlock Avoidance, if allocating a resource to a process could cause a deadlock then its not allocated. Two approaches -
1. Do not start a process if its demands might lead to deadlock.
2. Do not grant an incremental resource request to a process if this allocation might lead to deadlock.

Methods -
1. When resources only have 1 instance - Resource Allocation Graph
2. When resources may have many instances - Banker's Algo

## Deadlock Detection
Either by detecting cycle in wait-for graph or by Detection Algo.

## Dynamic Loading 
Routines/modules are loaded only when they are needed. (Unused routine not loaded, better memory utilization)

## Dynamic Linking
Linking is postponed until execution. Dynamic Linking is useful for shared libraries.

## Belady's Anamoly
Increasing the number of pages can increase the number of page faults.

## Thrashing
If a process does not have “enough” pages, the page-fault rate is very high. This leads to low CPU utilization due to which the operating system thinks that it needs to increase the degree of multiprogramming and adds another process added to the system. This further increases the page fault rate.
* Thrashing - a process is busy swapping pages in and out.