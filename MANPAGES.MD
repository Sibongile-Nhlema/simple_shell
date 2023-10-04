on 1.0 "04 Oct. 2023" | "simple-shell" Documentation (man pages)

Custom Simple Shell using C
====
The Seashell is a command-line interface that allows users to interact with an operating system by executing commands.

DESCRIPTION
===========
The shell is able to read user input, parse the input into commands and arguments, execute the commands and display the output to the user.

ENVIORNMENT VARIABLES
=====================
We have configured the shell to be able to create environments, get the created environments as well as unset environments.

EXIT STATUS
===========
The shell has a exit fetaure built-in that can handle agruments in the same way a typical UNIX shell operates.

BUILT-IN COMMANDS
=================
cd
exit
setenv
unsetenv
getenv
exit
getline

OTHER HANDLERS
==============
&&
||
;

LIMITATIONS
===========
The shell has not employed the use of the following functions:
1. Strtok
2. printf
3. ....
4. non-custom getline
5. ...
6. ....

Options
-------

-v, --version

:   Prints the current version number.


BUGS
====

See GitHub Issues: <https://github.com/Maddily/simple_shell/issues>

AUTHORS
=======

1. Sibongile Nhlema <sibongile.nhlema@gmail.com>
2. Mayada Saeed <mayadasaeeddev@gmail.com.com>

SEE ALSO
========

printf(3)
