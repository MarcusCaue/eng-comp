#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setfill; 
using std::setw;

#include "Time.hpp"

void Time::tick() {  
  int oldSec = this->second;
  
  setSecond(oldSec + 1);
  
  // Mudar o minuto => 11h50m59 + 1s -> 11h51m00 
  if (oldSec == 59) {
    int oldMin = this->minute;
    setMinute(oldMin + 1);

    // Mudar a hora => 11h59m59 + 1s -> 12h00m00
    if (oldMin == 59) {
      int oldHour = this->hour;
      setHour(oldHour + 1);
    }
  }
}

Time::Time(int hr, int min, int sec) {
  setTime(hr, min, sec);  
}

void Time::setTime(int h, int m, int s) {
  setHour(h);
  setMinute(m);
  setSecond(s);  
}

void Time::setHour(int h) { this->hour = (h >= 0 && h < 24) ? h : 0; }
inline void Time::setMinute(int m) { this->minute = (m >= 0 && m < 60) ? m : 0; }
inline void Time::setSecond(int s) { this->second = (s >= 0 && s < 60) ? s : 0; }

void Time::printUniversal() {
  cout << setfill('0') << setw(2) 
       << getHour() << ":" << setw(2) 
       << getMinute() << ":" << setw(2) 
       << getSecond() << endl
  ;
}

void Time::printStandard() {
  cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) 
       << getMinute() << ":" << setw(2) 
       << getSecond() << (getHour() < 12 ? " AM" : " PM") << endl
  ;
}