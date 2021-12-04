#include<lpc214x.h>

#define bit(x) (1<<x)
#define delay for(i=0;i<1000;i++);
/*pin config p0.0 - p0.7 -d0-d7
p0.8-rs
po.9-rw
p0.10-en*/

unsigned int i;

void lcd_int();
void dat(unsigned char);//
void cmd(unsigned char);
void string(unsigned char *);

void main()
{
    IO0DIR|=0XFFF;//binary-0000 0000 0000 0000 0000 1111 1111
   // lcd_int();
	cmd(0x0c);//DISPLAY ON
	cmd(0x38);//SELECT 1ST LINE 1ST BIT
	cmd(0x01);//CLEAR DISPLAY SCREEN
  cmd(0x80); // cmd(0xC0) for second line
    string("Hello ");
    while(1) {
        cmd(0x1C);// cmd(0x1c) for towards right
        delay;
    }
}

/*void lcd_int()
{
    cmd(0x30);// for 1 line and for 2 line send 0x38 see in cmd of lcd
    cmd(0x0c);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}*/

void cmd(unsigned char a)
{
    IO0PIN&=0x00; //io pin ox00
   IO0PIN|=(a<<0);//cmd value b'0000 0000 0000 0000 0000 0000 0011 0000
    IO0CLR|=bit(8);                //rs=0 , rs to pin 8 set po.8 to 0xx8(bit(8)=0x08)
    IO0CLR|=bit(9);                //rw=0 write operation
    IO0SET|=bit(10);               //en=1 high send high to low to latch the cmd
    delay;
    IO0CLR|=bit(10);               //en=0 low
}

void dat(unsigned char b)
{
    IO0PIN&=0x00;
    IO0PIN|=(b<<0);
    IO0SET|=bit(8);                //rs=1
    IO0CLR|=bit(9);                //rw=0
    IO0SET|=bit(10);               //en=1
    delay;
    IO0CLR|=bit(10);               //en=0
}

void string(unsigned char *p)//p is pointing to 1st char ie H
{
    while(*p!='\0') {
        dat(*p++);
    }
}