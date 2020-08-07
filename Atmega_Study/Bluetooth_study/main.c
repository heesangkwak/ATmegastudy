/*
 * Bluetooth_study.c
 *
 * Created: 2020-07-22 오후 3:05:49
 * Author : IOT
 */ 
//#include <avr/io.h>
//#define F_CPU 16000000
//#include <util/delay.h>
//
////UART 
//void init_UART();
//void tx(char c); //문자를 uart통신으로 핸드폰에 보내주는 함수
//void sort(char * arr); //문자열을 uart 통신으로 핸드폰으로 보내주는 함수 
//char rx(void);
//
////LCD
//#define Line_1 0x80 //이건 이해가 잘안됨
//#define Line_2 0xc0
//#define Function 0x30
//#define Function_Set 0x38  //8bit mode, 2line, 5x8 dot
//#define Display_ON 0x0f
//#define Clear_Display 0x01
//#define Entry_Mode_Set 0x06
//
//void input_string(char* arr); //문자열을 LCD에 입력하는 함수
//void input_data(char c); // 문자를 LCD 에 입력하는 함수
//void init_LCD(); // LCD를 초기화 하는 함수
//void CMD(unsigned char function);//LCD에 명령어를 입력하려면 타임다이어그램에 맞게 
////신호를 켜는 순서를 지켜야함 그것을 해주는 함수 
//
//int main(void)
//{
	//DDRF = 0xff;
	//DDRC = 0xff;
	//init_LCD();
	//init_UART();
	//char input_value[50];
	//char value;
	//int i = 0,processer = 0;
	//while(1)
	//{
			//value = rx();	
			//if (value == '\n' )
			//{
					//input_value[i] = '\0';
					//processer = 1;
			//}			
			//else
			//{
				//if(value == 0x0d)
						//input_value[i] = '\0';
				//else 
				//{
					//input_value[i] = value;
					//i++;	
				//}
			//}	
			//if (processer == 1) // 배열에 수신데이터를 다 입력했을 경우
			//{
				//processer = 0;
				//i = 0;
				//while(1)
				//{
					//CMD(Clear_Display);
					//_delay_ms(1.54);		
					//
					//CMD(Line_1);
					//input_string(input_value);
					//
					//tx('[');
					//sort(input_value); 
					//tx(']');
					//tx('\n');
					//break;				
				//}
			//}
	//}
//}
//
//void init_UART()
//{
	//UCSR1C = 0x06;
	//UCSR1B = 0x18;//송,수신 모드로 할것
	//UBRR1H = 0;
	//UBRR1L = 8; //115.2k Baud Rate ,16MHz 설정 datasheet 참조  
//}
//void tx(char c)
//{
	//while ((UCSR1A & 0x20) != 0x20);
	//
	//UDR1 = c;
//}
//void sort(char * arr)
//{
	//int i = 0;
	//while(1)
	//{
		//if (arr[i] == '\0' || arr[i] == 0x0d)
		//{
			////tx('F');
			//return;
		//}
		//else 
			//tx(arr[i]);
			//
		//i++;
	//}
//}
//
//char rx(void)
//{
	//while ((UCSR1A & 0x80) != 0x80);
	//
	//return (UDR1);
//}
//
//void input_string(char* arr)
//{
	//int i =0;
//
	//while (1)
	//{
		//if (i > 15)
		//break;
		//
		//if (arr[i] == '\0' || arr[i] == 0x0d)
		//return;
		//
		//input_data(arr[i]);
		//i++;
	//}
	//CMD(Line_2);
	//while(1)
	//{
		//if (arr[i] == '\0' || arr[i] == 0x0d)
		//return;
		//
		//input_data(arr[i]);
		//i++;
	//}
//}
//
//void input_data(char c)
//{
	//_delay_ms(1);
	//PORTC = 0x01; //RS=1, RW, E =0
	//_delay_us(0.06);
	//PORTC = 0x05; //E set ,RS set
	//_delay_us(0.2); // 150ns = 0.15us
	//
	//PORTF = c ;
	//_delay_us(0.1);
	//PORTC = 0x00; //E = 0 RW = 0 RS = 0
	//_delay_us(1);
//}
//
//void init_LCD()
//{
	//_delay_ms(40);
	//CMD(Function);
	//_delay_ms(5);
	//CMD(Function);
	//_delay_us(101);
	//CMD(Function);
	//_delay_us(0.1);
	//
	//CMD(Function_Set);
	//_delay_us(40);
	//CMD(Display_ON);
	//_delay_us(40);
	//CMD(Clear_Display);
	//_delay_ms(1.54);
	//CMD(Entry_Mode_Set);
	//_delay_us(40);
//}
//
//void CMD(unsigned char function)
//{
	//_delay_ms(1); //이거 없으면 안됨 왜인지는 잘모르겠음
	////타임다이어그램을 봐도 여기부분은 잘모르겠다
	////(마음에 준비가 필요해보임)
	//PORTC = 0x00; //RS, RW, E =0
	//_delay_us(0.06); // 0.06us 정도로 잡아야하지만 지금 테스트
	//PORTC = 0x04; //E set
	//_delay_us(0.2); // 150ns = 0.15us
	//
	//PORTF = function & 0xff;
	//_delay_us(0.1); // 0.09us;
	//PORTC = 0x00;
	//_delay_us(0.2); //0.01us;
//}


//DC MOTOR 추가 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

//UART
void init_UART();
void tx(char c); //문자를 uart통신으로 핸드폰에 보내주는 함수
void sort(char * arr); //문자열을 uart 통신으로 핸드폰으로 보내주는 함수
char rx(void);

//LCD
#define Line_1 0x80 //이건 이해가 잘안됨
#define Line_2 0xc0
#define Function 0x30
#define Function_Set 0x38  //8bit mode, 2line, 5x8 dot
#define Display_ON 0x0f
#define Clear_Display 0x01
#define Entry_Mode_Set 0x06

void input_string(char* arr); //문자열을 LCD에 입력하는 함수
void input_data(char c); // 문자를 LCD 에 입력하는 함수
void init_LCD(); // LCD를 초기화 하는 함수
void CMD(unsigned char function);//LCD에 명령어를 입력하려면 타임다이어그램에 맞게
//신호를 켜는 순서를 지켜야함 그것을 해주는 함수

//DC motor

/*
AIN1 = PB 0pin  1
AIn2 = PB 1pin  2
STBY = PB 2pin  4
PWMA = PB 4pin  16
*/

void stop();
void CCW();
void CW();

void select_motoer(char* arr);

int main(void)
{
	DDRF = 0xff;
	DDRC = 0xff;
	DDRB = 0xff;
	init_LCD();
	init_UART();
	char input_value[50];
	char value;
	int i = 0,processer = 0;
	while(1)
	{
		value = rx();
		if (value == '\n' )
		{
			input_value[i] = '\0';
			processer = 1;
		}
		else
		{
			if(value == 0x0d)
			input_value[i] = '\0';
			else
			{
				input_value[i] = value;
				i++;
			}
		}
		if (processer == 1) // 배열에 수신데이터를 다 입력했을 경우
		{
			processer = 0;
			i = 0;
			while(1)
			{
				//CMD(Clear_Display);
				//_delay_ms(1.54);
				//
				//CMD(Line_1);
				//input_string(input_value);
				//
				sort(input_value);
				tx('\n');
				break;
			}
		}
		select_motoer(input_value);
		
	}
}

void init_UART()
{
	UCSR1C = 0x06;
	UCSR1B = 0x18;//송,수신 모드로 할것
	UBRR1H = 0;
	UBRR1L = 8; //115.2k Baud Rate ,16MHz 설정 datasheet 참조
}
void tx(char c)
{
	while ((UCSR1A & 0x20) != 0x20);
	
	UDR1 = c;
}
void sort(char * arr)
{
	int i = 0;
	while(1)
	{
		if (arr[i] == '\0' || arr[i] == 0x0d)
		{
			//tx('F');
			return;
		}
		else
		tx(arr[i]);
		
		i++;
	}
}

char rx(void)
{
	while ((UCSR1A & 0x80) != 0x80);
	
	return (UDR1);
}

void input_string(char* arr)
{
	int i =0;

	while (1)
	{
		if (i > 15)
		break;
		
		if (arr[i] == '\0' || arr[i] == 0x0d)
		return;
		
		input_data(arr[i]);
		i++;
	}
	CMD(Line_2);
	while(1)
	{
		if (arr[i] == '\0' || arr[i] == 0x0d)
		return;
		
		input_data(arr[i]);
		i++;
	}
}

void input_data(char c)
{
	_delay_ms(1);
	PORTC = 0x01; //RS=1, RW, E =0
	_delay_us(0.06);
	PORTC = 0x05; //E set ,RS set
	_delay_us(0.2); // 150ns = 0.15us
	
	PORTF = c ;
	_delay_us(0.1);
	PORTC = 0x00; //E = 0 RW = 0 RS = 0
	_delay_us(1);
}

void init_LCD()
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
	_delay_ms(1.54);
	CMD(Entry_Mode_Set);
	_delay_us(40);
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
	_delay_us(0.2); //0.01us;
}

void stop()
{
	PORTB = 0x07;
	_delay_ms(1000);
}
void CCW()
{
	PORTB = 0x16;
	_delay_ms(1000);
}
void CW()
{
	PORTB= 0x15;
	_delay_ms(1000);
}

void select_motoer(char * arr)
{
	
	switch (arr[0]){
		case 'g':
		case 'G':
			if (arr[1]=='O' || arr[1]=='o')
			{
				char message[40] = "motor CW";
				CMD(Clear_Display);
				_delay_ms(1.54);
				
				CMD(Line_1);
				input_string(message);	
				CCW();
			}
		break;
		case 'S':
		case 's':
			if (arr[1]=='t' || arr[1]=='T')
			{
				if (arr[2]=='O' || arr[2]=='o')
				{
					if (arr[3]=='p' || arr[3]=='P')
					{
						char message[40] = "motor STOP";
					
						CMD(Clear_Display);
						_delay_ms(1.54);
						
						CMD(Line_1);
						input_string(message);
						stop();
			}	
				}
					}
	
	}
}