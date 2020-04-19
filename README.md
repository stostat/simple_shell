 ![Image of holb](https://latorredev.com/assets/Img/Certifications/Holberton.png)

---
# WELCOME TO SHEAVEN!

## simple_shell project

---

Description

>In this project, we will create a simple shell which will execute basic functions, emulating the same processes done by sh. We started off by creating a flowchart and defining the main skelleton of our project, setting goals and managing the entire project through the scrum metodology.We researched many new concepts, starting from the input of commands through the command interpreter, to the parents and child processes always taking care of the memory management to avoid any leak.
Finally the project has been merged and fully functioning.
---
### Program download
>To download this program, you must go to this github repo and download it:

    https://github.com/matcls/simple_shell

>Once in your local repo, you can complile it with the following command:

    gcc -Wall -Werror -Wextra -pedantic *.c

### Execution:
>There are two modes
    
    Interactive mode:
>$ ./a.out

    $ [write here your commands]

>Non-interactive mode

    $ echo "[put_commands and_arguments]" | ./a.out

### Built-ins

    • env
    • exit
    • help
    • pwd
### Examples
    1. Absolute path commands
    • non interactive

$ echo "/bin/pwd" | ./a.out

    $ /home/simple_shell

    • interactive mode

>$ ./a.out

    ./$ /bin/ls

>simple_shell.c

./$ exit

$

    2. short command
    • non interactive

$ echo "pwd" | ./a.out

>$ /home/simple_shell

    • interactive mode

>$ ./a.out

    ./$ echo welcome to shell

>welcome to shell

    ./$ exit

>$

    3. built-ins
    • non interactive

$ echo "pwd" | ./a.out

    $ echo "pwd" | ./a.out

    • interactive mode

>$ ./a.out

    ./$ cd
>$ pwd

    /home

### Some error output

>$ ./a.out

    ./$ cd..

>command not found: cd..

    $ ..

>$  ..: Permission denied

    2

---
### Project files

|:- File      -:|:- Description -: |
|:------------ | ----------: |
| AUTHORS     | File names and email of project’s owners|
Readme.md |Description and examples of project|
|_dupenv.c | Enviroment variable duplicate 
|| _dupenv - duplicates enviroment variables |
|_execute.c | Finds and executes commands |
| | find_command – finds function from command line |
|| _executes: sorts if builtin or PATH |
| _free_data.c  |Frees data allocated |
|| _free - frees all data|
|| free_env - frees enviroment variable |
|| free_args - Frees double pointer |
|| free_all - calls all free functions |
|| free_array - frees arrays |
| _getenv.c | functions that get enviroment and handle it |
| | _getenv |
|| free_PATH - frees PATH variable |
|| _myenv2 | prints env variable |
| _launch.c | executes command line |
| builtins.c | contains builtin functions |
|| _cd |
|| _help |
|| printwd |
|| myexit |
| exec_path.c | contains function that reads and executes path|
| get_help.c | aux functions for help builtin|
|| get_help |
|| more_help |
| handle_input.c | functions that read and parse the command line|
|init_data.c | data initialization at start of program |
| loop_prompt.c | displays prompt |
| main.c | main function that calls all other functions |
| shell.h | header |







### Manual page

You can find all the information on our man page

    $ ./man_1_simple



>Flow chart an be found at this address:

>>https://app.diagrams.net/#G1LC_F4Ss5qHXNA5NKIuUAo5PHcCVRhmeV

***

### *BLOG*
A blog with literature about this specific topic has been writen, this blog can be found at the following link:

    https://medium.com/@fafegu25/linux-commands-ls-and-its-option-l-51d720769d6a
    
---
#thanks

