#include "Dimmer.hpp"

void Dimmer::SetNumber(uint8_t number){
  number_ = number;
}

uint8_t Dimmer::GetNumber(void){
  return number_;
}

void Dimmer::SetAddress(uint8_t address){
  address_ = address;
}

uint8_t Dimmer::GetAddress(void){
  return address_;
}

void Dimmer::SetIntensity(uint8_t intensity){
  intensity_ = intensity;
}

uint8_t Dimmer::GetIntensity(void){
  return intensity_;
}

void Dimmer::SetIntensityMin(uint8_t intensity){
  intensity_min_ = intensity;
}

uint8_t Dimmer::GetIntensityMin(void){
  return intensity_min_;
}

void Dimmer::SetIntensityMax(uint8_t intensity){
  intensity_max_ = intensity;
}

uint8_t Dimmer::GetIntensityMax(void){
  return intensity_max_;
}

void Dimmer::SetStepWidth(uint8_t step_width){
  step_width_ = step_width;
}

uint8_t Dimmer::GetStepWidth(void){
  return step_width_;
}

void Dimmer::SetDarker(bool darker){
  darker_ = darker;
}

bool Dimmer::GetDarker(void){
  return darker_;
}

bool Dimmer::GetDarkerHasChanged(void){
  return darker_has_changed_;
}

void Dimmer::IncreaseIntensity(void){
  intensity_ += step_width_;
}

void Dimmer::DecreaseIntensity(void){
  intensity_ -= step_width_;
}

void Dimmer::ChangeIntensity(void){
  if (darker_){
    if ((intensity_min_ + step_width_) <= intensity_){
      intensity_ -= step_width_;
      darker_has_changed_ = false;
      }
    else {
      intensity_ = intensity_min_;
      darker_ = false;
      darker_has_changed_ = true;
    }
  }
  else {
    if ((intensity_max_ - step_width_) >= intensity_){
      intensity_ += step_width_;
      darker_has_changed_ = false;
      }
    else {
      intensity_ = intensity_max_;
      darker_ = true;
      darker_has_changed_ = true;
    }
  }
}
