#ifndef TIME_HPP
#define TIME_HPP

class Time {

private:
  int hour;
  int minute;
  int second;

public:
  Time(int = 0, int = 0 , int = 0);

  void printUniversal();
  void printStandard();
  void tick();

  inline int getHour() { return this->hour; }
  inline int getMinute() { return this->minute; }
  inline int getSecond() { return this->second; }

  void setTime(int, int, int);
  inline void setHour(int);
  void setMinute(int);
  void setSecond(int s);

};

#endif