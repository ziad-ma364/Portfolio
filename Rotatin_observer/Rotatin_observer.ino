#define Danger 29 
#define S_input 3 
#define mode_1  7 
#define mode_2  24 
#define mode_3  25 

unsigned long previousMillis = 0;

long interval = 5000; 
int i = 1;

void setup() 
{
 pinMode(Danger , OUTPUT);
 pinMode(S_input , INPUT_PULLUP);
 pinMode(mode_1 , INPUT_PULLUP);
 pinMode(mode_2 , INPUT_PULLUP);
 pinMode(mode_3 , INPUT_PULLUP);
 digitalWrite(Danger,HIGH);
 
}

void loop() 
{
   
   unsigned long currentMillis = millis();
   mode();
   
   if( digitalRead(S_input)== HIGH)
   {
    if (i==0)  previousMillis = currentMillis ;
    
    i = 1 ;
    
    if (currentMillis - previousMillis >= interval)
    {
      digitalWrite(Danger,LOW); 
           
    }else digitalWrite(Danger,HIGH);
   }


    if( digitalRead(S_input)== LOW)
    {
        if (i==1)  previousMillis = currentMillis ;
        
        i = 0 ;
        
        if (currentMillis - previousMillis >= interval)
        {
          digitalWrite(Danger,LOW);
        
        }else digitalWrite(Danger,HIGH);
    }
  
  
}


void mode()
{
  if(digitalRead(mode_1)== HIGH & digitalRead(mode_2)== LOW & digitalRead(mode_3)== LOW){
    interval = 1000 ; 
  }
    if(digitalRead(mode_2)== HIGH & digitalRead(mode_3)== LOW){
    interval = 2000 ; 
  }
      if(digitalRead(mode_3)== HIGH){
    interval = 3000 ; 
  }
}
