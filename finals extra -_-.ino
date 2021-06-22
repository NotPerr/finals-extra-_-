#define NOTE_C3  131
#define NOTE_D3  147
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262


//以led亮表示彈奏的音及順序
//若按下滑動式開關，則以led暗來表示彈奏的音及順序
//再次按下滑動式開關，回復以led亮表示彈奏的音及順序

//設定各接腳
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

int button[8]={0,1,2,3,4,5,6,7};

int previousState[8]={1};
int presentState[8]={1};

int k=-1;

byte colDataMatrix[8] = {
   B11111110,
   B11111101,
   B11111011,
   B11110111,
   B11101111,
   B11011111,
   B10111111,
   B01111111
}; //掃描

byte C3[8] = {
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001
};// C3


byte rC3[8] = {
  B11111110,
  B11111110,
  B11111110,
  B11111110,
  B11111110,
  B11111110,
  B11111110,
  B11111110
};// rC3


byte D3[8] = {
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010
};// D3

byte rD3[8] = {
  B11111101,
  B11111101,
  B11111101,
  B11111101,
  B11111101,
  B11111101,
  B11111101,
  B11111101
};// rD3

byte E3[8] = {
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100
};// E3

byte rE3[8] = {
  B11111011,
  B11111011,
  B11111011,
  B11111011,
  B11111011,
  B11111011,
  B11111011,
  B11111011
};// rE3


byte F3[8] = {
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000
};// F3

byte rF3[8] = {
  B11110111,
  B11110111,
  B11110111,
  B11110111,
  B11110111,
  B11110111,
  B11110111,
  B11110111
};// rF3


byte G3[8] = {
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000
};// G3

byte rG3[8] = {
  B11101111,
  B11101111,
  B11101111,
  B11101111,
  B11101111,
  B11101111,
  B11101111,
  B11101111
};// rG3


byte aA3[8] = {
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000
};// A3

byte raA3[8] = {
  B11011111,
  B11011111,
  B11011111,
  B11011111,
  B11011111,
  B11011111,
  B11011111,
  B11011111
};// rA3


byte B3[8] = {
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000
};// B3

byte rB3[8] = {
  B10111111,
  B10111111,
  B10111111,
  B10111111,
  B10111111,
  B10111111,
  B10111111,
  B10111111
};// rB3


byte C4[8] = {
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000
};// C4

byte rC4[8] = {
  B01111111,
  B01111111,
  B01111111,
  B01111111,
  B01111111,
  B01111111,
  B01111111,
  B01111111
};// rC4

int cState = 0;

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(0,INPUT_PULLUP);
  pinMode(1,INPUT_PULLUP);
  pinMode(13,INPUT_PULLUP);
  
} 



  
void loop() {


 for(int i=0;i<8;i++)
 {
   presentState[i]=digitalRead(button[i]);
 }
 cState =digitalRead(13);
  
  //C3 
 if(presentState[0]==0)
 {
   k++;
   tone(9,NOTE_C3,500);
   digitalWrite(latchPin,LOW);
   
   if(cState==HIGH)
   {
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,C3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   else
   {
     shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,rC3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
  
   
   if(k==7)
   {
     k=-1;
   }
   previousState[0]=0;
 }
  //D3
 else if(presentState[1]==0)
 {
   k++;
   tone(9,NOTE_D3,500);
   digitalWrite(latchPin,LOW);
   
   if(cState==HIGH)
   {
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,D3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   else
   {
     shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,rD3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
  
   if(k==7)
   {
     k=-1;
   }
   previousState[1]=0;
 }
 //E3
  
 else if(presentState[2]==0)
 {
    k++;
   tone(9,NOTE_E3,500);
   digitalWrite(latchPin,LOW);
   if(cState==HIGH)
   {
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,E3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   else
   {
     shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,rE3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   if(k==7)
   {
     k=-1;
   }
   previousState[2]=0;
 }
  
 //F3
 
 else if(presentState[3]==0)
 {
   k++;
   tone(9,NOTE_F3,500);
   digitalWrite(latchPin,LOW);
   if(cState==HIGH)
   {
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,F3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   else
   {
     shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,rF3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   if(k==7)
   {
     k=-1;
   }
   previousState[3]=0;
 }
    
 //G3
 else if(presentState[4]==0)
 {
    k++;
   tone(9,NOTE_G3,500);
   digitalWrite(latchPin,LOW);
   if(cState==HIGH)
   {
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,G3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   else
   {
     shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,rG3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   if(k==7)
   {
     k=-1;
   }
   previousState[4]=0;
 }
    
 //A3
 else if(presentState[5]==0)
 {
   k++;
   tone(9,NOTE_A3,500);
   digitalWrite(latchPin,LOW);
    if(cState==HIGH)
   {
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,aA3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   else
   {
     shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,raA3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   if(k==7)
   {
     k=-1;
   }
   previousState[5]=0;
 }
   
 //B3
  else if(presentState[6]==0)
 {
   k++;
   tone(9,NOTE_B3,500);
   digitalWrite(latchPin,LOW);
    if(cState==HIGH)
   {
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,B3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   else
   {
     shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,rB3[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   if(k==7)
   {
     k=-1;
   }
   previousState[6]=0;
 } 
 
   
 //C4
  else if(presentState[7]==0)
 {
   k++;
   tone(9,NOTE_C4,500);
   digitalWrite(latchPin,LOW);
    if(cState==HIGH)
   {
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,C4[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   else
   {
     shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[k]);
    shiftOut(dataPin, clockPin, MSBFIRST,rC4[k] );
    digitalWrite(latchPin,HIGH );
    delay(1000);
   }
   if(k==7)
   {
     k=-1;
   }
   previousState[7]=0;
 } 
  
  for(int i=0;i<8;i++){
    if(presentState[i]==1&&previousState[i]==0){
      noTone(9);
      previousState[i]=1;
    } 
   }  


}


