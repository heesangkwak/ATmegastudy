/*
 * Ultrasonic_senser.c
 *
 * Created: 2020-07-21 오후 7:05:54
 * Author : IOT
 */ 



#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#define F_CPU 16000000
#include <util/delay.h>

#define Function 0x30
#define Function_Set 0x38  //8bit mode, 2line, 5x8 dot
#define Display_ON 0x0c
#define Clear_Display 0x01 
#define Entry_Mode_Set 0x06
 
#define Line_1 0x80 //이건 이해가 잘안됨
#define Line_2 0xc0
/*
RS = PC		0 PIN		0x01
RW = PC		1 PIN		0x02
E  = PC		2 PIN		0x04
*/

void init_LCC();
void CMD(unsigned char function);
void input_data(unsigned char c);
void input_string(char * arr);
void stop_TC();
unsigned int count=0;
void start_TC();
int main(void)
{

	int value;
	char arr[40];
	DDRF = 0xff;
	DDRC = 0xff;
	DDRA = 0x80;
	SREG = 0x80;
	
	while(1){
		_delay_us(10); //켜기전 마음에 준비정도
		PORTA = 0x80;  //trigger on
		_delay_us(10);
		PORTA &= 0x00;//trigger off
	
		while((PINB & 0x01)!= 0x01); // echo 가 LOW 상태인동안 무한 반복해라 
		start_TC();
		while((PINB & 0x01)!= 0x00); // echo 가 HIGH 인동안 무한 반복해라
		stop_TC(); //인터럽트 중지 OR 클록 입력 차단  
	
		value = (count * 16) / 58; //cm 변환 소수점 날려버림
		// 16us* count /58 = 1cm //1us로할때보다 오차가 크지만 소수점을 날릴 경우
		// 비교적 오차가 크지 않기에 그냥 16us그대로 쓰기로 결정  
		if(value > 200)
		{
			continue;
		}
		sprintf(arr,"%d",value); //배열에 넣음
		
		CMD(Clear_Display);
		_delay_ms(1.6);
		
		CMD(Line_1);
		input_string(arr);
		input_data('c');
		input_data('m');
		
		_delay_ms(500);
		count = 0;
	}	
}


void stop_TC()
{
	TCCR0 = 0x00; //클럭 입력차단
	TIMSK = 0x00; //인터럽트 차단 
	TCNT0 = 0; //TCNT0 초기화 
}

void start_TC()
{
	TCCR0 = 0x01; //프리스케일링 없음 1/16000000 * 256 =  16us 
	//즉 16us 당 카운터 1씩 증가하게 하게 만듬
	TIMSK = 0x01; //16us이후에 인터럽트 발생하게 만듬
	TCNT0 = 0;
}

void CMD(unsigned char function)
{
	_delay_ms(1); //이거 없으면 안됨 왜인지는 잘모르겠음
	//타임다이어그램을 봐도 여기부분은 잘모르겠다
	//(마음에 준비가 필요해보임)
	PORTC = 0x00; //RS, RW, E =0
	_delay_us(0.06); // 0.06us 정도로 잡아야하지만 지금 테스트
	PORTC = 0x04; //E set
	_delay_us(0.2); // 150ns = 0.15us
	
	PORTF = function & 0xff;
	_delay_us(0.1); // 0.09us;
	PORTC = 0x00;
	_delay_us(0.02); //0.01us;
}

void init_LCC()
{
	_delay_ms(40);
	CMD(Function);
	_delay_ms(5);
	CMD(Function);
	_delay_us(101);
	CMD(Function);
	_delay_us(0.1);
	
	CMD(Function_Set);
	_delay_us(40);
	CMD(Display_ON);
	_delay_us(40);
	CMD(Clear_Display);
	_delay_ms(1.6);
	CMD(Entry_Mode_Set);
	_delay_us(40);
}

void input_data(unsigned char c)
{
	_delay_ms(1);
	PORTC = 0x01; //RS=1, RW, E =0
	_delay_us(0.06);
	PORTC = 0x05; //E set ,RS set
	_delay_us(0.2); // 150ns = 0.15us
	
	PORTF = c & 0xff;
	_delay_us(0.1);
	PORTC = 0x00; //E = 0 RW = 0 RS = 0
	_delay_us(1);
}

void input_string(char* arr)
{
	int i =0;

	while (1)
	{
		if (i > 15)
		break;
		
		if(arr[i] == '\0')
		return;
		
		input_data(arr[i]);
		i++;
	}
	CMD(Line_2);
	while(1)
	{
		if(arr[i] == '\0')
		return;
		
		input_data(arr[i]);
		i++;
	}
}

ISR(TIMER0_OVF_vect)
{
	count++;
	TCNT0 = 0;
}
