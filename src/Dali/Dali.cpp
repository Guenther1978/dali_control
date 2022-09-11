#include "Dali.hpp"

#define DALI_LOW 1
#define DALI_HIGH 0

uint8_t Dali::getPinRx(void)
  {
    return pinRx;
  }

uint8_t Dali::getPinTx(void)
  {
    return pinTx;
  }

bool Dali::getInterruptEnabled(void)
  {
    return interruptEnabled;
  }

void Dali::setPinRx(uint8_t pinRx)
  {
    this->pinRx = pinRx;
    pinMode(pinRx, INPUT);
  }

void Dali::setPinTx(uint8_t pinTx)
  {
    this->pinTx = pinTx;
    pinMode(pinTx, OUTPUT);
  }

void Dali::setInterruptEnabled(bool interruptEnabled)
  {
    this->interruptEnabled = interruptEnabled;
  }

void Dali::setDaliLow(void)
  {
    digitalWrite(pinTx, DALI_LOW);
  }

void Dali::setDaliHigh(void)
  {
    digitalWrite(pinTx, DALI_HIGH);
  }

void Dali::sendZero(void)
  {
    setDaliLow();
    delayMicroseconds(TIME_HALF_BIT);
    setDaliHigh();
    delayMicroseconds(TIME_HALF_BIT);
  }

void Dali::sendOne(void)
  {
    setDaliHigh();
    delayMicroseconds(TIME_HALF_BIT);
    setDaliLow();
    delayMicroseconds(TIME_HALF_BIT);
  }

void Dali::sendStart(void)
  {
    sendOne();
  }

void Dali::sendStop(void)
  {
    setDaliHigh();
    delayMicroseconds(2 * TIME_MAX);
  }

void Dali::sendByte(uint8_t data)
  {
    for (uint8_t i = 128; i > 0; i >> 1)
      {
        if (i & data)
          {
            sendOne();
          }
        else
          {
            sendZero();
          }
      }
  }
