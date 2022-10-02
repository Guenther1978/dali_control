#ifndef _DIMMER_HPP
#define _DIMMER_HPP

#include <Arduino.h>
#include <stdint.h>

class Dimmer{
  private:
  uint8_t number_;
  uint8_t address_;
  uint8_t intensity_;
  uint8_t intensity_min_;
  uint8_t intensity_max_;
  uint8_t intensity_default_min_;
  uint8_t intensity_default_max_;
  uint8_t step_width_;
  uint8_t delay_cycles_;
  bool darker_;
  bool dimmable_;
  bool intensity_at_min_;
  bool intensity_at_max_;
  bool wait_at_min_;
  bool wait_at_max_;
  bool delay_at_min_;
  bool delay_at_max_;
  bool new_min_int_at_max_;
  bool new_max_int_at_min_;
  bool new_step_width_at_min_;
  bool new_step_width_at_max_;
  public:
  void SetNumber(uint8_t);
  uint8_t GetNumber(void);
  void SetAddress(uint8_t);
  uint8_t GetAddress(void);
  void SetIntensity(uint8_t);
  uint8_t GetIntensity(void);
  void SetIntensityMin(uint8_t);
  uint8_t GetIntensityMin(void);
  void SetIntensityMax(uint8_t);
  uint8_t GetIntensityMax(void);
  void SetIntensityDefaultMin(uint8_t);
  uint8_t GetIntensityDefaultMin(void);
  void SetIntensityDefaultMax(uint8_t);
  uint8_t GetIntensityDefaultMax(void);
  void SetStepWidth(uint8_t);
  uint8_t GetStepWidth(void);
  void SetDarker(bool);
  bool GetDarker(void);
  bool GetIntensityAtMin(void);
  bool GetIntensityAtMax(void);
  void SetDimmable(bool);
  bool GetDimmable(void);
  void SetWaitAtMin(bool);
  bool GetWaitAtMin(void);
  void SetWaitAtMax(bool);
  bool GetWaitAtMax(void);
  void SetDelayAtMin(bool);
  bool GetDelayAtMin(void);
  void SetDelayAtMax(bool);
  bool GetDelayAtMax(void);
  void SetMewMinIntAtMax(bool);
  bool GetNewMinIntAtMax(void);
  void SetNewMaxIntAtMin(bool);
  bool GetNewMaxIntAtMin(void);
  void SetNewStepWidthAtMin(bool);
  bool GetNewStepWidthAtMin(void);
  void SetNewStepWidthAtMax(bool);
  bool GetNewStepWidthAtMax(void);
  void IncreaseIntensity(void);
  void DecreaseIntensity(void);
  void ChangeIntensity(void);
};

#endif
