
#include "MIDIUSB.h"
#include <FastLED.h>
#include <EEPROM.h>
#include "ctrl.h"
#include "def.h"
#if LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#endif

CRGB leds[LED_COUNT];

Variables MyVar;
Variables &mVar = MyVar;
Varr Var;
Function Func;

void setup() {

  Serial.begin(115200);
#if LCD
  lcd.init();                      // initialize the lcd
  lcd.backlight();
#endif
  pinMode(Var.PIN_OUT_0, OUTPUT);
  pinMode(Var.PIN_IN_0, INPUT);
  pinMode(Var.PIN_OUT_1, OUTPUT);
  pinMode(Var.PIN_IN_1, INPUT);
  pinMode(Var.A_0, INPUT_PULLUP);
  pinMode(Var.A_1, INPUT_PULLUP);
  pinMode(Var.A_2, INPUT_PULLUP);
  pinMode(Var.A_3, INPUT_PULLUP);
  pinMode(Var.A_4, INPUT_PULLUP);

  LEDS.addLeds<WS2812, LED_PIN_0, RGB>(leds, LED_COUNT);
  LEDS.setBrightness(255);

  //EEPROM.put(0, MyVar);
  EEPROM.get(128, mVar);

}


void loop() {

  if (MyVar.POT_BUT) {
    Potentiometres(Var.A_0, MyVar.CTRL_0, MyVar.MIDI_CHANNEL, 0, Var.analogValue, Var.lastAnalogValue);
    Potentiometres(Var.A_1, MyVar.CTRL_1, MyVar.MIDI_CHANNEL, 1, Var.analogValue, Var.lastAnalogValue);
    Potentiometres(Var.A_2, MyVar.CTRL_2, MyVar.MIDI_CHANNEL, 2, Var.analogValue, Var.lastAnalogValue);
    Potentiometres(Var.A_3, MyVar.CTRL_3, MyVar.MIDI_CHANNEL, 3, Var.analogValue, Var.lastAnalogValue);
    Potentiometres(Var.A_4, MyVar.CTRL_4, MyVar.MIDI_CHANNEL, 4, Var.analogValue, Var.lastAnalogValue);
  }
  if (MyVar.SS_BUT_L) {
    superSonic(MyVar.CTRL_5, MyVar.MIDI_CHANNEL, Var.PIN_IN_0, Var.PIN_OUT_0, 5, Var.analogValue, Var.lastAnalogValue, Var.soft);
  }
  if (MyVar.SS_BUT_R) {
    superSonic(MyVar.CTRL_6, MyVar.MIDI_CHANNEL, Var.PIN_IN_1, Var.PIN_OUT_1, 6, Var.analogValue, Var.lastAnalogValue, Var.soft);
  }
  Func.colorProg(Var.color,
                 Var.Value,
                 Var.x,
                 MyVar.LED_PROG,
                 MyVar.LED_SPEED,
                 MyVar.LED_BRIGHT,
                 Var.timer,
                 leds,
                 LED_COUNT);
#if LCD
  lcd.clear();
#endif

  while (Serial.available() > 0) {
    Var.c = Serial.read();
    if (Var.c == '\n') {
      switch ( Func.parse(Var.input_string, Var.VarArr) ) {
        case 0: {

          }
          break;
        case 1: {
            MyVar.CTRL_1 = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("CTRL_1 -");
            lcd.print(MyVar.CTRL_1);
#endif
          }
          break;
        case 2: {
            MyVar.CTRL_2 = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("CTRL_2 -");
            lcd.print(MyVar.CTRL_2);
#endif
          }
          break;
        case 3: {
            MyVar.CTRL_3 = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("CTRL_3 -");
            lcd.print(MyVar.CTRL_3);
#endif
          }
          break;
        case 4: {
            MyVar.CTRL_4 = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("CTRL_4 -");
            lcd.print(MyVar.CTRL_4);
#endif
          }
          break;
        case 5: {
            MyVar.CTRL_5 = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("CTRL_5 -");
            lcd.print(MyVar.CTRL_5);
#endif
            break;
          }
        case 6: {
            MyVar.CTRL_6 = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("CTRL_6 -");
            lcd.print(MyVar.CTRL_6);
#endif
          }
          break;
        case 7: {
            MyVar.SS_BUT_L = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("BUT_L -");
            lcd.print(MyVar.SS_BUT_L);
#endif
          }
          break;
        case 8: {
            MyVar.SS_BUT_R = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("BUT_R -");
            lcd.print(MyVar.SS_BUT_R);
#endif
          }
          break;
        case 9: {
            MyVar.POT_BUT = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("POT_BUT -");
            lcd.print(MyVar.POT_BUT);
#endif
          }
          break;
        case 10: {
            MyVar.MIDI_CHANNEL = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("MIDI_CHANNEL -");
            lcd.print(MyVar.MIDI_CHANNEL);
#endif
          }
          break;
        case 11: {
            MyVar.LATENCY = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("LATENCY -");
            lcd.print(MyVar.LATENCY);
#endif
          }
          break;
        case 12: {
            MyVar.DUR_MIN = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("DUR_MIN -");
            lcd.print(MyVar.DUR_MIN);
#endif
          }
          break;
        case 13: {
            MyVar.DUR_MAX = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("DUR_MAX -");
            lcd.print(MyVar.DUR_MAX);
#endif
          }
          break;
        case 14: {
            MyVar.SMOOTHING = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("SMOOTHING -");
            lcd.print(MyVar.SMOOTHING);
#endif
          }
          break;
        case 15: {
            MyVar.LED_PROG = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("LED_PROG -");
            lcd.print(MyVar.LED_PROG);
#endif
          }
          break;
        case 16: {
            MyVar.LED_SPEED = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("LED_SPEED -");
            lcd.print(MyVar.LED_SPEED);
#endif
          }
          break;
        case 17: {
            MyVar.LED_BRIGHT = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("LED_BRIGHT -");
            lcd.print(MyVar.LED_BRIGHT);
#endif
          } break;
        case 18: {
#if LCD
            Func.eeWrite(mVar);
            lcd.print("SAVE SAVE SAVE");
#endif
          }
          break;
        case 19: {
            Func.eeRead(mVar);
            Func._Send_Dump_(Var.dataArray, mVar);
          } break;
        case 20: {
            Func._Send_Dump_(Var.dataArray, mVar);
          }
          break;
        case 21: {

          }
          break;
        case 22: {
            Serial.print(F("CONTROL_USB\r\n"));
          }
          break;
        case 23: {

          }
          break;
        case 24: {
            MyVar.CTRL_0 = Func.Slider();
#if LCD
            lcd.setCursor(0, 0);
            lcd.print("CTRL_0 -");
            lcd.print(MyVar.CTRL_0);
#endif
          }
          break;
        case 25: {
            Serial.print("2\r\n");

          }
          break;
        case 26: {
            Serial.print("1\r\n");
          }
          break;
        case 27:
#if LCD
          lcd.setCursor(0, 0);
          lcd.print(Var.input_string);
          lcd.setCursor(0, 1);
          lcd.print("Invalid String");
#endif
          break;
      }
      Var.input_string = "";
    }
    else {
      Var.input_string += Var.c;
    }
  }
  delay(MyVar.LATENCY);
}



inline void controlChange(byte channel, byte control, byte *value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
  Var.Value[0] = value;
}

inline void Potentiometres(char anRead, byte control, byte channel, int sensor_number, int *analogValue, int *lastAnalogValue) {
  analogValue[sensor_number] = analogRead(anRead) / 8;
  if ((analogValue[sensor_number] - lastAnalogValue[sensor_number]) > 1 || (analogValue[sensor_number] - lastAnalogValue[sensor_number]) < -1) {
    if (analogValue[sensor_number] != lastAnalogValue[sensor_number]) {
      controlChange(channel, control, analogValue[sensor_number]);
      lastAnalogValue[sensor_number] = analogValue[sensor_number];
    }
  }
}

inline void superSonic(byte control, byte channel, int pin_in, int pin_out, int sensor_number, int *analogValue, int *lastAnalogValue, uint8_t *soft) {

  if (millis() - Var.timer_SS > 15) {
    digitalWrite(pin_in, LOW);
    delayMicroseconds(2);
    digitalWrite(pin_out, HIGH);
    delayMicroseconds(20);
    digitalWrite(pin_out, LOW);
    Var.duration = pulseIn(pin_in, HIGH);
    analogValue[sensor_number] = map(Var.duration, MyVar.DUR_MIN, MyVar.DUR_MAX, 0, 127);
    Var.cm = Var.duration / 29 / 2;
    if ((Var.duration <= MyVar.DUR_MIN) || (Var.duration >= MyVar.DUR_MAX))
    {
      analogValue[sensor_number] = lastAnalogValue[sensor_number];
      if ((Var.duration > MyVar.DUR_MAX) && (Var.duration < MyVar.DUR_MAX + 1000))
      {
        analogValue[sensor_number] = 127;
        controlChange(channel, control, analogValue[sensor_number]);
      }
    }
    else {


      if ((analogValue[sensor_number] - lastAnalogValue[sensor_number]) > 1 || (analogValue[sensor_number] - lastAnalogValue[sensor_number]) < -1) {
        if (analogValue[sensor_number] != lastAnalogValue[sensor_number]) {
          controlChange(channel, control, Var.softResult);
          lastAnalogValue[sensor_number] = analogValue[sensor_number];
          soft[0] = lastAnalogValue[sensor_number];
          soft[1] = soft[0];
          soft[2] = soft[1];
          soft[3] = soft[2];
          soft[4] = soft[3];
          soft[5] = soft[4];
          Var.softResult = (analogValue[sensor_number] + lastAnalogValue[sensor_number] + soft[0] + soft[1] + soft[2] + soft[3] + soft[4] + soft[5]) / 8;
          if (Var.softResult - analogValue[sensor_number] > 20) {
            Var.softResult = Var.lastSoftResult;
          }
          Var.timer_SS = millis();
          Var.lastSoftResult = Var.softResult;
        }
      }
    }
  }
}
