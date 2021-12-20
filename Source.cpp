/******************************************************************************
*	Clock.cpp																  *
*																			  *
*	Display a clock in 24 and 12-hour formats and allow user to adjust time   *
*																			  *
*	by Jon Olson															  *
******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

void DisplayMenu()
{
	cout << "		**************************" << endl;
	cout << "		* 1 - Add One Hour       *" << endl;
	cout << "		* 2 - Add One Minute     *" << endl;
	cout << "		* 3 - Add One Second     *" << endl;
	cout << "		* 4 - Exit Program       *" << endl;
	cout << "		**************************" << endl;
}

void AddHour(int& hourOffset)
{
	hourOffset++;
}

void AddMinute(int& minuteOffset)
{
	minuteOffset++;
}

void AddSecond(int& secondOffset)
{
	secondOffset++;
}

void runClock(int& seconds, int& minutes, int& hours)
{
	// get total seconds
	time_t total_seconds = time(0);

	// get values of seconds, minutes, and hours
	struct tm* ct = localtime(&total_seconds);

	seconds = ct->tm_sec;
	minutes = ct->tm_min;
	hours = ct->tm_hour;
}

void printClocks(int seconds, int minutes, int hours)
{
	int modHours;
	string timeOfDay;
	
	if (seconds >= 60)
	{
		minutes++;
		seconds %= 60;
	}

	if (minutes >= 60)
	{
		hours++;
		minutes %= 60;
	}

	hours %= 24;
	modHours = hours == 0 ? 12 : hours > 12 ? hours - 12 : hours;

	if (hours >= 12)
	{
		timeOfDay = "PM";
	}
	else
	{
		timeOfDay = "AM";
	}

	system("CLS");
	cout << "**************************        **************************" << endl;
	cout << "*     12-Hour Clock      *        *      24-Hour Clock     *" << endl;
	cout << "*       " << (modHours < 10 ? "0" : "") << modHours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << timeOfDay << "      *";
	cout << "        ";
	cout << "*         " << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << "      *\n";
	cout << "**************************        **************************" << endl;

}

const char QUIT = '4';

int main()
{
	char userInput = ' ';
	int hoursOffest = 0;
	int minutesOffest = 0;
	int	secondsOffest = 0;
	int seconds, minutes, hours;


	while (userInput != QUIT)
	{
		runClock(seconds, minutes, hours);
		
		// print clocks
		_sleep(1000);
		printClocks(seconds + secondsOffest, minutes + minutesOffest, hours + hoursOffest);
		
		DisplayMenu();

		userInput = _getch();

		switch (userInput)
		{
			case '1':
				AddHour(hoursOffest);
				break;
			case '2':
				AddMinute(minutesOffest);
				break;
			case '3':
				AddSecond(secondsOffest);
				break;
			case '4':
				break;
			default:
				cout << "Invalid selection." << endl;

		}

	}
	
	cout << "Goodbye" << endl;

	return 0;
}