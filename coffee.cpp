#include "coffee.hpp"

Servo s;
LiquidCrystal lcd(2,3,4,5,6,7);

void boil()
{
	s.write(180);
	delay(500);
	s.write(90);
}

void noboil()
{
	s.write(0);
	delay(500);
	s.write(90);
}

void format_time_string(char* buf, unsigned long secs)
{
	uint8_t h = secs / 3600;
	uint8_t m = (secs / 60) % 60;
	uint8_t s = secs % 60;
	sprintf(buf,"%u:%02u:%02u", h, m, s);
}

void coffee()
{
	unsigned long earlier_time;
	unsigned long later_time;
	unsigned long duration_on;
	unsigned long duration_off_init;
	unsigned long duration_off_again;
	unsigned long duration_temp;

	duration_on = 1000;
	duration_off_again = 23*1000;
	duration_off_init = FUTURE_SECONDS;

	// duration_off_init -= 8*60;

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
		else
		{
			lcd.clear();
			char buf[16];
			duration_temp = duration_off_init;
			duration_temp -= later_time;
			duration_temp /= 1000;
			format_time_string(buf,duration_temp);
			lcd.print(buf);
			delay(500);
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
			else
			{
				lcd.clear();
				char buf[16];
				duration_temp = duration_off_again;
				duration_temp -= later_time;
				duration_temp += earlier_time;
				duration_temp /= 1000;
				format_time_string(buf,duration_temp);
				lcd.print(buf);
				delay(500);
			}
		}
	}

}


void setup() 
{
	lcd.begin(16, 2);

	lcd.clear();

	lcd.print("hello world");
	s.attach(9);
}


void loop() 
{
	delay(1000);
	noboil();
	delay(1000);
	boil();
	delay(1000);
	noboil();
	delay(1000);
	boil();
	delay(1000);
	noboil();
	delay(1000);
	boil();
	delay(1000);
	noboil();
	delay(1000);

	coffee();
}

