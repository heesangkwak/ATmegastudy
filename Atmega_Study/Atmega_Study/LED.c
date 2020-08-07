//#include <avr/io.h>

//void time_sec(int time);
//
//int main(void)
//{
	//
	//DDRA = 3;
    //while (1) 
    //{
		////for (int i=0 ; i<256;i++)
		//PORTA = 3;
		////PORTA = i;		// 책에서 이내용을 설명하고 싶었던것 같음 PORTA 0xff = PORTA 255
		////time_sec(1);
		//
	//}
//}
//
//void time_sec(int time)
//{
	//volatile int i,j,k;
	//for (k =0; k < time ; k++)
		//for (i = 0 ; i <1000; i++)
			//for(j = 0 ; j<500;j++)
					//;			
//}

//#include <avr/io.h>
//#include <stdlib.h>
//#define __DELAY_BACKWARD_COMPATIBLE__ // Dealy 함수에 상수가 아닌 변수,인수를 사용할때에 선언해주어야한다
//#define F_CPU 16000000UL //cpu 의 처리속도 16Mhz 를 선언해줌 ,delay.h 에 F_CPU 가 있어서 미리 선언해준다 UL = unsigned long
//#include <util/delay.h>
//
//int main (void)
//{	
	//DDRA = 0xff;
	//while (1){
	//PORTA = rand()%256; //0~255사이의 값이 출력되게 설정 나머지 값은 나눈값보다 클수없다
	//_delay_ms ((1500); //50 + 1 을하는건 51까지로 나누면되지만 0일경우 0값이 나와 안됨 1은 약간 보험느낌 
	////_delay_ms(100 ~ 5000) 0.1초~ 5초 사이로 동작하도록 설정한다.	
	//}
//}

#include <avr/io.h>
#include <stdlib.h>
#define __DELAY_BACKWARD_COMPATIBLE
#define F_CPU 16000000UL
#include <util/delay.h>

//int main(void)
//{
	//DDRA = 0xff;
	//int num = 1;
	//while (1)
	//{	
		//PORTA = num;
		//num = num << 1;
		//_delay_ms(1000);
		//if (num >255)
			//num = 1;
//
	//}
//}
int main() 
{
	DDRA = 0xff;
	while(1)
	{
		
		if ((PINA & 0x01) == 0x01) // 스위치 디바운싱
			{
				_delay_ms(10); // 10ms 기달리고
				while((PINA & 0x01) != 0x01) //기달렸는데도 0일경우 LED 다 꺼버림 즉 디바운싱중에는 LED 꺼라
					PORTA = 0x00;
				PORTA = 0xff; // 10ms 기달리고 정상 입력일경우 LED 켜라
				_delay_ms(10);
			}
		PORTA = 0X00;
		_delay_ms(1);
	}
}