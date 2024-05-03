#define axisX A0
#define axisY A1
bool sharp;

const int freqs[14]=
  {440,493,525,588,658,701,786,880,987,1050,1176,1317,1402,1572}; //A,B,C,D,E,F,G,a,b,c,d,e,f,g 

void setup() {
  Serial.begin(57600);
  pinMode(4,OUTPUT);
  Serial.println();
  Serial.println("Welcome to my Arduino 'piano'. To use, simply move the joystick to the reletive sections listed below:");
  Serial.println("-------------------");
  Serial.println("[F/F#] [E/E#] [D/D#]");
  Serial.println("--------------------");
  Serial.println("[G/G#][center][C/C#]");
  Serial.println("--------------------");
  Serial.println("[swap #][A/A#][B/B#]");
  Serial.println("--------------------");
}

void playNote(long noteFreq) {
  long time = ((long)1000000) / (2*noteFreq);
  PORTD = 0b10000;
  delayMicroseconds(time);
  PORTD = 0b00000;
  delayMicroseconds(time);
}

void loop() {
  int x = analogRead(axisX);
  int y = analogRead(axisY);

  if(0 <= x && x <= 341 && 0 <= y && y <= 341) {
    if(sharp == 0) {
      sharp = 1;
    }
    else {
      sharp = 0;
    }
    delay(500);
  }
  else if(0 <= x && x <= 341 && 341 <= y && y <= 682) {
    if(sharp == 0) {
      playNote(freqs[0]); //A
    }
    else {
      playNote(freqs[7]); //A#
    }
  }
  else if(0 <= x && x <= 201 && 682 <= y && y <= 1023) {
    if(sharp == 0) {
      playNote(freqs[1]); //B
    }
    else {
      playNote(freqs[8]); //B#
    }
  }
  else if(341 <= x && x <= 682 && 0 <= y && y <= 201) {
    if(sharp == 0) {
      playNote(freqs[6]); //G
    }
    else {
      playNote(freqs[13]); //G#
    }
  }
  else if(341 <= x && x <= 682 && 341 <= y && y <= 682) {
    //center of the joystick
  }
  else if(341 <= x && x <= 682 && 822 <= y && y <= 1023) {
    if(sharp == 0) {
      playNote(freqs[2]); //C
    }
    else {
      playNote(freqs[9]); //C#
    }
  }
  else if(682 <= x && x <= 1023 && 0 <= y && y <= 341) {
    if(sharp == 0) {
      playNote(freqs[5]); //F
    }
    else {
      playNote(freqs[12]); //F#
    }
  }
  else if(822 <= x && x <= 1023 && 341 <= y && y <= 682) {
    if(sharp == 0) {
      playNote(freqs[4]); //E
    }
    else {
      playNote(freqs[11]); //E#
    }
  }
  else if(682 <= x && x <= 1023 && 682 <= y && y <= 1023) {
    if(sharp == 0) {
      playNote(freqs[3]); //D
    }
    else {
      playNote(freqs[10]); //D#
    }
  }
}
