#include <stdio.h>
#include <malloc.h>
char buf[100];

void MemoryDump(int start, int length);

int main(int argc, char *argv[])
{
	int start = 0x09000000;
	int length = 500;

	char c = 'A';
	int i = 1;
	float a = 2.0;
	double d = 3.14;
	void *p = malloc(100); //(void*) buf//0x80000000
	
	*(double *)p = d;

	MemoryDump((int)buf, length);
	//printf("c=%8c [0x%08x]\n", c, &c);
	//printf("i=%8c [0x%08x]\n", i, &i);
	//printf("f=%8f [0x%08x]\n", a, &a);
	//printf("d=%8f [0x%08x]\n", d, &d);
	//printf("p=%8f [0x%08x]\n", *(double *)p, p);
}

void MemoryDump(int start, int length) {
	void *vp = (void *)start;
	int i = 0;
	while (i < length) {
		//char *cp = (char *)vp;
		//char c = *cp;
		char c = *((char *)vp);
		i++;
		printf("0x%02x  ", c);
	}
}
