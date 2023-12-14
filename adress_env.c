#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("%p\n", env);
	printf("%p\n", environ);

}
