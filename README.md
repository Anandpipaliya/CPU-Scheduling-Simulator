# CPU-Scheduling-Simulator

The selected scheduling algorithms to implement in this assignment are 

• First Come First Serve (FCFS)

• Round Robin (RR)

• Shortest Job First (SJF)

Process Information

The task information will be read from an input file. The format is

          pid arrival_time burst_time

All of fields are of integer type where:

pid is a unique numeric process ID

arrival_time is the time when the task arrives in the unit of milliseconds burst_time is the CPU time requested by a task, in the unit of milliseconds

The time unit for arrival_time, burst_time and time_quantum is millisecond.

Here is a sample input file:

1 0 10 

2 0 9

3 3 5

4 7 4

5 10 6

6 10 7

Command-line Usage and Examples

Usage: sched input_file [FCFS|RR|SJF] [time_quantum]

where input_file is the file name with task information. FCFS and RR are the names of
scheduling algorithms. The time_quantum only applies to RR. FCFS, SJF are non-
preemptive while RR is preemptive. The last argument is needed only for RR. (See following table for more examples)

Examples Description:

sched input.1 FCFS FCFS scheduling with the data file “input.1”

sched input.1 RR 2 Simulate RR scheduling with time quantum 2 milliseconds (4th parameter is required even for quantum 1 millisecond) with the data file “input.1”

sched input.1 SJF Shortest Job First Scheduling with data file “input.1”

Design Hints

No sample code is given for this project. However, here is a possible design logic you can refer to. The simulator first reads task information from the input file and stores all data in a data structure. Then it starts simulating a scheduling algorithm in a time driven manner. At each time unit (or slot), it adds any newly arrived task(s) into the ready queue and calls a specific scheduler algorithm in order to select appropriate task from ready queue. When a task is chosen to run, the simulator prints out a message indicating what process ID is chosen to execute for this time slot. If no task is running (i.e. empty ready queue), it prints out an “idle” message. Before advancing to the next time unit, the simulator should make all necessary changes in task and ready queue status.

Requirements:

The project requires you to simulate FCFS, SJF and RR scheduling for given tasks and to compute the average waiting time, average response time and average turnaround time.

• Implement scheduling algorithm for FCFS, SJF and RR. The program should schedule tasks and print progress of task every unit time (millisecond) as shown in sample outputs.

• Print statistical information. As soon as all tasks are completed, the program should compute and print 1) average waiting time, 2) average response time and 3) average turnaround time.

Note: if you use static array to implement ready queue structure, you can assume the maximum queue length is 20.

Suggested Methodology

• Implement one scheduling algorithm at each step.

• You can use a circular linked list as the queue structure.

• You can use a data structure similar to a Process Control Block (PCB) for each
task, though it will be much simpler.

Sample outputs

Here is a sample input file:

% more input.1

1 0 10

2 0 9

3 3 5

4 7 4 

5 10 6 

6 10 7

% sched

Usage: sched input_file FCFS|SJF|RR [quantum]

And here is a sample output:

% sched input.1 FCFS

Schdeuling algorithm: FCFS

Total 6 tasks are read from "input.1". press 'enter' to start... 

================================================================== 

<system time 0> process 1 is running

<system time 1> process 1 is running

<system time 2> process 1 is running

<system time 3> process 1 is running

<system time 4> process 1 is running

<system time 5> process 1 is running

<system time 6> process 1 is running

<system time 7> process 1 is running

<system time 8> process 1 is running

<system time 9> process 1 is running

<system time 10> process 1 is finished.......

<system time 10> process 2 is running

<system time 11> process 2 is running

<system time 12> process 2 is running

<system time 13> process 2 is running

<system time 14> process 2 is running

<system time 15> process 2 is running

<system time 16> process 2 is running

<system time 17> process 2 is running

<system time 18> process 2 is running

<system time 19> process 2 is finished.......

<system time 19> process 3 is running

<system time 20> process 3 is running

<system time 21> process 3 is running

<system time 22> process 3 is running

<system time 23> process 3 is running

<system time 24> process 3 is finished.......

<system time 24> process 4 is running

<system time 25> process 4 is running

<system time 26> process 4 is running

<system time 27> process 4 is running

<system time 28> process 4 is finished.......

<system time 28> process 5 is running

<system time 29> process 5 is running

<system time 30> process 5 is running

<system time 31> process 5 is running

<system time 32> process 5 is running

<system time 33> process 5 is running

<system time 34> process 5 is finished.......

<system time 34> process 6 is running

<system time 35> process 6 is running

<system time 36> process 6 is running

<system time 37> process 6 is running

<system time 38> process 6 is running

<system time 39> process 6 is running

<system time 40> process 6 is running

<system time 41> process 6 is finished.......

<system time 41> All processes finish .................... 

============================================================ 

Average waiting time : 14.17

Average response time : 14.17

Average turnaround time: 21.00 

============================================================

% sched input.1 RR 2

Schdeuling algorithm: RR

Total 6 tasks are read from "input.1". press 'enter' to start... 

================================================================== 

<system time 0> process 1 is running

<system time 1> process 1 is running

<system time 2> process 2 is running

<system time 3> process 2 is running

<system time 4> process 1 is running

<system time 5> process 1 is running

<system time 6> process 3 is running

<system time 7> process 3 is running

<system time 8> process 2 is running

<system time 9> process 2 is running

<system time 10> process 1 is running

<system time 11> process 1 is running

<system time 12> process 4 is running

<system time 13> process 4 is running

<system time 14> process 3 is running

<system time 15> process 3 is running

<system time 16> process 5 is running

<system time 17> process 5 is running

<system time 18> process 6 is running

<system time 19> process 6 is running

<system time 20> process 2 is running


<system time 21> process 2 is running

<system time 22> process 1 is running

<system time 23> process 1 is running

<system time 24> process 4 is running

<system time 25> process 4 is running

<system time 26> process 4 is finished....... 

<system time 26> process 3 is running

<system time 27> process 3 is finished....... 

<system time 27> process 5 is running

<system time 28> process 5 is running

<system time 29> process 6 is running

<system time 30> process 6 is running

<system time 31> process 2 is running

<system time 32> process 2 is running

<system time 33> process 1 is running

<system time 34> process 1 is running

<system time 35> process 1 is finished....... 

<system time 35> process 5 is running

<system time 36> process 5 is running

<system time 37> process 5 is finished.......

<system time 37> process 6 is running

<system time 38> process 6 is running

<system time 39> process 2 is running

<system time 40> process 2 is finished.......

<system time 40> process 6 is running

<system time 41> process 6 is finished.......

============================================================

Average waiting time : 22.50

Average response time : 4.00

Average turnaround time: 29.33 

============================================================
