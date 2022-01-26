  /***********************************************
   * App variables
   ***********************************************/
  const boolean VERBOSE = true;
  
  /***********************************************
   * Motor variables
   ***********************************************/
  const int MOTOR_PIN  = 1;   // pin of the motor
  const int MOTOR_OFF  = 0;   // vibration speed when off
  const int MOTOR_ON   = 125; // intensity of vibration
  const int MOTOR_TIME = 1000; // time to vibrate
  
  /***********************************************
   * Piezo sensor variables
   ***********************************************/ 
  const int TRIGGER_THRESH = 950;
  
  void setup() {
    // put your setup code here, to run once:
    if( VERBOSE ) Serial.begin(9600); 
  }
  
  void loop() 
  {
    int piezoSensor = analogRead(2);
    
    if( VERBOSE ) Serial.println(piezoSensor);
  
    if( piezoSensor > TRIGGER_THRESH){
      analogWrite( MOTOR_PIN, MOTOR_ON );
      delay( MOTOR_TIME );
    }else  {
      analogWrite( MOTOR_PIN, MOTOR_OFF );    
    }
    
    delay(10);
  }
