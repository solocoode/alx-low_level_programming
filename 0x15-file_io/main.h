#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters);

/*
 * create_file - Creates a file with it's name and writes text_content to it
 * @filename: A pointer to the name of the file.
 * @text_content: The content to write to the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         O/w - 1 (Success).
 */
int create_file(const char *filename, char *text_content);

/*
 * append_text_to_file - Appends text_content to an existing file.
 * @filename: A pointer to the name of the file.
 * @text_content: The content to append to the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         O/w - 1 (Success).
 */
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
