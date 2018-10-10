// Program to measure consumed current by a load with non-invasive sensor SCT013-30A 


//Include a constants for the Pin where the Sensor is connected to. 
///------------- WRITE HERE THE CODE-----------------//

const int Sense0 = A0; /// Added as measurment input ref 0
const int RefPin = A2; /// +2,5 measurement 
const int Rshunt = 33;

unsigned long time_ant = 0, difTime = 0, act_time = 0;
const int sampleDuration = 20;
int count_integral = 0;
double rawSquaredSum = 0;
double Irms = 0;
double Iant = 0;
double ADC_sensor;
double ADC_ref;
double V_sens;
double V_ref;
double V_grid = 230;

/// Write the void setup code command. Inside it, Set the data rate in bits per second for serial data transmission, so as to communicate with the computer. Use of the availables reates.
///------------- WRITE HERE THE CODE-----------------//
void setup( ){
Serial.begin(115000);
///Serial.println("Hello world!");
}
void loop()
{
  act_time = micros();
  difTime = act_time - time_ant;

  int RawValue = 0;

  if (difTime >= 1000) {
    time_ant = act_time + (difTime - 1000);
  

    // Read the ADC input from the sensor and the voltage reference point
    ///------------- WRITE HERE THE CODE-----------------//
    ADC_sensor = analogRead(Sense0);
    ADC_ref = analogRead(RefPin);

    
    // Translate the ADC input measured to voltage values
    ///------------- WRITE HERE THE CODE-----------------//
    V_sens = ADC_sensor/1023*5;
    V_ref = ADC_ref/1023*5;

    // Calculate the instantaneous current using the voltage diference and the burder resistor value
    double Iinst = 1000 * (V_sens - V_ref) / Rshunt;

    //Serial.print("Iinst = ");
    Serial.println(Iinst);

    // Calculating Power
    Pinst = Iinst*V_grid;
    

    rawSquaredSum += Iinst * Iinst * 0.001;
    count_integral++;
  }

  if (count_integral >= sampleDuration) {
    Irms = sqrt(50 * rawSquaredSum);

    count_integral = 0;
    rawSquaredSum = 0;

    // Low-pass filter
    double Ifilt = 0.95 * Iant + 0.05 * Irms;
    Iant = Ifilt;

  }
  // could write for power or for price. 
  if (Pinst >= Pmax) {
    digitalWrite.BUTTON(HIGH)
  }
  else { 
    digitalWrite.BUTTON(LOW)
  }

  /// import market price
  /// import time
  /// calculate cheapest time

}
