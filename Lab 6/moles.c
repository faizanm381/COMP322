#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    FILE* fp = fopen("./lab6.log", "a");
    if (fp != 0)
    {
		fprintf(fp, "Pop mole %s\n", argv[argc-1]);
        fclose(fp);
    }
    return 0;
}
