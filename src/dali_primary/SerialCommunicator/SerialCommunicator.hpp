/** @file */

#ifndef SERIAL_COMMUNICATOR_H_
#define SERIAL_COMMUNICATOR_H_

#include <Arduino.h>

#define OFFSET_ASCII 0x30

class SerialCommunicator
{
  private:
  byte incoming_byte_;
  byte incoming_digit_;
  bool data_boolean_;
  uint8_t data_8_;
  uint16_t data_16_;
  
  public:
  void Setup(void);
  bool GetDataBoolean(void);
  uint8_t GetData8(void);
  uint16_t GetData16(void);
  void ReceiveChar(void);
  bool ReceiveDigit(void);
  bool ReceiveBoolean(void);
  bool ReceiveDecDigit(void);
  bool ReceiveHexDigit(void);
};

#endif
