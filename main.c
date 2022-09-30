#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
unsigned char keypad();
unsigned char digit[];
int main(void)
{
	DDRC=0X0F; // Port for Keypad
	DDRB=0xFF; //Port for 7 Segment
	PORTB=0x00;
	while (1)
	{
		PORTC=0xF0;
		if(PINC!=0xF0)
		{
			if(keypad()=='1')
			{
				PORTB=0x06;
			}
			else if (keypad()=='2')
			{
				PORTB=0x5B;
			}
			else if(keypad()=='3')
			{
				PORTB=0x4F;
			}
			else if (keypad()=='4')
			{
				PORTB=0x66;
			}
			else if (keypad()=='5')
			{
				PORTB=0x6D;
			}
			else if(keypad()=='6')
			{
				PORTB=0x7D;
			}
			else if (keypad()=='7')
			{
				PORTB=0x07;
			}
			else if (keypad()=='8')
			{
				PORTB=0x7F;
			}
			else if (keypad()=='9')
			{
				PORTB=0x6F;
			}
			else if (keypad()=='0')
			{
				PORTB=0x3F;
			}
		}
	}
	return 0;
}

unsigned char keypad()
{
	PORTC=0b11111110;
	if ((PINC & (1<<4))==0)
	{
		_delay_ms(3); return '7';
	}
	else if ((PINC & (1<<5))==0)
	{
		_delay_ms(3); return '8';
	}
	else if ((PINC & (1<<6))==0)
	{
		_delay_ms(3); return '9';
	}
	PORTC=0b11111101;
	if ((PINC & (1<<4))==0)
	{
		_delay_ms(3); return '4';
	}
	else if ((PINC & (1<<5))==0)
	{
		_delay_ms(3); return '5';
	}
	else if ((PINC & (1<<6))==0)
	{
		_delay_ms(3); return '6';
	}
	PORTC=0b11111011;
	if ((PINC & (1<<4))==0)
	{
		_delay_ms(3); return '1';
	}
	else if ((PINC & (1<<5))==0)
	{
		_delay_ms(3); return '2';
	}
	else if ((PINC & (1<<6))==0)
	{
		_delay_ms(3); return '3';
	}
	PORTC=0b11110111;
	if ((PINC & (1<<5))==0)
	{
		_delay_ms(3); return '0';
	}
}
