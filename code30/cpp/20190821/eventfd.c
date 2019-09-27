#include <sys/eventfd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>             /* Definition of uint64_t */

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

int
main(int argc, char *argv[])
{
    int efd, j;
    uint64_t u;
    ssize_t s;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num>...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    efd = eventfd(10, 0);//eventfd的第一个参数代表的是内核上的计数器
    if (efd == -1)
        handle_error("eventfd");

    switch (fork()) {
    case 0:
        for (j = 1; j < argc; j++) {
            printf("Child writing %s to efd\n", argv[j]);
            u = strtoull(argv[j], NULL, 0);
                    /* strtoull() allows various bases */
            s = write(efd, &u, sizeof(uint64_t));//write可以写多次, 每执行一次，就会执行一次加法
            if (s != sizeof(uint64_t))
                handle_error("write");

			sleep(1);
        }
        printf("Child completed write loop\n");

        exit(EXIT_SUCCESS);

    default:
        //sleep(2);

		for(int idx = 2; idx < argc; ++idx)
		{
			printf("Parent about to read\n");
			s = read(efd, &u, sizeof(uint64_t));// read操作会将计数器的值清0
			if (s != sizeof(uint64_t))
				handle_error("read");
			printf("Parent read %llu (0x%llx) from efd\n",
					(unsigned long long) u, (unsigned long long) u);
			sleep(2);
		}

        exit(EXIT_SUCCESS);

    case -1:
        handle_error("fork");
    }
}
