# Definir  WATERPIN  2
# Definir  READSOILPIN A0

// Número más alto es más seca
# Definir  MAXDRYNESS  700

# Definir  WATERDELAY  750
# Definir  WATERPOSTDELAY  5000

void  setup ()
{
  Serial. Comenzar ( 9600 );
  pinMode (READSOILPIN, INPUT);
  pinMode (WATERPIN, OUTPUT);
}

void  loop ()
{
  int SensorValue = analogRead (READSOILPIN); // tomar una muestra
  . Serie de impresión (SensorValue); . Serie de impresión ( " - " );
  
  si (SensorValue> = MAXDRYNESS)
  {
   // Si el suelo está demasiado seco de inicio de riego por 3/4 y luego una segunda
   // Esperar 5 segundos antes de monitorizar de nuevo
   . De serie println ( " Soil arranque en seco de riego " );
   digitalWrite (WATERPIN, HIGH);
   retardo (WATERDELAY);
   digitalWrite (WATERPIN, LOW);
   retardo (WATERPOSTDELAY);
  }
  
  retraso ( 50 );
}
