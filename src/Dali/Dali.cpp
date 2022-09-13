#include "Dali.hpp"

uint8_t Dali::getPinRx(void)
  {
    return pinRx;
  }

uint8_t Dali::getPinTx(void)
  {
    return pinTx;
  }

bool Dali::getInverted(void)
  {
    return inverted;
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

void Dali::setInverted(bool inverted)
  {
    this->inverted = inverted;
  }

void Dali::setInterruptEnabled(bool interruptEnabled)
  {
    this->interruptEnabled = interruptEnabled;
  }

void Dali::setDaliLow(void)
  {
    digitalWrite(pinTx, inverted);
  }

void Dali::setDaliHigh(void)
  {
    digitalWrite(pinTx, !inverted);
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
    startIdle();
    delayMicroseconds(2 * TIME_MAX);
  }

void Dali::startIdle(void)
  {
    pinMode(pinTx, INPUT);
  }

void Dali::stopIdle(void)
  {
    pinMode(pinTx, OUTPUT);
  }

void Dali::sendByte(uint8_t data)
  {
      for (uint8_t i = 128; i > 0; i = i / 2)
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
