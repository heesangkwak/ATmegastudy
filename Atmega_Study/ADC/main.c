///*
 //* ADC.c
 //*
 //* Created: 2020-07-14 오전 9:15:05
 //* Author : IOT
 //*/ 
//

//#include <avr/io.h>
//#define F_CPU 16000000UL
//#include <util/delay.h>
//
//#define CDS10 341
//#define CDS20 450
//#define CDS50 550
//#define CDS80 650
//#define CDS100 731
//
//void init_adc();
//unsigned short read_adc();
//void show_adc_led(unsigned short data);
//
//int main()
//{
	//unsigned short value;
	//DDRA = 0xFF; // LED 출력port설정
	//DDRF = 0x00; // ADC port 입력
	//init_adc(); // adc  초기화
	//
	//while(1)
	//{
		//value = read_adc();
		//if (value >= CDS10)
			//PORTA =0xff;
		////show_adc_led(value); // led display
	//}
//}
//
//void init_adc()
//{
	//ADMUX = 0x40; //  01000000
	////ADMUX =| 1<<REFS0 // AVCC (5V maximum) , right sorting, use port0
	//ADCSRA = 0x87; //10000111 ADE enable, single conversion, prescaler 128
//}
//
//unsigned short read_adc()
//{
	//unsigned char adc_low, adc_high;
	//unsigned short value;
	//ADCSRA = 0x40; // 01000000 start conversion.
	//while((ADCSRA & 0x10) != 0x10);
	//
	//adc_low = ADCL; // CL을 먼저읽고 CH를 나중에읽음
	//adc_high = ADCH;
	//value = (adc_high<<8) | adc_low; // 16bit
	//
	//return value;
//}
//
//void show_adc_led(unsigned short value)
//{
	//if (value <= CDS10)        PORTA = 0xff;
	//else if (value <= CDS20)    PORTA = 0x77;
	//else if (value <= CDS20)    PORTA = 0x55;
	//else if (value <= CDS20)    PORTA = 0x11;
	//else if (value <= CDS20)    PORTA = 0x01;
	//else
	//{
		//PORTA = 0x00;
	//}
	//
//}

#include <avr/io.h>

void init_adc();
unsigned short adc_read();

//레지스터들은 그냥선언보다 and 나 or 연산으로 선언하는 습관을 들이자 

int main()
{
	init_adc();
	unsigned short value; 
	while(1)
	{
		value = adc_read();
		if (value > 800) // 임의로 지정 LED 켜지게
			PORTA |= 0xff;
	}
}

void init_adc()
{
	ADMUX |= 0x02; // vext (5v) 사용하고 adc2 pin 사용 
	ADCSRA |= 0x87; // adc 사용한다 , 7 = 프리스케일 128 로 설정
	DDRA = 0xff; // A pin전부 output으로 
} 

unsigned short adc_read()
{
	unsigned char high ,low; // 8bit 변수
	unsigned short value; // 16비트 변수
	ADCSRA |= 0x40; // start converter 1로 세트
	while ((ADCSRA & 0x10) !=0x10); 
	// converter 가 완료되면 ADIF 가 1로 세트되는것을 이용 while 문에서 1이 될때까지 무한반복 돌림
	
	high = ADCH; 
	//	adc의 상위 8bit를 high 에 저장 상위비트를 저장한것뿐 이자체가 상위비트가 아니다 그래서 value 값을 할때 shift 8bit을 시킨것
	low = ADCL;  
	// adc의 하위 8bit를 low 에 저장한다 
	value =(high << 8)|low; 
	// high를 상위 8 bit 로 올리고 하위 8 bit 연산시켜서 16bit의 value를 만든다
	return value;	//analog → digital 로 변경된 value 값 리턴
}


