# operating_system-practical
#practical-1:: Operations on Processes

Set A

(1) Implement the C Program to create a child process using fork(), display parent and child
process id. Child process will display the message “I am Child Process” and the parent
process should display “I am Parent Process”.

(2) Write a program that demonstrates the use of nice() system call. After a child process is
started using fork(), assign higher priority to the child using nice() system call.

Set B

(1) Implement the C program to accept n integers to be sorted. Main function creates child
process using fork system call. Parent process sorts the integers using bubble sort and
waits for child process using wait system call. Child process sorts the integers using
insertion sort.

(2) Write a C program to illustrate the concept of orphan process. Parent process creates a
child and terminates before child has finished its task. So child process becomes orphan
process. (Use fork(), sleep(), getpid(), getppid()).

Set C

(1) Implement the C program that accepts an integer array. Main function forks child
process. Parent process sorts an integer array and passes the sorted array to child process
through the command line arguments of execve() system call. The child process uses
execve() system call to load new program that uses this sorted array for performing the
binary search to search the particular item in the array.

(2) Implement the C Program to create a child process using fork(), Using exec() system call,
child process will execute the program specified in Set A(1) and parent will continue by
printing message “I am parent “.

#practical-2:: Operations on Processes

Set A

Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It
accepts the command, tokenize the command line and execute it by creating the child process.
Also implement the additional command ‘count’ as
myshell$ count c filename: It will display the number of characters in given file
myshell$ count w filename: It will display the number of words in given file
myshell$ count l filename: It will display the number of lines in given file

Set B

Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It
accepts the command, tokenize the command line and execute it by creating the child process.
Also implement the additional command ‘list’ as
myshell$ list f dirname: It will display filenames in a given directory.
myshell$ list n dirname: It will count the number of entries in a given directory.
myshell$ list i dirname: It will display filenames and their inode number for the files in a given directory.

Set C

(1)

Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It
accepts the command, tokenize the command line and execute it by creating the child process.
Also implement the additional command ‘typeline’ as
myshell$ typeline n filename: It will display first n lines of the file.
myshell$ typeline -n filename: It will display last n lines of the file.
myshell$ typeline a filename: It will display all the lines of the file.

(2)

Write a C program that behaves like a shell which displays the command prompt ‘myshell$’. It
accepts the command, tokenize the command line and execute it by creating the child process.
Also implement the additional command ‘search’ as
myshell$ search f filename pattern : It will search the first occurrence of pattern in the given
file
myshell$ search a filename pattern : It will search all the occurrence of pattern in the given file
myshell$ search c filename pattern : It will count the number of occurrence of pattern in the
given file

#practical-3:: CPU Scheduling

Set A:

i. Write the program to simulate FCFS CPU-scheduling. The arrival time and first CPU-
burst for different n number of processes should be input to the algorithm. Assume that
the fixed IO waiting time (2 units). The next CPU-burst should be generated randomly.
The output should give Gantt chart, turnaround time and waiting time for each process.
Also find the average waiting time and turnaround time.

ii. Write the program to simulate Non-preemptive Shortest Job First (SJF) -scheduling. The
arrival time and first CPU-burst for different n number of processes should be input to the
algorithm. Assume the fixed IO waiting time (2 units). The next CPU-burst should be
generated randomly. The output should give Gantt chart, turnaround time and waiting
time for each process. Also find the average waiting time and turnaround time.

Set B:

i. Write the program to simulate Preemptive Shortest Job First (SJF) -scheduling. The
arrival time and first CPU-burst for different n number of processes should be input to the
algorithm. Assume the fixed IO waiting time (2 units). The next CPU-burst should be
generated randomly. The output should give Gantt chart, turnaround time and waiting
time for each process. Also find the average waiting time and turnaround time.

ii. Write the program to simulate Non-preemptive Priority scheduling. The arrival time and
first CPU-burst and priority for different n number of processes should be input to the
algorithm. Assume the fixed IO waiting time (2 units). The next CPU-burst should be
generated randomly. The output should give Gantt chart, turnaround time and waiting
time for each process. Also find the average waiting time and turnaround time.

Set C:

i. Write the program to simulate Preemptive Priority scheduling. The arrival time and first
CPU-burst and priority for different n number of processes should be input to the
algorithm. Assume the fixed IO waiting time (2 units). The next CPU-burst should be
generated randomly. The output should give Gantt chart, turnaround time and waiting
time for each process. Also find the average waiting time and turnaround time.

ii. Write the program to simulate Round Robin (RR) scheduling. The arrival time and first
CPU-burst for different n number of processes should be input to the algorithm. Also
give the time quantum as input. Assume the fixed IO waiting time (2 units). The next
CPU-burst should be generated randomly. The output should give Gantt chart, turnaround
time and waiting time for each process. Also find the average waiting time and
turnaround time.

#practical-4:: Demand Paging

Set A

i. Write the simulation program to implement demand paging and show the page
scheduling and total number of page faults for the following given page reference string.
Give input n as the number of memory frames.
Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
1) Implement FIFO
2) Implement LRU

Set B:

I. Write the simulation program to implement demand paging and show the page
scheduling and total number of page faults for the following given page reference string.
Give input n as the number of memory frames.
Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
1) Implement OPT
2) Implement MFU

Set C:

I. Write the simulation program to implement demand paging and show the page
scheduling and total number of page faults for the following given page reference string.
Give input n as the number of memory frames.
Reference String: 2,5,2,8,5,4,1,2,3,2,6,1,2,5,9,8
1) Implement MRU
