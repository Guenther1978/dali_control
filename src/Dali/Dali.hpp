#ifndef _DALI_HPP
#define _DALI_HPP

#include <Arduino.h>
#include <stdint.h>

#define TIME_HALF_BIT 417
#define TIME_MIN 376
#define TIME_MAX 458
#define TIME_NEW_BIT 625

union forwardFrame{
  uint16_t data_16;
  uint8_t data_8[2];
};

class Dali{
  private:
  union forwardFrame daliData;
  uint8_t pinRx;
  uint8_t pinTx;
  bool inverted;
  bool interruptEnabled;
  protected:
  void sendZero(void);
  void sendOne(void);
  void setDaliLow(void);
  void setDaliHigh(void);
  public:
  void setPinRx(uint8_t);
  void setPinTx(uint8_t);
  void setInverted(bool);
  void setInterruptEnabled(bool);
  uint8_t getPinRx(void);
  uint8_t getPinTx(void);
  bool getInverted(void);
  bool getInterruptEnabled(void);
  void sendStart(void);
  void sendStop(void);
  void startIdle(void);
  void stopIdle(void);
  bool testIdle(void);
  void waitStart(void);
  void sendByte(uint8_t);
  uint8_t receiveByte(void);
};

class DaliPrimary : public Dali{
  public:
  uint8_t receive(void);
  void send(uint16_t);
};

class DaliSecondary : public Dali{
  public:
  uint16_t receive(void);
  void send(uint8_t);
};

#endif
