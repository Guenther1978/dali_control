#include "SerialCommunicator.hpp"

void SerialCommunicator::Setup(void)
{
  Serial.begin(9600);
}

bool SerialCommunicator::GetDataBoolean(void)
{
  return data_boolean_;
}

uint8_t SerialCommunicator::GetData8(void)
{
  return data_8_;
}

uint16_t SerialCommunicator::GetData16(void)
{
  return data_16_;
}

void SerialCommunicator::ReceiveChar(void)
{
  incoming_byte_ = 0;
  
  if (Serial.available())
    {
      incoming_byte_ = Serial.read();
      Serial.write(incoming_byte_);
    }
}

bool SerialCommunicator::ReceiveDigit(void)
{
  bool conversion_succesful = true;
  
  ReceiveChar();
  
  switch (incoming_byte_)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      incoming_digit_ = incoming_byte_ - OFFSET_ASCII;
      break;
    case 'a':
    case 'A':
      incoming_digit_ = 10;
      break;
    case 'b':
    case 'B':
      incoming_digit_ = 11;
      break;
    case 'c':
    case 'C':
      incoming_digit_ = 12;
      break;
    case 'd':
    case 'D':
      incoming_digit_ = 13;
      break;
    case 'e':
    case 'E':
      incoming_digit_ = 14;
      break;
    case 'f':
    case 'F':
      incoming_digit_ = 15;
      break;
    case 'n':
    case 'N':
      incoming_digit_ = 0;
      break;
    case 'y':
    case 'Y':
    case 'j':
    case 'J':
      incoming_digit_ = 1;
    default:
      conversion_succesful = false;
      break;
    }
}

bool SerialCommunicator::ReceiveBoolean(void)
{
  bool conversion_succesful = false;
  
  ReceiveDigit();

  switch (incoming_digit_)
    {
    case 0:
      data_boolean_ = false;
      conversion_succesful = true;
      break;
    case 1:
      data_boolean_ = true;
      conversion_succesful = true;
      break;
    default:
      break;
    }
      
  return conversion_succesful;
}



bool SerialCommunicator::ReceiveDecDigit(void)
{
  bool conversion_succesful = true;
  
  ReceiveDigit();
  
  switch (incoming_byte_)
    {
            	    
    }
  
  return conversion_succesful;
}

bool SerialCommunicator::ReceiveHexDigit(void)
{
  bool conversion_succesful = true;
  
  ReceiveDigit();
  
  return conversion_succesful;
}
