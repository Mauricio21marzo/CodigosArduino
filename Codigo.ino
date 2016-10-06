#define WATERPIN 2
#define READSOILPIN A0

//número más alto es más seca 
#define MAXDRYNESS 700

#define WATERDELAY 750
#define WATERPOSTDELAY 5000

void setup()
{
  Serial.begin(9600);
  pinMode(READSOILPIN, INPUT);
  pinMode(WATERPIN, OUTPUT);
}

void loop()
{
  int SensorValue = analogRead(READSOILPIN);  //tomar una muestra
  Serial.print(SensorValue); Serial.print(" - ");
  
  if(SensorValue >= MAXDRYNESS) 
  {
   
//si el suelo está demasiado seco de inicio de riego por 3/4 y luego una segunda
//esperar 5 segundos antes de monitorizar de nuevo
   Serial.println("Riego del suelo arranque en seco");
   digitalWrite(WATERPIN, HIGH);
   delay(WATERDELAY);
   digitalWrite(WATERPIN, LOW);
   delay(WATERPOSTDELAY);
  }
  
  delay(50);
}
