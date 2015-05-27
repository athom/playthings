#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    struct stat st;

    fd = open("./hello.txt", O_RDWR);
    if (fd == -1)
    {
        printf("can not open hello.txt\n");
        return -1;
    }
    fstat(fd, &st);

    int len = st.st_size;

    void* bufp;
    bufp = mmap(NULL, len, PROT_WRITE, MAP_SHARED, fd, 0);
    if (bufp == NULL)
    {
        printf("can not mmap hello.txt\n");
        return -1;
    }

    char* buf = (char*)(bufp);
    buf[0] = 'J';

    return 0;
}
