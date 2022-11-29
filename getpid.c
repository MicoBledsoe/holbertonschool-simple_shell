#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
printf("%d", (int)getpid());
return (0);
}
