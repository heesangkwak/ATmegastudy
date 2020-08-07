///*
 //* LCD.c
 //*
 //* Created: 2020-07-20 오전 9:20:33
 //* Author : IOT
 //*/ 
//
//#include <avr/io.h>
//#define F_CPU 16000000
//#include <util/delay.h>
//#define Function 0x30
//#define Function_Set 0x38  //8bit mode, 2line, 5x8 dot
//#define Display_ON 0x0C
//#define Clear_Display 0x01
//#define Entry_Mode_Set 0x06 
//
///*
//RS = PC		0 PIN		0x01
//RW = PC		1 PIN		0x02
//E  = PC		2 PIN		0x04
//*/
//void LCD_initialize(void);
//void LCD_CMD (unsigned char function);
//void Input_data(unsigned char c);
//int main(void)
//{
	//DDRC = 0xff;
    //DDRF = 0xff;
	//LCD_initialize(); //8 bit interface의 초기화 과정에 따라 초기화함 
	//Input_data('A');
//}
//
//void LCD_CMD (unsigned char function)
//{
	//PORTC = 0x00; // RS RW E 전부 0
	//_delay_us(0.04);
	//PORTC  = 0x04; // E신호 ON E 신호 1로
	//_delay_us(0.15); // 데이터 입력가능시간까지 기달림/
	//
	//PORTF = function; // 데이터 입력 
	//_delay_us(0.08); 
	//PORTC = 0x03; //E = 0 RW = 1 RS = 1 // E 신호 OFF 
	//_delay_us(0.01);
//}
//
//void Input_data(unsigned char c)
//{
	//_delay_ms(1);
	//PORTC = 0x01; //RS만 1(ON)
	//
	//_delay_us(0.04);
	//
	//PORTC = 0x05; // E, RS ON  
	//_delay_us(0.15); // 데이터 입력가능시간까지 기달림/
	//
	//PORTF = c & 0xff;
	//_delay_us(0.08); 
	//PORTC = 0x02; //E = 0 RW = 1 RS = 0  
	//_delay_us(0.01); 
	//
//}
//
//void LCD_initialize(void)
//{
	//_delay_ms(30);
	//LCD_CMD (Function);
	//_delay_ms(10);
	//LCD_CMD (Function);
	//_delay_us(200);
	//LCD_CMD (Function);
	//
	//_delay_ms(1);
	//
	//LCD_CMD (Function_Set);
	//_delay_us(40);
	//LCD_CMD (Display_ON);
	//_delay_us(40);
	//LCD_CMD (Clear_Display);
	//_delay_us(1.53);
	//LCD_CMD (Entry_Mode_Set);
	//_delay_ms(1);
//}
//

//#include <avr/io.h>
//#define F_CPU 16000000
//#include <util/delay.h>
//#define Function 0x30
//#define Function_Set 0x38  //8bit mode, 2line, 5x8 dot
//#define Display_ON 0x0c
//#define Clear_Display 0x01
//#define Entry_Mode_Set 0x06
//#define NULL 0
//#define Line_1 0x80 //이건 이해가 잘안됨
//#define Line_2 0xc0
///*
//RS = PC		0 PIN		0x01
//RW = PC		1 PIN		0x02
//E  = PC		2 PIN		0x04
//*/
//
//void init_LCD();
//void CMD(unsigned char function);
//void input_data(unsigned char c);
//void input_string(unsigned char * arr);
//void init_uart();
//unsigned char rx();
//int main(void)
//{
	//unsigned char string[36];
	//DDRF = 0xff;
	//DDRC = 0xff;
	//init_uart();
	//init_LCD();
	//int i = 0,proccesser = 0;
	//while(1)
	//{
		//unsigned value = rx();
		//
		//if (value == '\n')
		//{
			//string[i] = NULL;
			//proccesser = 1;
		//}
		//else 
		//{
			//string[i]= value;
			//i++;
		//}
		//
		//if (proccesser == 1)
			//break;	
	//}
	//CMD(Line_1);
	//input_string(string);	
//}
//// 다시 하면서 깨달은것 데이터 시트보다 시작은 적게주면 문제지만 좀 더주는것은 큰 문제는 없음
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
	//_delay_us(0.02); //0.01us;
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
//void input_data(unsigned char c)
//{
	//_delay_ms(1);
	//PORTC = 0x01; //RS=1, RW, E =0
	//_delay_us(0.06);
	//PORTC = 0x05; //E set ,RS set
	//_delay_us(0.2); // 150ns = 0.15us
	//
	//PORTF = c & 0xff;
	//_delay_us(0.1);
	//PORTC = 0x00; //E = 0 RW = 0 RS = 0
	//_delay_us(1);
//}
//
//void input_string(unsigned char* arr)
//{
	//int i =0;
//
	//while (1)
	//{
		//if (i > 15)
		//break;
		//
		//if(arr[i] == NULL)
		//return;
		//
		//input_data(arr[i]);
		//i++;
	//}
	//CMD(Line_2);
	//while(1)
	//{
		//if(arr[i] == NULL)
		//return;
		//
		//input_data(arr[i]);
		//i++;
	//}
//}
//
//void init_uart()
//{
	//UBRR0H = 0x00;
	//UBRR0L = 0x67;
	//UCSR0B = 0x10;
	//UCSR0C = 0x06;
//}
//
//unsigned char rx()
//{
	//while((UCSR0A & 0x80) != 0x80)
		//;
	//
	//return UDR0;
//}
