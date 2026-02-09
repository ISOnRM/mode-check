//
#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static void die(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    _exit(1);
}

int main(int argc, char **argv)
{
	unsigned int want = STATX_MODE;

	struct statx stx;

	memset(&stx, 0, sizeof(stx));

	int ret;

	char resp[PATH_MAX];

	for (argv++; *argv; argv++)
	{
		ret = statx(AT_FDCWD, *argv, AT_STATX_SYNC_AS_STAT, want, &stx);
		if (ret != 0)
		{
			die("statx");
		}

		if (!(realpath(*argv, resp)))
		{
			die("realpath");
		}

		if (stx.stx_mask & STATX_MODE)
		{
			printf("(%s)'s mode: %04o/%c%c%c%c%c%c%c%c%c\n",
				   resp,
				   stx.stx_mode & 0777,
				   stx.stx_mode & S_IRUSR ? 'r' : '-',
				   stx.stx_mode & S_IWUSR ? 'w' : '-',
				   stx.stx_mode & S_IXUSR ? 'x' : '-',
				   stx.stx_mode & S_IRGRP ? 'r' : '-',
				   stx.stx_mode & S_IWGRP ? 'w' : '-',
				   stx.stx_mode & S_IXGRP ? 'x' : '-',
				   stx.stx_mode & S_IROTH ? 'r' : '-',
				   stx.stx_mode & S_IWOTH ? 'w' : '-',
				   stx.stx_mode & S_IXOTH ? 'x' : '-');
		}
	}
	return 0;
}

