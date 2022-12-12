# GET_NEXT_LINE
This project is about creating a function that allows reading a line ending with a newline character ('\n') from a file descriptor, without knowing its size beforehand. One of the goal of this project is to learn a highly interesting new concept in C programming: static variables, and to gain a deeper understanding of allocations, whether they happen on the stack memory or in the heap memory, the manipulation and the life cycle of a buffer, the unexpected complexity implied in the use of one or many static variables.

## STATIC VARIABLES
Static variables have a property of preserving their value even after they are out of their scope. This means, static variables preserve their previous value in their previous scope and are not initialized again in the new scope.

## FILE DESCRIPTOR
In Unix and Unix-like computer operating systems, a file descriptor (FD) is a process-unique identifier (handle) for a file or other input/output resource, such as a pipe or network socket.
File descriptors typically have non-negative integer values, with negative values being reserved to indicate "no value" or error conditions.

```
Standard Streams:

In computer programming, standard streams are interconnected input and output communication channels between a computer
program and its environment
when it begins execution.
```
The three input/output (I/O) connections are called standard input (stdin), standard output (stdout) and standard error (stderr). 
```
Standard input:

	Standard input is a stream from which a program reads its input data.
  The program requests data transfers by use of the read operation. 
  Not all programs require stream input. 
  For example, the dir and ls programs (which display file names contained in a directory) may take command-line arguments, 
  but perform their operations without any stream data input.
```
The file descriptor for standard input is 0; the POSIX <unistd.h> definition is STDIN_FILENO; the corresponding C <stdio.h> variable is FILE* stdin.
```
Standard output:

Standard output is a stream to which a program writes its output data. 
The program requests data transfer with the write operation. Not all programs generate output. 
For example, the file rename command (called mv, move, or ren) is silent on success.
Unless redirected, standard output is inherited from the parent process. 
In the case of an interactive shell, that is usually the text terminal which initiated the program.
```
The file descriptor for standard output is 1 (one); the POSIX <unistd.h> definition is STDOUT_FILENO; the corresponding C <stdio.h> variable is FILE* stdout.
```
Standard error:

Standard error is another output stream typically used by programs to output error messages or diagnostics. 
It is a stream independent of standard output and can be redirected separately.
```
