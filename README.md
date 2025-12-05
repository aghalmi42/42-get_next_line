# get_next_line - 42 Project

## 📚 Description

**get_next_line** is a project from the 42 curriculum that consists in writing a function capable of reading, efficiently, one line at a time from a file descriptor.
The function must return each line read, including the newline character, and work with any type of file or standard input.

This project is ideal for practicing memory management, buffer handling, and the use of system calls such as `read`.

## 🛠️ Features

- Line-by-line reading from one or multiple files (or stdin)
- Efficient buffer management
- Supports multiple file descriptors simultaneously
- Returns each line, with or without a newline
- Follows the required prototype:
```c
char *get_next_line(int fd);
```
## 📂 Project Structure

- `get_next_line.c`: Main function and reading logic
- `get_next_line_utils.c`: Utility functions (string handling, memory, etc.)
- `get_next_line.h`: Header containing the prototype and definitions
- `Makefile`: Compilation rules

## 🚀 Usage

### 1. Compilation

```bash
make
```

### 2. Use in your projects

Include the header in your code:

```c
#include "get_next_line.h"
```

Example usage:

```c
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## 📝 Constraints

- Must follow the required prototype
- Proper memory management (no leaks)
- Must work with multiple file descriptors in parallel
- Forbidden to use non-authorized libc functions

## 💡 Tips

- Test with files of different sizes and contents
- Check behavior at end-of-file and with empty files
- Use `valgrind` to detect memory leaks
- Follow the 42 coding standard (Norminette)
