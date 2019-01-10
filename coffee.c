#include "coffee.h"

void coffee()
{
	unsigned long earlier_time;
	unsigned long later_time;
	unsigned long duration_on;
	unsigned long duration_off_init;
	unsigned long duration_off_again;

	duration_on = 1000*3600;
	duration_off_again = 23*3600*1000;
	duration_off_init = 1*1000;

	earlier_time = millis();
	while(1)
	{
		later_time = millis();
		if(later_time - earlier_time > duration_off_init)
		{
			earlier_time = millis();
			digitalWrite(A2,HIGH);
			break;
		}
	}
	while(1)
	{	
		while(1)
		{
			later_time = millis();
			if(later_time - earlier_time > duration_on)
			{
				earlier_time = millis();
				digitalWrite(A2,LOW);
				break;
			}
		}
		while(1)
		{
			later_time = millis();
			if(later_time - earlier_time > duration_off_again)
			{
				earlier_time = millis();
				digitalWrite(A2,HIGH);
				break;
			}
		}
	}

}


void setup() 
{
	pinMode(A2,OUTPUT);

	delay(500);
	digitalWrite(A2,LOW);
	delay(500);
	digitalWrite(A2,HIGH);
	delay(500);
	digitalWrite(A2,LOW);
	delay(500);
	digitalWrite(A2,HIGH);
	delay(500);
	digitalWrite(A2,LOW);
	delay(500);


	coffee();

	for(int i = 0; i < 120; i++)
	{
		delay(60000);
	}

	digitalWrite(A2,LOW);

}

void loop() 
{

	delay(1000);

}

