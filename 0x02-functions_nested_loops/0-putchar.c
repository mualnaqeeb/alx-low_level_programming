#include "main.h"
int main(void)
{
	char *sh = "Main";

	while (*sh)
	{
		_putchar(*sh);
		sh++;
	}
	_putchar('\n');

	return (0);
}
