#include <HX711.h>


#define DT  4
#define SCK  3

// hx intialise
HX711 scale(DT, SCK);
float calibration_factor = +435700;
//



void setup() {
  Serial.begin(9600);
  scale.set_scale();
  long zero_factor = scale.read_average();
}




void loop() {

  scale.set_scale(calibration_factor); //Adjust to this calibration factor
 
  Serial.print(scale.get_units(), 3);
  Serial.print(" kg"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  
  Serial.println();
  delay(100);

  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
    else if(temp == 's')
      calibration_factor += 100;  
    else if(temp == 'x')
      calibration_factor -= 100;  
    else if(temp == 'd')
      calibration_factor += 1000;  
    else if(temp == 'c')
      calibration_factor -= 1000;
    else if(temp == 'f')
      calibration_factor += 10000;  
    else if(temp == 'v')
      calibration_factor -= 10000;  
    else if(temp == 't')
      scale.tare();  //Reset the scale to zero
  }
}
