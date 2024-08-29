#ifndef TIME_H
#define TIME_H

class Time {
	private:
		int hour;
		int minute;
		int second;
		
	public:
		Time(int hour = 0, int minute = 0, int second = 0); // constructor
		//
		int getHour() const;
		void setHour(int hour);
		//
		int getMinute() const;
		void setMinute(int minute);
		//
		int getSecond() const;
		void setSecond(int second);
		//
		void nextSecond();
		void print() const;
};

#endif
