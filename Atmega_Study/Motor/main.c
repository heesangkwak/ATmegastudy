/*
 * Motor.c
 *
 * Created: 2020-07-21 오전 9:17:33
 * Author : IOT
 */ 

//DC MOTOR
//#include <avr/io.h>
//#define F_CPU 16000000
//#include <util/delay.h>
//
//#define min 77
//#define max 150
/*
AIN1 = PB 0pin  1
AIn2 = PB 1pin  2
STBY = PB 2pin  4 
PWMA = PB 4pin  16
PWMB = PB 5pin  32
BIN1 = PD 0pin  1
BTN2 = PD 1pin
*/

//void j_18_stop();
//void j_18_CCW();
//void j_18_CW();

//void stop();
//void CCW();
//void CW();
//
//void init_PWM_TC();
//void init_PWM_TC2();
//int main(void)
//{
	//init_PWM_TC();
	//init_PWM_TC2();
	//DDRB = 0xff;
	//DDRD = 0xff;
	//
	//while(1)
	//{
		//OCR0 = 77;
		//OCR2 = 77;
		//
		//CCW();
		//_delay_ms(1000);
		//
		//stop();
		//_delay_ms(1000);
		//
		////CCW();
		////_delay_ms(1000);
		////
		////stop();
		////_delay_ms(1000);
	//}
//}

//void j_18_stop()
//{
	//PORTB = 0x07;
//}
//void j_18_CCW()
//{
////	OCR0 = speed;
	//PORTB = 0x16;
//}
//void j_18_CW()
//{
////	OCR0 = speed;
	//PORTB= 0x15;	
//}

//void stop()
//{
	//
	//PORTD = 0x03;
	//PORTB |= 0x84;
	////j18
	//PORTB |= 0x07;	
//}
//void CCW()
//{
	//PORTD = 0x02;
	//PORTB |= 0x84;
	////j18
	//PORTB |= 0x16;
	//
//}
//void CW()
//{
	//PORTB |= 0x16;
	//PORTD= 0x01;
	//PORTB |= 0x84;
	////j18
	////PORTB |= 0x16;	
//}
//
//void init_PWM_TC()
//{
	//TCCR0 = 0x6A; //fast PWM mode, OC0 compare Match set 0 64프리스케일링
//}
//
//void init_PWM_TC2()
//{
	//TCCR2 = 0x6b; //fast PWM mode, OC0 compare Match set 0 64프리스케일링
//}

//#include <avr/io.h>
//#define F_CPU 16000000
//#include <util/delay.h>
//
//void step_1();
//void step_2();
//void step_3();
//void step_4();
//void step_5();
//void step_6();
//void step_7();
//void step_8();
//void rotate(int angle); //angle
//
//#define Blue 1
//#define Pink 2
//#define Yellow 4
//#define Orange 8 
//
//
//int main(void)
//{
	//DDRD = 0x0f;
	//while(1)
	//{
		//rotate(360); //angle 1입력시 5.625 회전 
		//_delay_ms(5000);
	//}
	//
//}
//
//void step_1()
//{
	//PORTD = 0xff -Orange;
//}
//
//void step_2()
//{
	//PORTD = 0xff -Yellow -Orange;
//}
//
//void step_3()
//{
	//PORTD = 0xff -Yellow;
//}
//
//void step_4()
//{
	//PORTD = 0xff -Pink -Yellow;
//}
//
//void step_5()
//{
	//PORTD = 0xff -Pink;
//}
//
//void step_6()
//{
	//PORTD = 0xff -Pink - Blue;
//}
//
//void step_7()
//{
	//PORTD = 0xff -Blue;
//}
//
//void step_8()
//{
	//PORTD = 0xff -Orange - Blue;
//}
//
//void rotate(int angle) 
//{
	//for (int i =0 ; i< (8 * angle) /5.625; i++)
	//{
		//step_1();
		//_delay_ms(1);
		//step_2();
		//_delay_ms(1);
		//step_3();
		//_delay_ms(1);
		//step_4();
		//_delay_ms(1);
		//step_5();
		//_delay_ms(1);
		//step_6();
		//_delay_ms(1);
		//step_7();
		//_delay_ms(1);
		//step_8();
		//_delay_ms(1);
	//}
//}

//Servo motor
//#include <avr/io.h>
//#define F_CPU 16000000
//#include <util/delay.h>
//
//
//void zero();
//void Left_90();
//void Right_90();
//int main(void)
//{
	//DDRB = 0xff;
	//while(1){
		//
		//zero();
		//_delay_ms(60);
		//Left_90();
		//_delay_ms(60);
		//Left_90();
		//_delay_ms(60);
		//zero();
		//_delay_ms(60);
	//
	//}
		//
//}
//
////Position "0" (1.5 ms pulse) is middle, "90" (~2
////
//void Left_90()
//{
	//PORTB = 0x01;
	//_delay_ms(1);
	//PORTB = 0x00;
	//_delay_ms(19);
	//
//}
//
//void zero()
//{
	//PORTB = 0x01;
	//_delay_ms(1.5);
	//PORTB = 0x00;
	//_delay_ms(18.5);
//}
//
//void Right_90()
//{
	//PORTB = 0x01;
	//_delay_ms(2);
	//PORTB = 0x00;
	//_delay_ms(18);
//}

// TCNT1 으로 fastPWM 모드로 모터 구현 (좌우 각각 속도조절 가능)
// OCR1A = 250; PB 5pin TCNT1A 로 조절가능 
// OCR1B = 100;	PB 5pin TCNT1B 로 조절가능 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
void init_PWM();
void stop();
void cc();

int main(void)
{
	DDRD =0xff;
	DDRB =0xff;
	init_PWM();
	OCR1A = 250;
	OCR1B = 100;
	while (1)
	{
		cc();
		_delay_ms(1000);
		stop();
		_delay_ms(2000);
	}
}
void init_PWM() // Timer/counter 로 만들어내려함 timer/counter seting
{
	TCCR1A = 0xa2; // OCN1A ,OCN1B matching clear ,bottom set fastPWM
	TCCR1B = 0x0c; // fastPWM 256 prescaler
	TCNT1 = 0;
}
void cc()
{
	PORTD = 0xa0;
	PORTB = 0x60;
	PORTA = 0x04;
}
void stop()
{
	PORTD = 0x00;
	PORTB = 0x00;
	PORTA = 0x00;
}