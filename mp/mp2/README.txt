# Machine Problem II, due Feb. 12

Part of [ the homework for CS:3620, Spring 2018 ](../)  
by [Douglas W. Jones](http://www.cs.uiowa.edu/~jones/)  
[ THE UNIVERSITY OF IOWA](http://www.uiowa.edu/) [Department of Computer
Science](http://www.cs.uiowa.edu/)

Begin with a copy of Mush, the minimally usable shell.

**a)** Add a line to the header comments saying that you modified the code to
meet the requirements of mp2. Also change the original byline to say
"originally by" instead of just "by". Generally, the most recent author should
be listed first, but all authors who have ever modified the code should be
recorded. **Also** add header comments documenting each function (see the
style guidelines cited below).

**b)** The original code contains the naked constant 100 in several places.
One of these is the limit on the input line lencth. Use a `#define` for this,
defining the symbolic name `LINE_LENGTH`. The second is simply wrong. If the
input line is 100 characters and there is at least one character between each
argument, there cannot be 100 arguments. So, define `MAX_ARGS` as an
appropriate function of `LINE_LENGTH`.

**c)** The original code is grossly unsafe. If you type too many charaters on
an input line, it fails. Fix the code so that there are no points where it
will fail because of overly-long input lines, too many arguments, or similar
faults.

If a line is too long, the part of the line that was successfully read should
be processed after a compact error message is displayed saying "overlength
line: ", followed by the characters that were not processed. Similarly, if
there are too many arguments for the argument vector (but only if this is
possible, see part b) you might output "too many arguments ", and then the
excess text.

**d)** The original code has no provisions for a graceful exit. The only way
to terminate Mush is to press Control-C, killing it. Fix it so it exits
normally when it detects an end-of-file in the input, and fix it so that it
has a built-in command, `exit` that exits normally.

All of your code must conform, as much as is possible, to the manual of style:

\-- [
http://www.cs.uiowa.edu/~jones/syssoft/style.html](http://www.cs.uiowa.edu/~jones/syssoft/style.html)

Your solution must be in a file named `mp2.c` (all lower case). Submit your
solution using the coursework submission tools documented at:

\-- [ https://clas.uiowa.edu/linux/help/start/submit
](https://clas.uiowa.edu/linux/help/start/submit)

In short, you will type the shell command `submit`, with no arguments, and
when it prompts for a file name, you will type `mp2.c`. and then an extra
carriage return to indicate that there is only one file in your submission.
When it prompts for a course, type `CS3620` and when it prompts for an
assignment directory, enter `mp2`.

Note, file names on Unix/Linux systems are case sensitive! That includes the
course name. If you type `cs3620`, it will not work.

