// Include here the PID Library that you have downloaded previously. 
// ------------- WRITE HERE THE CODE--------------------------------- //
#include <PID_v1.h>
// Variables needed for the function called NewConfigParameter()
String cadena;
double number;

// Define the Variables we'll be connecting to, which we will use so as to know the behaviour of our plant (setpoint, input,output)
// ------------- WRITE HERE THE CODE--------------------------------- //
double Setpoint;
double Output;
double Input;
double readinput;
const int input_pin = A1;
const int output_pin = 9;

// Temporary Variables
unsigned long Time = 0, Time_ant = 0;
unsigned long num_aux = 0;

// Configuration of the PID Variables that we will change so as to control the plant. 
// ------------- WRITE HERE THE CODE--------------------------------- //
double Kp = 2;
double Ki = 4;
double Kd = 0.1; 
// Configuration of the PID Controller using the PID Library
// ------------- WRITE HERE THE CODE--------------------------------- //
PID pid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

// To set up a new SetPoint, we just have to write one value. We will do that using the function NewConfigParameter()
void NewConfigParameter()
{
  if (Serial.available() > 0)
  {
    // Write the lecture in one string
    cadena = Serial.readString();
    // We will change this number into a float, with the variable named number
    number = cadena.toFloat();
    Setpoint = number;
  }
}

// The setup routine runs once when you press reset:

void setup() 
{
  // Initialize serial communication at 57600 bits per second. Normally, this baudrate is 9600. 
  // However, we have to increase the speed to then be able to print the information every 10ms. 
  // We have to change also the baudrate in the serial Monitor
  
  Serial.begin(57600);

  // Turn the PID on
  // ------------- WRITE HERE THE CODE--------------------------------- //
  pid.SetMode(AUTOMATIC);
  // Indicate that we the PID has been activated 
  Serial.println("Active PID");
}

// The loop routine runs over and over again forever:
void loop() 
{
    // Read the current time in milliseconds
    Time = millis();
     
    // Read the input of the channel 0, where we have the LDR connected
    // ------------- WRITE HERE THE CODE--------------------------------- //
    readinput = analogRead(input_pin);
    Input = readinput/(1023/255);                   
    // Read the Setpoint value using the serial port
    NewConfigParameter();
  
  
    // Execute the PID controller
    // ------------- WRITE HERE THE CODE--------------------------------- //
    pid.Compute();
    // We want to Write an analog value so as to turn on or off the LED, depending on the PID Output 
    // ------------- WRITE HERE THE CODE--------------------------------- //
    analogWrite(output_pin,Output);
 
    // Run the program at 10 ms.   
    //==================================================================================================
    if (Time - Time_ant >=  10)
    { 
        // Auxiliar flag used to print out every 10 ms
        num_aux = 1;
        // Update the variable named Time_ant so as to be able to run the program again after 10 ms. 
        Time_ant = Time;
    }
    //==================================================================================================
  
    // Print out the data if we have tuned the PID or not. 
    //==================================================================================================
    if (num_aux == 1) {
        // Print out Time in ms.
        Serial.print(Time);
        Serial.print("; ");
        // Print out setpoint
        Serial.print(Setpoint);
        Serial.print("; ");
        // Print out the plant output without maping it
        Serial.print(Input);
        Serial.print("; ");
        // Print out PID output, plant input. 
        Serial.print(Output);
        Serial.println("; ");
        // Restart the flag. 
        num_aux = 0;
    }
    //==================================================================================================
}  
