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
		////PORTA = i;		// å���� �̳����� �����ϰ� �;����� ���� PORTA 0xff = PORTA 255
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
//#define __DELAY_BACKWARD_COMPATIBLE__ // Dealy �Լ��� ����� �ƴ� ����,�μ��� ����Ҷ��� �������־���Ѵ�
//#define F_CPU 16000000UL //cpu �� ó���ӵ� 16Mhz �� �������� ,delay.h �� F_CPU �� �־ �̸� �������ش� UL = unsigned long
//#include <util/delay.h>
//
//int main (void)
//{	
	//DDRA = 0xff;
	//while (1){
	//PORTA = rand()%256; //0~255������ ���� ��µǰ� ���� ������ ���� ���������� Ŭ������
	//_delay_ms ((1500); //50 + 1 ���ϴ°� 51������ ����������� 0�ϰ�� 0���� ���� �ȵ� 1�� �ణ ������� 
	////_delay_ms(100 ~ 5000) 0.1��~ 5�� ���̷� �����ϵ��� �����Ѵ�.	
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
		
		if ((PINA & 0x01) == 0x01) // ����ġ ��ٿ��
			{
				_delay_ms(10); // 10ms ��޸���
				while((PINA & 0x01) != 0x01) //��޷ȴµ��� 0�ϰ�� LED �� ������ �� ��ٿ���߿��� LED ����
					PORTA = 0x00;
				PORTA = 0xff; // 10ms ��޸��� ���� �Է��ϰ�� LED �Ѷ�
				_delay_ms(10);
			}
		PORTA = 0X00;
		_delay_ms(1);
	}
}