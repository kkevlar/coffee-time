#include "coffee.hpp"

Servo s;

void boil()
{
	s.write(180);
	delay(2000);
	s.write(90);
}

void noboil()
{
	s.write(0);
	delay(2000);
	s.write(90);
}

void coffee()
{
	unsigned long earlier_time;
	unsigned long later_time;
	unsigned long duration_on;
	unsigned long duration_off_init;
	unsigned long duration_off_again;

	duration_on = 1000;
	duration_off_again = 23*1000;
	duration_off_init = FUTURE_SECONDS;

	duration_on *= 1000;
	duration_off_init *= 1000;
	duration_off_again *= 3600;

	earlier_time = millis();
	while(1)
	{
		later_time = millis();
		if(later_time - earlier_time > duration_off_init)
		{
			earlier_time = millis();
			boil();
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
				noboil();
				break;
			}
			else
			{
				boil();
				for(int z = 0; z < 60; z++)
				{
				delay(5 * 1000);
				}
			}
		}
		while(1)
		{
			later_time = millis();
			if(later_time - earlier_time > duration_off_again)
			{
				earlier_time = millis();
				boil();
				break;
			}
		}
	}

}


void setup() 
{
	pinMode(A2,OUTPUT);
}

void loop() 
{
	s.attach(3);
	delay(3000);
	noboil();
	delay(3000);
	boil();
	delay(3000);
	noboil();
	delay(3000);
	boil();
	delay(3000);
	noboil();
	delay(3000);
	boil();
	delay(3000);
	noboil();
	delay(3000);

	coffee();
}

