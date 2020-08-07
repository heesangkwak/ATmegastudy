#include <avr/io.h>
int main(void)
{
   //DDRA = 0xff; // 1 ,2 PIN OUTPUT
   DDRA = 0x0a;
   //DDRE = 0X00; // PE PIN INPUT
	while (1) 
    {
		PORTA = 0x08;
		if ((PINA & 0x04)==0x04) // PE 4번 핀이 마스킹 되었을때 즉 4번핀이 1의 신호를 줄때 LED ON 외부 인터럽트 아닌경우는 인터럽트 걸리는게 아니라 코드 흐름에 따라 되는거같음
		{
			PORTA = 0x02;
		}
	}
}

