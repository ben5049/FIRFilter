#ifndef FIR_FILTER_H
#define FIR_FILTER_H

#ifdef ARDUINO
#include "Arduino.h"
#endif

/* Pre-existing filters */
typedef enum {
  FIR_FILTER_LPF2 = 0x00,
  FIR_FILTER_LPF20 = 0x01,
  FIR_FILTER_LPF50 = 0x02
} FIRFilterType;

/* FIR filter class */
class FIRFilter {

private:

  float *FIRImpulseResponse;
  uint8_t FIRFilterLength;

  uint8_t bufIndex;
  float *buf;

  bool custom;

public:

  /* Initialise either a custom or premade FIR filter*/
  void FIRFilterInitCustom(uint8_t length, float *coefficients);
  void FIRFilterInitPremade(FIRFilterType type);

  /* Update FIR filter with a new sample */
  float FIRFilterUpdate(float input);

  /* The current output value of the FIR filter */
  float output;

  /* Destructor */
  ~FIRFilter();
};

#endif