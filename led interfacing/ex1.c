#include <LPC21xx.h> //reg file
void delay()
		{
		for(int i=0;i<300;i++);
		}
int main(){
	PINSEL0 = 0X00000000;
	IO0DIR = 0X00000002;
	if(IO0PIN & 0X01 == 0X01){
		IO0SET |= (1<<1);//=0x0000 0001
	delay();}
			else{
				IO0CLR |= (1<<1);
				delay();
			
		}
		return 0;
		}
