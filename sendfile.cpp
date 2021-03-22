#include "sendfile.h"

#include <stddef.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>

ssize_t sendfile(int out_fd, int in_fd, off_t *offset, size_t count) {
    off_t len = count;
    if (sendfile(out_fd, in_fd, (offset ? *offset : 0), &len, NULL, 0)) {
        return -1;
    }

    return len;
}