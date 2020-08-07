/*
 * USART.c
 *
 * Created: 2020-07-14 오후 8:50:55
 * Author : heesang
 */ 
//#include <avr/io.h>
//#define F_CPU 16000000
//#include <util/delay.h>
//#define  NULL 0

//void init_usart(); // usart setup
//void putchar0 (char c); // 문자 송신 
//void puts0 (char *ptr);
//int main(void)
//{
   //char string[]="Hi~ I'm HeeSang";
   //char *ptr = string;
//
   //init_usart();
    //while (1) 
    //{
      //
      //puts0(ptr);
      //putchar0('\n'); //줄바꿈
      //putchar0('\r');//커서 앞으로
      //_delay_ms(1000);
    //}
//}
//
//
//void init_usart()
//{
   //UCSR0B =0x08; // TX enable USART의 송신모듈 작동
   //UCSR0C =0x06; // 패리티 비트 사용X 스톱비트 1 , 8bit 데이터 전송
   ////baud rate 설정하기 16MHZ 에 속도 9600의 경우 HIGH = 0 , LOW =103 으로 설정한다.
   //UBRR0H = 0x00;
   //UBRR0L = 103;
//}
//
//void putchar0 (char c) // 1개의 문자를 송신하는 함수
//{
   //while (!(UCSR0A & (1<<UDRE0)))
   ////while ((UCSR0A & 0x20) != 0x20 )//A의 5번 비트 새로운 송신 데이터를 받기 위한 생태 플래그로 새로운 송신데이터를 받을 준비가 되면 1로 세트 
      //;
   //
   //UDR0 = c; // 송수신에 필요한 데이터를 저장하는 레지스터
//}   
//
//void puts0 (char *ptr) // string을 송신하는 함수 
//{
   //while (1)
   //{
      //
      //if (*ptr != NULL) // 문자열의 끝은 NULL C에서 배웠던 내용
         //putchar0(*ptr++);
      //else
         //return; //ptr배열값을 하나씩 증가시킴 == ptr[i++]
   //}   
//}

//#include <avr/io.h>
//#define F_CPU 16000000
//#define NULL 0
//#include <util/delay.h>
//
//void init_uart();
//
//void sort(char * ptr);
//void tx(char c);//송신부
//
//char rx();//수신부 
//char rx_value[20];
//int main()
//{	
	//init_uart();	
	//char data;
	//int index = 0;
	//int processor;
	//while(1)
	//{
		//data = rx(); // 한글자씩 수신하고
		//
		//if(data == '\n') //문자열의 끝에 도달했을때 엔터 반환 입력이라 엔터인가? 
		//{
			//rx_value[index] = 0;//맨마지막 문자 0으로 그래야 sort 에서 분류 될때 마지막 null 만나게 함
			//processor = 1;
		//}
		//
		//else
		//{
			//rx_value[index] = data;
			//index++;
		//}
		//
		//if (processor == 1) //다시 수신가능상태도 만들어줘야함
		//{
			//sort(rx_value);
			//processor = 0;
			//index = 0;
		//}
			//
	//}	
//}
//
//void init_uart()
//{
	//UCSR0B = 0x18; //송수신 모듈 다 사용하겠다.
	//UCSR0C = 0x07; // 패리티비트 X 스톱비트 0 8bit 데이터 전송 
	 //16Mhz 9600 일때 datasheet 참고 
	//UBRR0H = 0x00;
	//UBRR0L = 0x67; 
//}
//
//void tx(char c) //보내는건 사용자에게 입력받는것이기에 인자를 넣음 
//{
	//while((UCSR0A & 0x20) != 0x20)
	//;
	//UDR0 = c;
//}
//
//char rx() // 수신하는건 어딘가에서 오는걸받기때문에 함수의 인자를 넣지않음 
//{
	//while((UCSR0A & 0x80) != 0x80) //7번비트가 1일떄 수신한 값이 있는것 즉 0일땐 수신값이 없다 고로 1일때까지 대기시켜준다.
	//;
	//return (UDR0); //수신된 데이터가 UDR0 에 있기때문에 이값을 리턴해준다
//}
//
//void sort(char *arr)
//{
	//int j = 0;
	//while (1)
	//{
		//if (arr[j] == NULL){
			//tx('\n');
			//tx('\r');
			//return ;
		//}
		//else {
			//tx(arr[j]);
			//j++;	
		//}
	//}
//}

//void sort(char * arr)
//{	int j = 0;
	//while(1)
	//{
		//if (arr[j] == NULL)
			//return;
		//else 
			//tx(arr[j]);
		//j++;	
	//}
//}

//#include <avr/io.h>
//#define F_CPU 16000000
//#define NULL 0
//#include <util/delay.h>
//
//void init_uart();
//char rx();
//void select_number(char c);
//int main(void)
//{
//DDRG = 0xff;
//DDRC = 0xff;
//init_uart();
//char data;
//char input[6] = "1";
//int index = 0;
//int process = 0;
//while(1)
//{
	//if (process == 1)
	//{
		//while(1)
		//{
			//PORTG = 0x0e;
			//select_number(input[0]);
			//_delay_ms(5);
				//
			//PORTG = 0x0d;
			//select_number(input[1]);
			//_delay_ms(5);
				//
			//PORTG = 0x0b;
			//select_number(input[2]);
			//_delay_ms(5);
				//
			//PORTG = 0x07;
			//select_number(input[3]);
			//_delay_ms(5);
				//
			//if ((PINA & 0x01) == 0x01){
				//_delay_ms(10);
				//while((PINA & 0x01) !=0x01);
				//
				//PORTG = 0xff;
				//index = 0;
				//process = 0;
				//for (int k=0 ; k<6;k++)
					//input[k] = 0;
				//break;
			//}
		//}
	//}
	//data = rx();
	//if (data =='\n')
	//{
		//input[index] = NULL;
		//process = 1;
	//}
	//else
	//{
		//input[index] = data;
		//index++;
	//}
	//
//}
//}
//
//void init_uart()
//{
	//UCSR0B = 0x10;
	//UCSR0C = 0x07;
	//UBRR0H = 0x00;
	//UBRR0L = 0x67;
//}
//
//char rx()
//{
	//while ((UCSR0A & 0x80)!= 0x80);
	//
	//return (UDR0);
//}
//
//void select_number(char c)
//{
	//switch (c){
		//case '0':
			//PORTC= 63;
			//break;
		//case '1':
			//PORTC = 6;
			//break;
		//case '2':
			//PORTC = 91;
			//break;
		//case '3':
			//PORTC = 79;
			//break;
		//case '4':
			//PORTC = 102;
			//break;
		//case '5':
			//PORTC = 109;
			//break;
		//case '6':
			//PORTC = 124;
			//break;
		//case '7':
			//PORTC = 7;
			//break;
		//case '8':
			//PORTC = 127;
			//break;
		//case '9':
			//PORTC = 103;
	//}
//}

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

//ADC 추가해서 입출력
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <stdio.h>

//usart
void init_uart();
void tx(char a);
void sort(char * arr);


//adc 내용 
void init_adc();
unsigned short adc_value();

//7segment
void select_number(int num);

int main(void)
{
	DDRG = 0xff;
	DDRC = 0xff;
	init_uart();
	init_adc();
	int num1,num2,num3,num4,value;
	char s1[10];
	while(1)
	{
		value = adc_value();
		num1 = value /1000;
		num2 = (value %1000) /100;
		num3 = ((value %1000) %100)/10;
		num4 = ((value %1000) %100)%10;	
		
		//sprintf 함수를 사용하면 정수를 문자열로 변환할 수 있다 즉 배열로 저장된다 
		//(stdio.h 선언해야 사용가능).
		sprintf(s1,"%d",value); //value 값을 문자열 (배열로 만들고)
		
		sort(s1);

		for(int i = 0; i<31;i++){ // 0.3s 설정
			PORTG = 0x0e;
			select_number(num1);
			_delay_ms(2.5);
			
			PORTG = 0x0d;
			select_number(num2);
			_delay_ms(2.5);
			
			PORTG = 0x0b;
			select_number(num3);
			_delay_ms(2.5);
			
			PORTG = 0x07;
			select_number(num4);
			_delay_ms(2.5);
		}
		
	}
}
void init_uart()
{
	UCSR0B = 0x08;
	UCSR0C = 0x06;
	//baud rate 설정
	UBRR0H = 0x00;
	UBRR0L = 0x67;
}

void init_adc()
{
	ADMUX |= 0x40;
	ADCSRA |= 0x87; 
}

void tx(char a)
{
	while((UCSR0A & 0x20) !=0x20);
	
	UDR0 = a;
}

unsigned short adc_value()
{
	unsigned char low,high;
	unsigned short value;
	ADCSRA |= 0x40;
	while((ADCSRA & 0x10) != 0x10);
	
	low = ADCL;
	high = ADCH;
	value = (high << 8) | low ;
	return value;
}

void sort(char * arr)
{
	int j=0;
	while(1)
	{
		if (arr[j] == '\0'){
			tx('\n');
			return;
		}
		else
			tx(arr[j]);
		j++;
	}
}
//배열로 했을때 1000의자리 숫자가 입력이없을경우 100의 자리 숫자가 1000의자리로 가고 1의자리숫자가 없어 버그를 발생시킴 
// 배열을 스왑해서 해결 할 수 있지만 조건과 반복문의 과도하게 들어갈 가능성이 있어 그냥 short로 받은 값을 자릿수 나누기를 이용해서 처리함 

void select_number(int num)
{
	switch (num){
		case 0:
			PORTC= 63;
			break;
		case 1:
			PORTC = 6;
			break;
		case 2:
			PORTC = 91;
			break;
		case 3:
			PORTC = 79;
			break;
		case 4:
			PORTC = 102;
			break;
		case 5:
			PORTC = 109;
			break;
		case 6:
			PORTC = 124;
			break;
		case 7:
			PORTC = 7;
			break;
		case 8:
			PORTC = 127;
			break;
		case 9:
			PORTC = 103;
}
}