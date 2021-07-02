int IRinput = 4;
float t = 0.;
float Tdiff=0.;
float rpm;
int interruptPin=2;


void setup() {
  // put your setup code here, to run once:
 pinMode(13,OUTPUT);
  pinMode(IRinput,INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(IRinput)==HIGH)
   {digitalWrite(13,HIGH);
  
   }
   else 
   {
    digitalWrite(13,LOW);
   }

   float Reading1 = digitalRead(13);
  
   Serial.println(Reading1);
}


void blink(){ 
   boolean PrevState = LOW;
   boolean NState = digitalRead(IRinput);
   if (NState!=PrevState){
    Tdiff = micros()- t;
    rpm =60000/(Tdiff*2);
    t= micros();
    PrevState = NState;
    
    Serial.println(rpm);
    return;
   }
}
