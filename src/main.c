#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

/**
 * @brief Maps the file content on the stack, don't forget to free
 * @param fd File descriptor
 * @return NULL on error, Pointer to buffer on success
 */
char* get_file_content(int fd) {
    off_t raw_len;
    char *raw_ptr;
    char *file_content;

    raw_len = lseek(fd, 0, SEEK_END);
    if (raw_len == -1) {
        printf("error: failed to lseek %d: %s\n", fd, strerror(errno));
        return NULL;
    }

    raw_ptr = mmap(0, raw_len, PROT_READ, MAP_PRIVATE, fd, 0);
    if (raw_ptr == (void*)-1) {
        printf("error: failed to mmap %d: %s\n", fd, strerror(errno));
        return NULL;
    }

    file_content = malloc(raw_len + 1);
    file_content[raw_len] = '\0';
    strncpy(file_content, raw_ptr, raw_len);
    munmap(raw_ptr, raw_len);

    return file_content;
}

int main(int argc, char** argv) {
    char* buffer = NULL;
    int fd = 0;

    if (argc < 2) {
        printf("error: please provide an input sequence: ./syntax_analyzer <input_file>\n");
        return 1;
    }

    fd = open(argv[1], O_RDONLY, 0600);
    if (fd == -1) {
        printf("error: failed to open file %s: %s\n", argv[1], strerror(errno));
        return 1;
    }

    buffer = get_file_content(fd);
    if (buffer == NULL) {
        printf("error: failed to get file content\n");
        return 1;
    }

    printf("info: successfully mapped file content: %s\n", buffer);

    free(buffer);

    return 0;
}