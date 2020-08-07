///*
 //* interrupt.c
 //*
 //* Created: 2020-07-08 오후 8:43:39
 //* Author : heesang
 //*/ 
//
////#include <avr/io.h>
////#include <avr/interrupt.h>
////#define F_CPU 16000000 
////#include <util/delay.h>
////int main(void)
////{	
	////DDRA = 0xff; // PA번 다 출력핀으로
	////DDRB = 0x01;
	////DDRE = 0x00; // PE번 다 입력핀으로
	////SREG |= 0x80; // 인터럽트 사용하겠다
	////EIMSK = 0x10;
	////EICRB = 0x03; //상승 엣지일때 인터럽트 걸겠
	////while (1) 
    ////{
		////PORTB = 0x01;	
	////}
////}
////
	////ISR(INT4_vect)
	////{
		////_delay_ms(100);
		////EIFR = 1 << 4;
		////if ((PINE = 0x10)==0)
			////return;
		////PORTA = 0x80;
		////_delay_ms(100);
		////PORTA = 0x01;
		////
		////
		////
	////}
	////
////
//
////#include <avr/io.h>
////#include <avr/interrupt.h>
////#define F_CPU 16000000 
////#include <util/delay.h>
////int main(void)
////{   
   ////DDRA = 0xff; // PA번 다 출력핀으로
   ////DDRB = 0xff;
   ////DDRE = 0x00; // PE번 다 입력핀으로
   ////SREG = 0x80; // 인터럽트 사용하겠다
   ////EIMSK = 0x10;
   ////EICRB = 0x03; //상승 엣지일때 인터럽트 걸겠다 EICRB 1<< ISC40 || 1<< ISC41    ISC 40 과 41을 1로 셋팅 상승엣지일때 인터럽트 == 0x03 과도 같음 
            ////PORTA = 0x01;
   ////while (1) 
    ////{
      ////PORTB = 0xff;
      ////
   ////}
////}
////
   ////ISR(INT4_vect) // vect = vector의 약자 
   ////{
      ////PORTA = 0x02;
      ////_delay_ms(30);
      ////PORTA = 0x01;
      ////
   ////}
    //
//// 7Segment로 숫자 카운트
//// 스위치 디바운싱
//// sw1 on count +1;
//// sw2 on count = 0 리셋
//
//#include <avr/io.h>
//#define F_CPU 16000000  //크리스탈 용량
//#include <util/delay.h> 
//#include <avr/interrupt.h> //인터럽트 사용 
//
//# define IDLE 0 
//# define GO 1
//# define STOP 2
//
//void select_number(int num);
//
////전역변수 선언
//int count = 0;  
//int status = IDLE;
//int Stop_Time = 0;
//
//int main(void)
//{
	//DDRC = 0xff;
	//DDRG = 0xff;
	//DDRE = 0x00;
	//SREG |=0x80;
	//EIMSK = 0x30;
	//EICRB = 0x0f;
//
	////1ms = 1/1000 초    1 / 100 초속으로 1개씩 증가시키려면 
	//while (1){	
		//if (count > 9999)
			//count = 0;
		//
		//if(status == GO){
		//PORTG = 0x0e;
		//select_number(count / 1000);  //2.5*4 = 10ms = 1/100
		//_delay_ms(2.5);
		//
		//PORTG = 0x0d;
		//select_number((count % 1000) / 100);
		//_delay_ms(2.5);
		//
		//PORTG = 0x0b;
		//select_number(((count % 1000) % 100)/10);
		//_delay_ms(2.5);
		//
		//PORTG = 0x07;
		//select_number(((count % 1000) % 100)%10);
		//_delay_ms(2.5);
		//count++;
		//}
		//else if (status == STOP)
		//{
			//PORTG = 0x0e;
			//select_number(Stop_Time / 1000); 
			//_delay_ms(2.5);
			//
			//PORTG = 0x0d;
			//select_number((Stop_Time % 1000) / 100);
			//_delay_ms(2.5);
			//
			//PORTG = 0x0b;
			//select_number(((Stop_Time % 1000) % 100)/10);
			//_delay_ms(2.5);
			//
			//PORTG = 0x07;
			//select_number(((Stop_Time % 1000) % 100)%10);
			//_delay_ms(2.5);
		//}		
		//else
		//{
			//PORTG = 0x0e;
			//select_number(IDLE / 1000);
			//_delay_ms(2.5);
			//
			//PORTG = 0x0d;
			//select_number((IDLE % 1000) / 100);
			//_delay_ms(2.5);
			//
			//PORTG = 0x0b;
			//select_number(((IDLE % 1000) % 100)/10);
			//_delay_ms(2.5);
			//
			//PORTG = 0x07;
			//select_number(((IDLE % 1000) % 100)%10);
			//_delay_ms(2.5);
		//}
	//}
//}
//
//ISR (INT4_vect)
	//_delay_ms (10);
	//EIFR = 0x10;
	//
	//if ((PINE & 0x10) == 0x00)
		//return ;
		//
	//if (status == IDLE ||status == STOP)
		//{
			//status = GO;
		//}	
	//else if (status == GO)
	//{
		//Stop_Time = count;
		//status = STOP; 
	//}
//}
//
//ISR (INT5_vect)
//{
	//_delay_ms (10);
	//EIFR = 0x20;
	//
	//if ((PINE & 0x20) == 0x00)
	//return ;
	//
	//status = IDLE;
	//count = 0;
//}
//
//
//
//void select_number(int num)
//{
	//switch (num){
		//case 0:
			//PORTC= 63;
			//break;
		//case 1:
			//PORTC = 6;
			//break;
		//case 2:
			//PORTC = 91;
			//break;
		//case 3:
			//PORTC = 79;
			//break;
		//case 4:
			//PORTC = 102;
			//break;
		//case 5:
			//PORTC = 109;
			//break;
		//case 6:
			//PORTC = 124;
			//break;
		//case 7:
			//PORTC = 7;
			//break;
		//case 8:
			//PORTC = 127;
			//break;
		//case 9:
			//PORTC = 103;
	//}
//}
//
////0 : PORTG = 0x3f		0011 1111   63
////1 : PORTG = 0X06		0000 1010	6
////2 : PORTG = 0X53;		0101 1011	91
////3 : PORTG = 0x4f;		0100 1111	79
////4 : PORTG = 0x66;		0110 0110	102	
////5 : PORTG = 0x6c;		0110 1101	109
////6 : PORTG = 0X78		0111 1100	124
////7 : PORTG = 0X07;		0000 0111	7
////8 : PORTG = 0x7f		0111 1111	127
////9 : PORTG = 0X67		0110 0111	103

//#include <avr/io.h>
//#define F_CPU 16000000
//#include <util/delay.h>
////1초간 켜지고 꺼지는 LED
//#include <util/interrupt.h>
//int main(void)
//{
	//DDRA =0xff;
	//SREG |= 0x80; //인터럽트 허용하고 
	//TCCR0 = 0x111; //1024 분주 
	//TIMSK =0x01; // 오버플로우가 발생하는순간
	//TCNT0 =          //   
	//while (1)
	//{
		//;
	//}
//}
