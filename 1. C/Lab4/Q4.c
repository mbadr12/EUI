#include<stdio.h>
#define WINDOWS	1
#define LINUX	2
#define MAC		3
/*Choose your OS
* WINDOWS	
* LINUX	
* MAC		
*/

#define OS	WINDOWS
void main(void)
{
#if OS==WINDOWS
	printf("Welcome on WIndows");
#elif OS==LINUX
	printf("Welcome on Linux");
#elif OS==MAC
	printf("Welcome on MAC");
}