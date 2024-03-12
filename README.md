Clone this project with git clone https://github.com/Martin-Bonte/Minishell

What is it

A simple shell in which you can write commands such as ls or other any existed unix binaries.
Pipes and multi-processes line commands are not handled.
How to use

 - First build the project executing  [make]
 - Launch on a command file with     [./mysh]     file
 - Launch with piped commands with echo     ["command" | ./mysh]
 - Launch as normal mode with     [./mysh]
 - Exit shell pressing     [^D]

the [ ] have not to be written

The code respects Epitech-Norm and contains no memory leak and no error.
Notice : custom built-in cd env setenv unsetenv have to be written
