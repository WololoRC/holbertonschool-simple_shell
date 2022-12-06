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

The printf function prints a message to the screen using a "format string" that includes instructions for mixing multiple strings into the final string to display.

## Description
The sh utility is a command language interpreter that shall execute commands read from a command line string, the standard input, or a specified file. The application shall ensure that the commands to be executed are expressed in the language described in Chapter 2, Shell Command Language.

Pathname expansion shall not fail due to the size of a file.

Shell input and output redirections have an implementation -defined offset maximum that is established in the open file description.

Options:

|  Type |  Make  |
| ------------ | ------------ |
| -c  | Read commands from the command string operand |
| -i  | Specify that the shell is interactive |
| -s  | Read commands from the standard input |

## File Description
- **2-simple-shell.c** - contains the main function.
- **_getenv.c** - the getenv function get value from enviroment variable, add_node add a node on a path_list list,
		get_path initalizes a path_list list and the last function free_path free's a path_node list.
- **aux_functions.c** - contains some functions that have been used.
- **get_arg.c** - turns the stirng passed by main in arguments for execve.
- **main.h** - header file which contains all function prototypes used..
- **man_3_printf** - manual of out shell.

### Compilation & Testing
* The shell function was coded on an Ubuntu 20.04 LTS machine with gcc version 4.8.4.

We compile with:
* gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Flowchart
