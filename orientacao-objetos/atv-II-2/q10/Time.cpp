#include <ctime>
using namespace std;

#include <iostream>
using std::cout;
using std::endl;

//biblioteca que permite alguns controles sobre a saída
#include <iomanip>
using std::setfill; 
using std::setw;

#include "Time.hpp"

// Setando com a hora atual
Time::Time() {
  time_t secsAtual = time(nullptr);
  struct tm *dateAtual = localtime(&secsAtual);

  // Setando para o timezone brasileiro
  dateAtual->tm_hour -= 3;

  int h = dateAtual->tm_hour;
  int m = dateAtual->tm_min;
  int s = dateAtual->tm_sec;

  setTime(h, m, s);
}

Time::Time(int hr, int min, int sec)
{
  setTime(hr, min, sec);  
  //qualquer modificação posterior em setTime reflete no construtor
}

void Time::setTime(int h, int m, int s)
{
  setHour(h);
  setMinute(m);
  setSecond(s);  
}

void Time::setHour(int h)
{
  hour = (h >=0 && h < 24) ? h : 0;     //valida horas
}

//forma 2
inline void Time::setMinute(int m)
{
  minute = (m >= 0 && m < 60) ? m : 0;  //valida minutos
}

void Time::printUniversal()
{
  cout << setfill('0') << setw(2) << getHour() << ":" <<
  setw(2) << getMinute() << ":" << setw(2) << getSecond() << endl;
}

void Time::printStandard()
{
  cout << ( (getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM") << endl;
}
