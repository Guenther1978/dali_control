#ifndef _DALI_HPP
#define _DALI_HPP

#include <Arduino.h>
#include <stdint.h>

#define DALI_LOW HIGH
#define DALI_HIGH LOW
#define TIME_HALF_BIT 417
#define TIME_MIN 376
#define TIME_MAX 458
#define TIME_NEW_BIT 625

class Dali{
  private:
  uint8_t pinRx;
  uint8_t pinTx;
  bool interruptEnabled;
  protected:
  void sendZero(void);
  void sendOne(void);
  void setDaliLow(void);
  void setDaliHigh(void);
  public:
  void setPinRx(uint8_t);
  void setPinTx(uint8_t);
  void setInterruptEnabled(bool);
  uint8_t getPinRx(void);
  uint8_t getPinTx(void);
  bool getInterruptEnabled(void);
  void sendStart(void);
  void sendStop(void);
  void sendByte(uint8_t);
};

class DaliPrimary : public Dali{
};

class DaliSecondary : public Dali{
};

#endif
