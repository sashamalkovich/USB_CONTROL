

class Variables {
  public:
    uint8_t CTRL_0;
    uint8_t CTRL_1;
    uint8_t CTRL_2;
    uint8_t CTRL_3;
    uint8_t CTRL_4;
    uint8_t CTRL_5;
    uint8_t CTRL_6;
    uint8_t SS_BUT_L;
    uint8_t SS_BUT_R;
    uint8_t POT_BUT;
    uint8_t MIDI_CHANNEL;
    uint8_t LATENCY;
    uint16_t DUR_MIN;
    uint16_t DUR_MAX;
    uint8_t SMOOTHING;
    uint8_t LED_PROG;
    float LED_SPEED;
    uint8_t LED_BRIGHT;

};
class Varr  {
  public:
    String dataArray[17];
    const String VarArr[27] = {
      "__0__",    // 0
      "__POT_Ctrl_1__",    // 1
      "__POT_Ctrl_2__",    // 2
      "__POT_Ctrl_3__",    // 3
      "__POT_Ctrl_4__",    // 4
      "__SS_Ctrl_L__",     // 5
      "__SS_Ctrl_R__",     // 6
      "__SS_B_L__",        // 7
      "__SS_B_R__",         // 8
      "__Pot_B__",         // 9
      "__MIDI_Chan__",     // 10
      "__Latency__",       // 11
      "__Dist_min__",      // 12
      "__Dist_max__",      // 13
      "__Smooth__",        // 14
      "__L_P__",           // 15
      "__L_S__",           // 16
      "__L_B__",           // 17
      "__Save__",          // 18
      "__Refresh__",       // 19
      "__SEND_D__",        // 20
      "__RECIVE_D__",      // 21
      "__CHECK_DEV__",     // 22
      "__Test_2__",        // 23
      "__POT_Ctrl_0__",    // 24
      "__2__",             // 25
      "__3__"              // 26
    };

    long duration, cm;
    int analogValue[7] = {0, 0, 0, 0, 0, 0, 0};
    int lastAnalogValue[7] = {127, 127, 127, 127, 127, 127, 127};
    uint8_t soft[7];
    uint8_t softResult, lastSoftResult;
    uint16_t x[4];
    uint16_t y[3];
    uint32_t timer_SS;
    uint8_t Value[2];
    uint32_t timer;
    float color[3];
    char c;
    String input_string = "";

    int PIN_OUT_0 = 8;
    int PIN_OUT_1 = 11;
    int PIN_IN_0 = 9;
    int PIN_IN_1 = 12;

    int A_0 = A0;
    int A_1 = A1;
    int A_2 = A4;
    int A_3 = A6;
    int A_4 = A7;

};

class Function {
  public:
    byte parse(String input_string, const String *VarArr) {
      if (input_string.equals(VarArr[0]) == true) {
        return 0;
      }
      else if (input_string.equals(VarArr[1]) == true) {
        return 1;
      }
      else if (input_string.equals(VarArr[2]) == true) {
        return 2;
      }
      else if (input_string.equals(VarArr[3]) == true) {
        return 3;
      }
      else if (input_string.equals(VarArr[4]) == true) {
        return 4;
      }
      else if (input_string.equals(VarArr[5]) == true) {
        return 5;
      }
      else if (input_string.equals(VarArr[6]) == true) {
        return 6;
      }
      else if (input_string.equals(VarArr[7]) == true) {
        return 7;
      }
      else if (input_string.equals(VarArr[8]) == true) {
        return 8;
      }
      else if (input_string.equals(VarArr[9]) == true) {
        return 9;
      }
      else if (input_string.equals(VarArr[10]) == true) {
        return 10;
      }
      else if (input_string.equals(VarArr[11]) == true) {
        return 11;
      }
      else if (input_string.equals(VarArr[12]) == true) {
        return 12;
      }
      else if (input_string.equals(VarArr[13]) == true) {
        return 13;
      }
      else if (input_string.equals(VarArr[14]) == true) {
        return 14;
      }
      else if (input_string.equals(VarArr[15]) == true) {
        return 15;
      }
      else if (input_string.equals(VarArr[16]) == true) {
        return 16;
      }
      else if (input_string.equals(VarArr[17]) == true) {
        return 17;
      }
      else if (input_string.equals(VarArr[18]) == true) {
        return 18;
      }
      else if (input_string.equals(VarArr[19]) == true) {
        return 19;
      }
      else if (input_string.equals(VarArr[20]) == true) {
        return 20;
      }
      else if (input_string.equals(VarArr[21]) == true) {
        return 21;
      }
      else if (input_string.equals(VarArr[22]) == true) {
        return 22;
      }
      else if (input_string.equals(VarArr[23]) == true) {
        return 23;
      }
      else if (input_string.equals(VarArr[24]) == true) {
        return 24;
      }
      else if (input_string.equals(VarArr[25]) == true) {
        return 25;
      }
      else if (input_string.equals(VarArr[26]) == true) {
        return 26;
      }
      else return 27;
    }
    long _iter;
    void colorProg(float *color,
                   uint8_t *Value,
                   uint16_t *x,
                   byte LED_PROG,
                   float LED_SPEED,
                   byte LED_BRIGHT,
                   uint32_t timer,
                   CRGB *leds,
                   uint8_t LED_COUNT) {
      float prog[3];
      float Bright_Conv;
      float Bright_Conv1;

      if (LED_PROG == 1) {
        prog[0] = 1;
        prog[1] = 0.314;
        prog[2] = 2.71;
      }
      else if (LED_PROG == 2) {
        if (millis() - timer > LED_SPEED) { // put your main code here, to run repeatedly:
          Bright_Conv = float(LED_BRIGHT);
          Bright_Conv1 = myMap(Bright_Conv, 0.0, 127.0, 0.00, 255);
          Value[1] = myMap(Value[0], 255, 0, 0, 255);
          leds[abs(_iter % 8)] = CRGB::Red;
          leds[(abs(1 + _iter) % 8)] = CRGB::Yellow;
          leds[(abs(2 + _iter) % 8)] = CRGB::Green;
          FastLED.show();
          _iter = _iter - LED_SPEED - myMap(Value[0], 0, 127, 7, 0.001);
          timer = millis();
          fadeall(leds, LED_COUNT);
        }
      }
      else if (LED_PROG == 3) {

        if (millis() - timer > LED_SPEED) { // put your main code here, to run repeatedly:
          Bright_Conv = float(LED_BRIGHT);
          Bright_Conv1 = myMap(Bright_Conv, 0.0, 127.0, 0.00, 255);
          Value[1] = myMap(Value[0], 255, 0, 0, 255);
          leds[abs(_iter % 8)] = CRGB::Black;
          leds[(abs(1 + _iter) % 8)] = CRGB::White;
          FastLED.show();
          _iter = _iter - LED_SPEED - myMap(Value[0], 0, 127, 7, 0.001);
          timer = millis();
          fadeall(leds, LED_COUNT);
        }
      }
      else if (LED_PROG == 4) {

        if (millis() - timer > 1) { // put your main code here, to run repeatedly:
          Bright_Conv = float(LED_BRIGHT);
          Bright_Conv1 = myMap(Bright_Conv, 0.0, 127.0, 0.00, 255);
          Value[1] = myMap(Value[0], 255, 0, 0, 255);
          if ((_iter % 127) < -64) {
            for (uint8_t i = 0; i < 8; i++) {
              leds[i] = CHSV(0, 0, 255);
            }
            FastLED.show();
            _iter = _iter - LED_SPEED - myMap(Value[0], 0, 127, 0.001, 16);
            timer = millis();
            fadeall(leds, LED_COUNT);
          }
          else {
            for (uint8_t i = 0; i < 8; i++) {
              leds[i] = CHSV(0, 0, 0);
            }
            FastLED.show();
            _iter = _iter - LED_SPEED - myMap(Value[0], 0, 127, 0.001, 16);
            timer = millis();
            fadeall(leds, LED_COUNT);
          }
        }

      }
      else if (LED_PROG == 5 ) {

        if (millis() - timer > 1) { // put your main code here, to run repeatedly:
          Bright_Conv = float(LED_BRIGHT);
          Bright_Conv1 = myMap(Bright_Conv, 0.0, 127.0, 0.00, 255);
          Value[1] = myMap(Value[0], 255, 0, 0, 255);
          leds[0] = CHSV(0 + (_iter % 256), Value[1], Bright_Conv1);
          leds[1] = CHSV(32 + (_iter % 256), Value[1], Bright_Conv1);
          leds[2] = CHSV(64 + (_iter % 256), Value[1], Bright_Conv1);
          leds[3] = CHSV(96 + (_iter % 256), Value[1], Bright_Conv1);
          leds[4] = CHSV(128 + (_iter % 256), Value[1], Bright_Conv1);
          leds[5] = CHSV(192 + (_iter % 256), Value[1], Bright_Conv1);
          leds[6] = CHSV(224 + (_iter % 256), Value[1], Bright_Conv1);
          leds[7] = CHSV(256 + (_iter % 256), Value[1], Bright_Conv1);
          FastLED.show();
          _iter = _iter - LED_SPEED - myMap(Value[0], 0, 127, 0.001, 16);
          timer = millis();
          fadeall(leds, LED_COUNT);
        }
      }
      else if (LED_PROG == 6 ) {
        if (millis() - timer > LED_SPEED) { // put your main code here, to run repeatedly:
          Bright_Conv = float(LED_BRIGHT);
          Bright_Conv1 = myMap(Bright_Conv, 0.0, 127.0, 0.00, 255);
          Value[1] = myMap(Value[0], 255, 0, 0, 255);
          leds[abs(_iter % 8)] = CRGB::Blue;
          Serial.println(abs(_iter % 8));
          leds[(abs(1 + _iter) % 8)] = CRGB::Green;
          FastLED.show();
          _iter = _iter - LED_SPEED - map(Value[0], 0, 127, 7, 0.001);
          timer = millis();
          fadeall(leds, LED_COUNT);
        }

      }
      else if (LED_PROG == 7 ) {
        if (millis() - timer > LED_SPEED) { // put your main code here, to run repeatedly:
          Bright_Conv = float(LED_BRIGHT);
          Bright_Conv1 = myMap(Bright_Conv, 0.0, 127.0, 0.00, 255);
          Value[1] = myMap(Value[0], 255, 0, 0, 255);
          leds[abs(_iter % 8)] = CRGB::Yellow;
          leds[(abs(1 + _iter) % 8)] = CRGB::Red;
          leds[(abs(2 + _iter) % 8)] = CRGB::Black;
          FastLED.show();
          _iter = _iter - LED_SPEED - myMap(Value[0], 0, 127, 7, 0.001);
          timer = millis();
          fadeall(leds, LED_COUNT);
        }
      }
      else if (LED_PROG == 8 ) {
        prog[0] = 1.0;
        prog[1] = 1.5;
        prog[2] = 1.75;
      }

      if ((LED_PROG < 2) || (LED_PROG > 7)) {
        if (millis() - timer > 10 ) { // put your main code here, to run repeatedly:
          Bright_Conv = float(LED_BRIGHT);
          Bright_Conv1 = myMap(Bright_Conv, 0.0, 127.0, 0.00, 255);
          Value[1] = myMap(Value[0], 255, 0, 0, 255);


          color[0] = (sin(sqrt(x[0] * prog[0] * LED_SPEED * 0.1))) + 1;
          color[1] = (sin(sqrt(x[0] * prog[1] * LED_SPEED * 0.1))) + 1;
          color[2] = (sin(sqrt(x[0] * prog[2] * LED_SPEED * 0.1))) + 1;
          x[1] = color[0] * 127;
          x[2] = color[1] * 127;
          x[3] = color[2] * 127;
          leds[0] = CHSV(x[1], Value[1], Bright_Conv1);
          leds[1] = CHSV(x[2], Value[1], Bright_Conv1);
          leds[2] = CHSV(x[3], Value[1], Bright_Conv1);
          leds[3] = CHSV(x[1] + 15, Value[1], Bright_Conv1);
          leds[4] = CHSV(x[2] + 10, Value[1], Bright_Conv1);
          leds[5] = CHSV(x[3] + 15, Value[1], Bright_Conv1);
          leds[6] = CHSV(x[1] + 30, Value[1], Bright_Conv1);
          leds[7] = CHSV(x[2] + 35, Value[1], Bright_Conv1);
          FastLED.show();
          x[0]++;
          timer = millis();
          fadeall(leds, LED_COUNT);
        }
      }
    }

    void eeWrite(Variables &mVar) {
      EEPROM.put(128, mVar);
    }

    void eeRead(Variables &mVar) {
      EEPROM.get(128, mVar);
    }

    uint16_t Slider() {
      uint8_t ser_av; char serial_read; String readed_String;
      while (true)  {
        ser_av = Serial.available();
        if (ser_av > 0) {
          for (uint8_t i = 0; i < ser_av; i++ ) {
            serial_read = Serial.read();
            readed_String += serial_read;
          }
          break;
        }
      }
      return readed_String.toInt();
    }
    void _Send_Dump_(String *dataArray, Variables &MyVar) {

      dataArray[0]  = String(MyVar.CTRL_0);// = 21;
      dataArray[1]  = String(MyVar.CTRL_1);// = 20;
      dataArray[2]  = String(MyVar.CTRL_2);// = 24;
      dataArray[3]  = String(MyVar.CTRL_3);// = 25;
      dataArray[4]  = String(MyVar.CTRL_4);// = 23;
      dataArray[5]  = String(MyVar.CTRL_5);// = 26;
      dataArray[6]  = String(MyVar.CTRL_6);// = 27;
      dataArray[7]  = String(MyVar.SS_BUT_L);
      dataArray[8]  = String(MyVar.SS_BUT_R);
      dataArray[9]  = String(MyVar.POT_BUT);
      dataArray[10] = String(MyVar.MIDI_CHANNEL);
      dataArray[11] = String(MyVar.LATENCY);
      dataArray[12] = String(MyVar.DUR_MIN);
      dataArray[13] = String(MyVar.DUR_MAX);
      dataArray[14] = String(MyVar.SMOOTHING);
      dataArray[15] = String(MyVar.LED_PROG);
      dataArray[16] = String(uint8_t(MyVar.LED_SPEED));
      dataArray[17] = String(MyVar.LED_BRIGHT);
      for (uint8_t i = 0; i < 18; i++) {
        Serial.println(dataArray[i]);
        delay(10);
      }
      Serial.flush();
    }



  private:
    float myMap(long x, long in_min, long in_max, float out_min, float out_max)
    {
      return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

    void fadeall(CRGB * leds, uint8_t LED_COUNT) {
      for (int i = 0; i < LED_COUNT; i++) {
        leds[i].nscale8(250);
      }
    }



};
