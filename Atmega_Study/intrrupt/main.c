///*
 //* interrupt.c
 //*
 //* Created: 2020-07-08 오후 8:43:39
 //* Author : heesang
 //*/ 
//
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#define F_CPU 16000000 
//#include <util/delay.h>
//int main(void)
//{   
   //DDRA = 0xff; // PA번 다 출력핀으로
   //DDRB = 0xff;
   //DDRE = 0x00; // PE번 다 입력핀으로
   //SREG = 0x80; // 인터럽트 사용하겠다
   //EIMSK = 0x10;
   //EICRB = 0x03; //상승 엣지일때 인터럽트 걸겠다 EICRB 1<< ISC40 || 1<< ISC41    ISC 40 과 41을 1로 셋팅 상승엣지일때 인터럽트 == 0x03 과도 같음 
            //PORTA = 0x01;
   //while (1) 
    //{
      //PORTB = 0xff;
      //
   //}
//}
//
   //ISR(INT4_vect) // vect = vector의 약자 
   //{
      //PORTA = 0x02;
      //_delay_ms(30);
      //PORTA = 0x01;
      //
   //}
   

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>

// 7Segment로 숫자 카운트 
// 스위치 디바운싱
// sw1 on count +1;
// sw2 on count = 0 리셋

void select_number(int num);
int count = 0;

int main(void)
{
	DDRA = 0x01;
	DDRC = 0xff;
	DDRG = 0xff; 
	SREG |= 0x80;  // 인터럽트 허용 
	EIMSK = 0x30;  // INT4, 5 번 인터럽트 허용
	EICRB = 0x0f; // INT4, 5번 사용	상승엣지로 설정
	while(1){
		PORTA = 0x01;
		PORTG = 0x07;
		select_number(count);
		
	}
}

ISR (INT4_vect) // 인터럽트 발생시 카운트 온
{
	PORTA = 0x01;
	_delay_ms(10); //10ms 간 기다린다.
	EIFR = 0x10; //인터럽트 리셋 EIFR으로 강제로 클리어 해준다 	
	if((PINE = 0x10) == 0)
		return ;
	count++;
}

//ISR (INT5_vect) // 인터럽트 발생시
//{
	//_delay_ms(10); //10ms 간 기다린다.
	//EIFR = 0x10; //인터럽트 리셋 EIFR으로 강제로 클리어 해준다
	//if((PINE = 0x10) == 0)
		//return ;
	//count=0;
//}


void select_number(int num)
{
	switch (num){
		case 0:
			PORTG = 63;
		case 1:
			PORTG = 6;
		case 2:
			PORTG = 91;
		case 3:
			PORTG = 79;
		case 4:
			PORTG = 102;
		case 5:
			PORTG = 109;
		case 6:
			PORTG = 124;
		case 7:
			PORTG = 7;
		case 8:
			PORTG = 127;
		case 9:
			PORTG = 103;
	}
}


//0 : PORTG = 0x3f		0011 1111   63
//1 : PORTG = 0X06		0000 1010	6
//2 : PORTG = 0X53;		0101 1011	91
//3 : PORTG = 0x4f;		0100 1111	79
//4 : PORTG = 0x66;		0110 0110	102	
//5 : PORTG = 0x6c;		0110 1101	109
//6 : PORTG = 0X78		0111 1100	124
//7 : PORTG = 0X07;		0000 0111	7
//8 : PORTG = 0x7f		0111 1111	127
//9 : PORTG = 0X67		0110 0111	103