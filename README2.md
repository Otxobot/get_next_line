**get_next_line** is a function that reads a line from a file descriptor. 
A line is defined as a sequence of characters followed by a newline character or the end of the file.

The function takes a file descriptor **fd** as its only argument. It reads the file associated with this descriptor, 
one line at a time, and returns the line as a null-terminated string.

The function has a **static** variable save that is used to store any remaining characters from the file after a line has been read. 
This allows the function to pick up where it left off the next time it is called, rather than starting from the beginning of the file again.

The function first checks if the file descriptor is valid and the buffer size is positive. 
If either of these conditions is not met, it returns NULL.

It then calls **ft_read_and_save**, which reads the file and stores any remaining characters in the **save** variable. 
If there is nothing left to read, **ft_read_and_save** returns NULL.

If **ft_read_and_save** returns NULL, the function returns NULL as well. Otherwise, it calls **ft_get_line** to extract the next line from the file. 
This line is returned as a null-terminated string.

Finally, the function calls **ft_save** to update the **save** variable with any remaining characters after the line has been extracted. 
This ensures that the next call to **get_next_line** will start reading from the correct position in the file.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  

**ft_read_and_save** is a function that reads a file descriptor and stores any remaining characters in a string. 
The function takes a file descriptor **fd** and a string **save** as arguments.

The function first allocates memory for a buffer **buff** of size **BUFFER_SIZE + 1** characters. 
It then reads the file associated with the file descriptor **fd** into this buffer in blocks of **BUFFER_SIZE** characters at a time.

The function reads the file until it encounters a newline character or reaches the end of the file. If it encounters an error while reading the file, it frees the memory allocated for the buffer and returns NULL.

After each read, the function appends the contents of the buffer to the **save** string using the **ft_strjoin** function. 
This allows the function to build up the **save** string with the contents of the file.

When the function finishes reading the file, it frees the memory allocated for the buffer and returns the **save** string.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

**ft_get_line** reads a string, **save**, and extracts a substring that ends at the first occurrence of a newline character ('\n'). 
It does this by using the **ft_strchr** function to find the first occurrence of a newline character in **save**.

If **ft_strchr** returns NULL, indicating that no newline character was found, the function returns NULL. Otherwise, the function allocates a new string, **line**, that is the length of the substring ending at the newline character. 
It then uses the **ft_memcpy** function to copy the substring into **line**, and appends a newline character and a null terminator to line. Finally, the function returns the **line** string.

It is important to note that this function uses dynamically allocated memory for the line string, so it is the caller's responsibility to free this memory when it is no longer needed.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

**ft_save** performs the following operations:

It iterates through the string **save** and counts the number of characters up to the first occurrence of a newline character ('\n').

If the newline character is not found, it frees the memory allocated to **save** and sets **save** to NULL, and returns NULL.

Otherwise, the function allocates a new string, **str**, that is the length of the substring of **save** starting from the character after the newline character.

It then uses the **ft_strlcpy** function to copy the substring into **str**, and adds a null terminator to **s**.

It appends a null terminator to **str** and frees the memory allocated to **save**, setting **save** to NULL.

Finally, it returns the new string, **str**.

It is important to note that this function uses dynamically allocated memory for the **s** string, so it is the caller's responsibility to free this memory when it is no longer needed.