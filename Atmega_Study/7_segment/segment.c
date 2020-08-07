 //#include <avr/io.h>
 //#define __DELAY_BACKWARD_COMPATLE_ // delay 에 상수말고 변수 사용가능하도록 락을 풀어주는 설정
 //#define F_CPU 16000000UL // cpu 속도에 따라 다르지만 128A는 16Mhz 의 속도의 cpu 
 //#include <util/delay.h> // delay 함수 사용 _delay_ms = 10^-3 _delay_us 10^6 사용가능하다

// 목표 
// 1.전화번호가 우측으로 1비트씩 이동 
// 2.마지막 번호에 도달시 다시 좌측으로 1비트로 이동
// 3.무한 루프 

//010-9726-0026
//0 : PORTG = 0x3f		0011 1111   63
//1 : PORTG = 0X06		0000 1010	6
//2 : PORTG = 0X53;		0101 1011	91 
//7 : PORTG = 0X07;		0000 0111	7
//6 : PORTG = 0X78		0111 1100	124
//8 : PORTG = 0x7f		0111 1111	127
//9 : PORTG = 0X67		0110 0111	103
// -: PORTG = 0x40		64
//배열로 만들경우 
// int phone [13] = {63,6,63,64,103,7,91,124,64,63,63,91,127}
				//    0 1  0  -  9  7 2   6  - 0  0   2   8
 //int main(void)
 //{
	 //int phone [13] = {63,6,63,64,103,7,91,124,64,63,63,91,127};
		////010-9726-0028 표현식
	 //DDRC = 0xff; // PORTC OUTPUT
	 //DDRG = 0x0f; // PORTG OUTPUT
	 //while (1)
	 //{
		 //
		 //for (int i = 0 ; i < 9 ; i++){
			//
			//for(int j = 0 ; j <25 ; j++){  //40ms *25  1초간 3번 약 1초간 
				//PORTG = 0x0e;  
				//PORTC = phone[i]; //9
				//_delay_ms(10);
			//
				//PORTG = 0x0d;
				//PORTC = phone[i+1];//10
				//_delay_ms(10);
				//
				//PORTG = 0x0b;
				//PORTC = phone[i+2]; //11
				//_delay_ms(10);
					//
				//PORTG = 0x07;
				//PORTC = phone[i+3]; //12
				//_delay_ms(10);
			//}
		 //}
		 	 //
		  //for (int i = 9 ; i > 0 ; i--){
				  //for(int j = 0 ; j <25 ; j++){  //40ms *25  1초간 3번 약 1초간 
				  //PORTG = 0x0e;
				  //PORTC = phone[i]; //9
				 	 //_delay_ms(10);
			  //
				  //PORTG = 0x0d;
				  //PORTC = phone[i+1]; //10
					 //_delay_ms(10);
			  //
				  //PORTG = 0x0b;
				  //PORTC = phone[i+2];// 11
					 //_delay_ms(10);
			  //
				  //PORTG = 0x07;
				  //PORTC = phone[i+3]; //12
				  	//_delay_ms(10);
				  //}
		  //}
	 //} 
 //}

 //#include <avr/io.h>
 //
 //#define __DELAY_BACKWARD_COMPATLE_
 //#define F_CPU 16000000UL
 //#include <util/delay.h>
//
 //int main(void)
 //{u
	 //
	 //DDRC = 0xff;
	 //DDRG = 0xff;
	 //
	 //while (1)
	 //{
		 //DDRG = 0x01;
		 //PORTC = 7;
		 //_delay_ms(5);
		 //DDRG = 0x02;
		 //PORTC = 7;
		 //_delay_ms(5);
		 //DDRG = 0x04;
		 //PORTC = 7;
		 //_delay_ms(5);
		 //DDRG = 0x08;
		 //PORTC = 7;
		 //_delay_ms(5);
	 //}
	 //
 //}
//
