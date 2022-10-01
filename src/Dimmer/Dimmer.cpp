#include "Dimmer.hpp"

void Dimmer::SetNumber(uint8_t number){
  nummber_ = number;
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

void Dimmer::SetStepWidth(uint8_t step_width){
  step_width_ = step_width
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

