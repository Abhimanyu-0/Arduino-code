  
float value=0;
float rev=0;
int rpm=0;
int oldtime=0;
int time;
 
void isr() //interrupt service routine
{
rev++;
}
 
void setup()
{
Serial.begin(9600);; 
attachInterrupt(0,isr,RISING); //attaching the interru(pin,OUTPUT);

}
 
void loop()
{
  
delay(1000);
detachInterrupt(0); //detaches the interrupt
time =millis()-oldtime; //finds the time
rpm=(rev/time)*60000/2; //calculates rpm for blades  // 1 rev==> x 
                                                     // y rev==> 60000
oldtime=millis(); //saves the current time
rev=0;
//Serial.clear;

Serial.print( rpm);
Serial.println(" RPM");
attachInterrupt(0,isr,RISING);




 
  
}
