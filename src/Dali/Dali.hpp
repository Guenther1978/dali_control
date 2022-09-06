#ifndef _DALI_HPP
#define _DALI_HPP

#include <stdint.h>

#define DALI_LOW 1
#define DALI_HIGH 0

union daliDataField{
  uint16_t forwardFrame;
  uint8_t data[2];
};

class Dali{
  private:
  uint8_t pinRx;
  uint8_t pinTx;
  bool pinRxHasInterrupt;
  protected:
  union daliDataField daliData;
  void sendZero(void);
  void sendOne(void);
  void setDaliLow(void);
  void setDaliHigh(void);
  void sendStart(void);
  void sendStop(void);
  public:
  void setPinRx(uint8_t);
  void setPinTx(uint8_t);
  void setPinRxHasInterrupt(bool);
  uint8_t getPinRx(void);
  uint8_t getPinTx(void);
  bool getPinRxHasInterrupt(void);
};

class DaliPrimary : public Dali{
  public:
  uint8_t receive(void);
  void send(uint16_t);
};

class DaliSecondary : public Dali{
  public:
  uint16_t receive(void);
  void send(uint8_t):
};

#endif
