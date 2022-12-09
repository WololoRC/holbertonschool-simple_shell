#holberton-simple-shell

Working team:

* Joaquin Jones
[@WololoRC](https://github.com/WololoRC)
* Juan Valle
[@juanivalle](https://github.com/juanivalle)



> Index

- [Objective](#objective)
- [Description](#description)
- [Flowchart](#flowchart)

## Objective
Make a simple shell, this is a project made by Holberton School for students to keeplearning and improve their skills.

## Description
Super-simple-shell executes the basic commands of a classic linux terminal,The way it works is the following: Through the getline() function, it receives an input that is later tokenized and placed in an array called **arg[] that -from the beginning of the program- houses memory for about 40 type pointers. char, from there it is passed as an argument to the get_stat() function. **arg[] is reallocated in each iteration of the main function that runs in a loop, this way we make sure we don't run out of memory for any possible number of arguments.
Once inside get_stat() the function initializes a linked list that contains all the addresses of the $PATH variable, where it is already concatenated with the path that contains each node each argument tokenized in the main function.
Continuing the flow of get_stat(), it is evaluated if the arguments sent are already enough to contain a path or if it is necessary to go to a node of the linked list. If neither arv[0] nor path->data contains a valid value to execute, an error message is printed to the screen.
To finish, the execution syntax (PROCESS) is cloned with fork() and it is evaluated in which process the program is running, if it is the child (child_p == 0), execve is executed. if execve fails, the process is killed with kill(),

At the end, the entire linked list is released.
## File Description
- **2-simple-shell.c** - contains the main function.
- **_getenv.c** - the getenv function get value from enviroment variable, add_node add a node on a path_list list,
		get_path initalizes a path_list list and the last function free_path free's a path_node list.
- **aux_functions.c** - contains some functions that have been used.
- **get_arg2.c** - turns the stirng passed by main in arguments for execve.
- **header.h** - header file which contains all function prototypes used..
- **man_3_printf** - manual of out shell.

### Compilation & Testing
* The shell function was coded on an Ubuntu 20.04 LTS machine with gcc version 4.8.4.

We compile with:
* gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
### How to use it

In order to use this shell, in a terminal, first run the program:

`./hsh`

It will then display a simple prompt and wait for commands.

`$`

A command will be of the type `$ command`
This shell can handle two types of commands: builtins and normal program.

### List of built-ins
* exit  
    Exits the shell.
### Command
Every Program in $PATH It Support ls

It Handle Path ls /tmp

it Handle Options Like ls -l

it Handle All Three Togther Like ls -l /tmp

## Flowchart
![Flowcharts](https://app.code2flow.com/3WW4QD.png)
