#include<LPC21XX.H> // header file for lpc2148

void delay(); // delay function

unsigned int i,j,k; // globle variable

unsigned int ar[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90 }; // array data//for anode
//unsigned int ar[3]={0x3f,0x06,0x5b};
int main()

{

PINSEL0=0X00000000; // select port0 as gpio mode

IO0DIR =0X000000FF; // make starting 8 pin as output and other as input of port0

while(1)

{

for(i=0;i<10;i++)

{

IO0SET =ar[i];

delay();

IO0CLR =ar[i];

}

}

return 0;

}

void delay()

{

for(j=0;j<10000;j++);

 }