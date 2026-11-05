#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef O_BINARY
#define O_BINARY 0
#endif

/*
 * Task 6: Evaluate the cost of system calls and buffer size.
 * Function copies src to dst using specified buffer size and counts read() calls.
 */
long copy_file(const char *src, const char *dst, size_t bufsize)
{
    char buf[8192];
    int in = open(src, O_RDONLY | O_BINARY);
    if (in < 0) return -1;
    int out = open(dst, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0644);
    if (out < 0) { close(in); return -1; }
    long calls = 0;
    ssize_t n;
    while (1) {
        n = read(in, buf, bufsize);
        calls++;
        if (n <= 0) break;
        if (write(out, buf, n) != n) break;
    }
    close(in);
    close(out);
    return calls;
}

int main(void)
{
    const char *src = "temp_10k_input.dat";
    const char *dst = "temp_output.dat";

    /* Create test file of 10,000 bytes */
    FILE *f = fopen(src, "wb");
    if (!f) {
        perror("Failed to create test file");
        return 1;
    }
    for (int i = 0; i < 10000; i++) {
        fputc((char)(i % 256), f);
    }
    fclose(f);

    printf("--- Task 6: System Call Buffer Size Measurement ---\n");
    printf("buffer %4d bytes: %5ld read() calls\n", 1, copy_file(src, dst, 1));
    printf("buffer %4d bytes: %5ld read() calls\n", 512, copy_file(src, dst, 512));
    printf("buffer %4d bytes: %5ld read() calls\n", 4096, copy_file(src, dst, 4096));

    /* Cleanup temporary files */
    unlink(src);
    unlink(dst);

    return 0;
}