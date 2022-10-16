#include "Dimmer.hpp"

void Dimmer::SetNumber(uint8_t number)
{
  number_ = number;
}

uint8_t Dimmer::GetNumber(void)
{
  return number_;
}

void Dimmer::SetAddress(uint8_t address)
{
  address_ = address;
}

uint8_t Dimmer::GetAddress(void)
{
  return address_;
}

void Dimmer::SetIntensity(uint8_t intensity)
{
  intensity_ = intensity;
}

uint8_t Dimmer::GetIntensity(void)
{
  return intensity_;
}

void Dimmer::SetIntensityMin(uint8_t intensity)
{
  intensity_min_ = intensity;
}

uint8_t Dimmer::GetIntensityMin(void)
{
  return intensity_min_;
}

void Dimmer::SetIntensityMax(uint8_t intensity)
{
  intensity_max_ = intensity;
}

uint8_t Dimmer::GetIntensityMax(void)
{
   return intensity_max_;
}

void Dimmer::SetIntensityDefaultMin(uint8_t intensity)
{
  intensity_default_min_ = intensity;
}

uint8_t Dimmer::GetIntensityDefaultMin(void)
{
  return intensity_default_min_;
}

void Dimmer::SetIntensityDefaultMax(uint8_t intensity)
{
  intensity_default_max_ = intensity;
}

uint8_t Dimmer::GetIntensityDefaultMax(void)
{
    return intensity_default_max_;
}

void Dimmer::SetStepWidth(uint8_t step_width)
{
  step_width_ = step_width;
}

void Dimmer::SetStepWidthMin(uint8_t step_width)
{
  step_width_min_ = step_width;
}

void Dimmer::SetStepWidthMax(uint8_t step_width)
{
  step_width_max_ = step_width;
}

uint8_t Dimmer::GetStepWidth(void)
{
  return step_width_;
}

void Dimmer::SetDarker(bool darker)
{
  darker_ = darker;
}

bool Dimmer::GetDarker(void)
{
  return darker_;
}

void Dimmer::SetDimmable(bool dimmable)
{
  dimmable_ = dimmable;
}

bool Dimmer::GetDimmable(void)
{
  return dimmable_;
}

bool Dimmer::GetIntensityAtMin(void)
{
  return intensity_at_min_;
}

bool Dimmer::GetIntensityAtMax(void)
{
  return intensity_at_max_;
}

void Dimmer::SetWaitAtMin(bool wait)
{
  wait_at_min_ = wait;
}

bool Dimmer::GetWaitAtMin(void)
{
  return wait_at_min_;
}

void Dimmer::SetWaitAtMax(bool wait)
{
  wait_at_max_= wait;
}

bool Dimmer::GetWaitAtMax(void)
{
  return wait_at_max_;
}

void Dimmer::SetDelayEnabled(bool delay)
{
  delay_enabled_ = delay;
}

bool Dimmer::GetDelayEnabled(void)
{
  return delay_enabled_;
}

void Dimmer::SetDelayCycles(uint8_t cycles)
{
  delay_cycles_ = cycles;
}

uint8_t Dimmer::GetDelayCycles(void)
{
  return delay_cycles_;
}

void Dimmer::SetMewMinIntAtMax(bool new_int)
{
  new_min_int_at_max_ = new_int;
}

bool Dimmer::GetNewMinIntAtMax(void)
{
  return new_min_int_at_max_;
}

void Dimmer::SetNewMaxIntAtMin(bool new_int)
{
  new_max_int_at_min_ = new_int;
}

bool Dimmer::GetNewMaxIntAtMin(void)
{
  return new_max_int_at_min_;
}

void Dimmer::SetNewStepWidthAtMin(bool step)
{
  new_step_width_at_min_ = step;
}

bool Dimmer::GetNewStepWidthAtMin(void)
{
  return new_step_width_at_min_;
}

void Dimmer::SetNewStepWidthAtMax(bool step)
{
  new_step_width_at_max_ = step;
}

bool Dimmer::GetNewStepWidthAtMax(void)
{
  return new_step_width_at_max_;
}

void Dimmer::IncreaseIntensity(void)
{
  intensity_ += step_width_;
}

void Dimmer::DecreaseIntensity(void)
{
  intensity_ -= step_width_;
}

void Dimmer::ChangeIntensity(void)
{
if (dimmable_) {
  if (darker_){
    if ((intensity_min_ + step_width_) <= intensity_){
      intensity_ -= step_width_;
      intensity_at_min_ = false;
      }
    else {
      intensity_ = intensity_min_;
      darker_ = false;
      intensity_at_min_ = true;
      }
    }
  else {
    if ((intensity_max_ - step_width_) >= intensity_){
      intensity_ += step_width_;
      intensity_at_max_ = false;
      }
    else {
      intensity_ = intensity_max_;
      darker_ = true;
      intensity_at_max_ = true;
      }
    }
  }
}

void SetSpeedControlCounter(uint8_t counter)
{
  speed_control_.setCounter(counter);
}

uint8_t GetSpeedControlCounter(void)
{
  return speed_control_.getCounter(void);
}
