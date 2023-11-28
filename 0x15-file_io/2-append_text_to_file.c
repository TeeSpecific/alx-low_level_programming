#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filenmae: filename.
 * @text_content: added contents.
 *
 * Return: If the function fails or filename is NULL - -1.
 * If the file does not exist the user lacks write permissions - -1.
 * or id it fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int nletters;
	int rwr;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (nletters = 0; text_content[nletters]; nletters++)
			;

		rwr = write(fd, text_content, nletters);

		if (rwr == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
