
WELCOME TO SHEAVEN!
simple_shell project
Description
In this project, we will create a simple shell which will execute basic functions, emulating the same processes done by sh. We started off by creating a flowchart and defining the main skelleton of our project, setting goals and managing the entire project through the scrum metodology.
We researched many new concepts, starting from the input of commands through the command interpreter, to the parents and child processes always taking care of the memory management to avoid any leak.

Finally the project has been merged and fully functioning.
Program download
To download this program, you must go to this github repo and download it:
https://github.com/matcls/simple_shell
Once in your local repo, you can complile it with the following command:
gcc -Wall -Werror -Wextra -pedantic *.c 
Execution:
There are two modes
Interactive mode:
$ ./a.out
     $ [write here your commands]

Non-interactive mode
$ echo "[put_commands and_arguments]" | ./a.out
Built-ins
    • env
    • exit
    • help
    • pwd
Examples
    1. Absolute path commands
    • non interactive
$ echo "/bin/pwd" | ./a.out
$ /home/simple_shell
    • interactive mode
$ ./a.out
./$ /bin/ls
simple_shell.c
./$ exit
$
    2. short command
    • non interactive
$ echo "pwd" | ./a.out
$ /home/simple_shell
    • interactive mode
$ ./a.out
./$ echo welcome to shell
welcome to shell
./$ exit
$
    3. built-ins
    • non interactive
$ echo "pwd" | ./a.out
$ echo "pwd" | ./a.out

    • interactive mode
$ ./a.out
./$ cd
$ pwd
/home
Some error output
$ ./a.out
./$ cd..
command not found: cd..
$ ..
$  ..: Permission denied
2
Project files
File
Description
AUTHORS
File names and email of project’s owners
Readme.md
Description and examples of project
_dupenv.c
Enviroment variable duplicate
_dupenv - duplicates enviroment variables
_execute.c
Finds and executes commands
find_command – finds function from command line
_executes: sorts if builtin or PATH
_free_data.c
Frees data allocated











Manual page
You can find all the information on our man page
$ ./man_1_simple

Flow chart

Can be found at this address:


