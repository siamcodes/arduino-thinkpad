void beep() {
  digitalWrite(Beep, HIGH);
  delay(100);
}
//-------------------------------------------------------------
void sw_OK_press(void) // backward compatible function
{
  while (digitalRead(buttonPin) == HIGH)
  { Serial.println("Wait OK Press"); }
  Serial.println("OK pass");
}



//-------------------------------------------------------------
// Analog
//-------------------------------------------------------------
int analog(void)  // return 10 or 12 as resolution mode
{
  return (__analogResolution);
}

void analog10(void)
{
  __analogResolution = 10;
  //analogReadResolution(10);
}

void analog12(void)
{
  __analogResolution = 12;
  //analogReadResolution(12);
}

int analog10(int pinAN)
{
  __analogResolution = 10;
  //analogReadResolution(10);
  return (analogRead(pinAN));
}

int analog12(int pinAN)
{
  __analogResolution = 12;
  //analogReadResolution(12);
  return (analogRead(pinAN));
}

int analog(int pinAN)
{
  //analogReadResolution(__analogResolution);
  return (analogRead(pinAN));
}

int analog(int pinAN, int scale)
{
  long value;
  value = analog(pinAN);
  if (__analogResolution == 12)
  {
    value = ((value * (scale + 1)) / 4095);
  }
  else // if (__analogResolution==10)
  {
    value = ((value * (scale + 1)) / 1023);
  }
  if (value > scale)
  {
    value = scale;
  }
  return (value);
}

int analog(int pinAN, int scaleMin, int scaleMax)
{
  long value;
  value = analog(pinAN);
  if (scaleMax >= scaleMin)
  {
    if (__analogResolution == 12)
    {
      value = value / (4095 / ((scaleMax + 1) - scaleMin));
    }
    else
    {
      value = value / (1023 / ((scaleMax + 1) - scaleMin));
    }

    value += scaleMin;
    if (value > scaleMax)
    {
      value = scaleMax;
    }
  }
  else
  {
    if (__analogResolution == 12)
    {
      value = 4095 - value;
      value = value / (4095 / ((scaleMin + 1) - scaleMax));
    }
    else
    {
      value = 1023 - value;
      value = value / (1023 / ((scaleMin + 1) - scaleMax));
    }

    value += scaleMax;
    if (value > scaleMin)
    {
      value = scaleMin;
    }
  }
  return (value);
}

int __knobLastValue = 0;
