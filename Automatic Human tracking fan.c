
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
	


int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

int main(void)
{
	char string[10];
	long count;
	double distance;
	
	
	
	DDRA=0b11111000;
	
	sei();			/* Enable global interrupt */
			/* Set all bit to zero Normal operation */

	ICR1=19999;

    int var=ICR1-1500;
	int left=0;
	int middle=0;
	int right=0;
	
	while(1)
	{
		
		

		
		int temp=DDRA;
		
		if(PINA == 0b00000001)
		{
			if(left==1)
			{
				continue;
			}
			else{
				left=1;
			}
			
			if(middle==1)
			{
				
				middle=0;
			}
			
			if(right==1)
			{
				
				right=0;
			}
			TCNT1=0;
			TIFR=0;
			TCCR1B=0;
			TCCR1A=0;
			DDRA=0xFF;
			DDRB=0xFF;
				
			DDRD = 0b11111011;
			TCCR1A |= (1<<WGM11) | (1<<COM1A1) | (1<<COM1A0);
			TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS10) ;
			ICR1 = 19999;
			
			
			OCR1A = 19999-1000;
			
			
		}
		DDRA=temp;
		

		
		 temp=DDRA;
		
		
		if(PINA == 0b00000010)
		{
			if(middle==1)
			{
				continue;
			}
			else{
				middle=1;
			}
			
			if(left==1)
			{
				
				left=0;
			}
			
			if(right==1)
			{
				
				right=0;
			}
			
			TCNT1=0;
			TIFR=0;
			TCCR1B=0;
			TCCR1A=0;
			DDRA=0xFF;
			DDRB=0xFF;
			
			DDRD = 0b11111011;
			TCCR1A |= (1<<WGM11) | (1<<COM1A1) | (1<<COM1A0);
			TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS10) ;
			ICR1 = 19999;
			
			
			OCR1A = 19999-1500;
			
			_delay_ms(100);
			
			
		}
		
		
		
		
		
		
		
		DDRA=temp;
		
		if(PINA == 0b00000100)
		{
			if(right==1)
			{
				continue;
			}
			else{
				right=1;
			}
			
			if(middle==1)
			{
				
				middle=0;
			}
			
			if(left==1)
			{
				
				left=0;
			}
			TCNT1=0;
			TIFR=0;
			TCCR1B=0;
			TCCR1A=0;
			DDRA=0xFF;
			DDRB=0xFF;
			
			DDRD = 0b11111011;
			TCCR1A |= (1<<WGM11) | (1<<COM1A1) | (1<<COM1A0);
			TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS10) ;
			ICR1 = 19999;
			
			
			OCR1A = 19999-2000;
			
			_delay_ms(100);
			
			
		}
		
		DDRA=0b11111000;
		
		
		_delay_ms(200);
	}
}


