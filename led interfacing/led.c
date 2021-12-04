#include<lpc21xx.h>
int delay(unsigned int w)
{
unsigned int a,b;
for(a=0;a<w;a++)
	for(b=0;b<200;b++);
}

int main()
{
PINSEL1 = 0X00000000;
IODIR0 = 0XFFFFFFFF;
while(1)
{
IOSET0 = 0XFFFFFFFF;
delay(25000);
IOCLR0 = 0XFFFFFFFF;
delay(25000);
}
}