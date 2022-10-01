#ifndef _DIMMER_HPP
#define _DIMMER_HPP

#include <Arduino.h>
#include <stdint.h>

class Dimmer{
  private:
  uint8_t number_;
  uint8_t address_;
  uint8_t intensity_;
  uint8_t step_width_;
  bool darker_;
  bool dimmable_;
  bool wait_at_min_;
  bool wait_at_max_;
  public:
  void SetNumber(uint8_t);
  uint8_t GetNumber(void);
  void SetAddress(uint8_t);
  uint8_t GetAddress(void);
  void SetIntensity(uint8_t);
  uint8_t GetIntensity(void);
  void SetStepWidth(uint8_t);
  uint8_t GetStepWidth(void);
  void SetDarker(bool);
  bool GetDarker(void);
  void SetDimmable(bool);
  bool GetDimmable(void);
  void SetWaitAtMin(bool);
  bool GetWaitAtMin(void);
  void SetWaitAtMax(bool);
  bool GetWaitAtMax(void);  
};

#endif
