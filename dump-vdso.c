#include <stdio.h>
#include <string.h>

int
main()
{
	FILE *maps;
	void *vdso_begin, *vdso_end;

	maps = fopen("/proc/self/maps", "r");
	char buf[1024];
	while (fgets(buf, 1024, maps)) {
		if (strstr(buf, "[vdso]")) break;
	}
	fclose(maps);

	sscanf(buf, "%p-%p", &vdso_begin, &vdso_end);
	write(1, vdso_begin, vdso_end - vdso_begin);

	return 0;
}