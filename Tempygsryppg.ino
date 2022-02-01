int sensorPin=5;
int tempPin=2;
float temp;
float ADC_out;
float vout;
float rtemp;
float ngl; 
int PulseSensorPurplePin =0; //--> Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0.
int Signal1; //--> holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550; //--> Determine which Signal to "count as a beat", and which to ingore.
//----------------------------------------

//--------------------------------------------------------------------------------void setup
void setup() {
  Serial.begin(9600); //--> Set's up Serial Communication at certain speed.
}
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------void loop
void loop() {

ADC_out=analogRead(sensorPin);
temp= analogRead(tempPin);
Signal1 = analogRead(PulseSensorPurplePin); //--> Read the PulseSensor's value. Assign this value to the "Signal" variable.
//rtemp= temp*0.488;



int numReadsppg = 10;  //number of samples
int senseppgSum = 0; //sum of snesor readings
for(int i = 0; i < numReadsppg; i++){
  senseppgSum +=analogRead(PulseSensorPurplePin);
  delay(1);
  }

int senseppgAve =senseppgSum/numReadsppg; 
int Signal= senseppgAve;

int numReadsvout = 10;  //number of samples
int senseSum = 0; //sum of snesor readings
for(int k = 0; k < numReadsvout; k++){
  senseSum +=analogRead(sensorPin);
  delay(1);
  }

int senseAve =senseSum/numReadsvout; 
vout= senseAve*0.004;

int numReadstemp = 10;  //number of samples
int sensetempSum = 0; //sum of snesor readings
for(int j = 0; j < numReadsvout; j++){
  senseSum +=analogRead(PulseSensorPurplePin);
  delay(1);
  }
int sensetempAve =sensetempSum/numReadstemp; 
rtemp= senseppgAve*0.0488;


ngl= vout*(-2.33)+ 10.83;

Serial.print(Signal); //--> Send the Signal value to Serial Plotter.
Serial.print(" , ");
//delay(1000); 

Serial.print(vout);
Serial.print(" , ");
//delay(1000);

Serial.print(rtemp);
Serial.print(" , ");
//delay(1000);

Serial.print(ngl);
Serial.println(" , ");
delay(1000);

}
