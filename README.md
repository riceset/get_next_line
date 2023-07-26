<h1 align="center">
	Get Next Line
</h1>

<p align="center">
    <img src="https://github.com/riceset/riceset/blob/main/42_badges/get_next_linee.png" />
</p>

## Summary

> <i>The 42 school's get_next_line project is where we learn to read</i>
> <i>from a file descriptor, as well as the use of static variables.</i>
> <i>This function returns a single line from a given file descriptor.</i>
> <i>If called in a loop, get_next_line returns the entire contents of a file,</i>
> <i>line by line until it reaches the end of the file.</i>
> <i>It can be compiled specifying any buffer size.</i>

## Getting started

First, clone this repository and `cd` into it:

```zsh
$ git clone https://github.com/riceset/get_next_line; cd get_next_line
```

Compile the executable file with:

```zsh
$ make
```

## Usage
This function is not a stand-alone program, its files must be included and compiled within another project.

Example ``main.c``:
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
```
Compilation:
```bash
gcc main.c get_next_line.c get_next_line_utils.c
```
``BUFFER_SIZE`` can be specified at compilation to override the default ``BUFFER_SIZE``:
```bash
gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
Execution:
```bash
./a.out [file]
```
Output should show the entire contents of the given file.

Execution with stdin:
```bash
./a.out /dev/tty
```
Program will wait for input, then once the enter key is pressed, print out the input as well as get_next_line's output. The process can be killed with ``ctrl-c``.
