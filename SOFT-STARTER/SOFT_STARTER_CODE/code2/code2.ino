#include <TimerOne.h>
int counter=0;
#define SCR_PIN 3
#define max_counter 1000
#define zerocross 2
#define push 6
#define ledgreen 5
#define ledred 4


boolean zero_detect=false;
int value = 0 ;
int R_value = 1000 ;
float current_time = 0;


void phase_shift_counter()
{
  if(zero_detect&&counter>=R_value)
  {
    digitalWrite(SCR_PIN,HIGH);
    zero_detect=false;
    //digitalWrite(ledred, HIGH);
   // digitalWrite(ledgreen, LOW);
  }//else {
   // digitalWrite(ledred, LOW);
   // digitalWrite(ledgreen, HIGH);
  //}
  counter++;
}
void isr()
{
  zero_detect=true;
  counter=0;
  digitalWrite(SCR_PIN,LOW);
}
void setup() 
{
  pinMode(SCR_PIN,OUTPUT);
  pinMode(zerocross, INPUT_PULLUP);
  pinMode(push, INPUT_PULLUP);
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  Timer1.initialize(10);
  Timer1.attachInterrupt(phase_shift_counter);
  attachInterrupt(0,isr,RISING);
}

void loop() 
{
  if (digitalRead(push) == LOW) 
  {
    value = 500;
  } else value = 0;

    if( millis()- current_time == 20 )
    {
        R_value = R_value - 1;
        if(R_value <= value)
        {
          R_value = R_value + 2 ;
        }
        current_time = millis();
    }
   

}
