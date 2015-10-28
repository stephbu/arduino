
void setup() 
{
  Serial.begin();
  Bean.enableWakeOnConnect( true ); 
}

char incoming;
bool lastConnectionStatus = false;

void loop() 
{
  Bean.sleep(50);
  bool connectionStatus = Bean.getConnectionState();

  // put your main code here, to run repeatedly:
  if(connectionStatus != lastConnectionStatus)
  {
    if(connectionStatus)
    {
      Bean.setLed(0,255,0);
    }
    else
    {
      Bean.setLed(255,0,0);
    }
    
    Bean.sleep(50);
    Bean.setLed(0,0,0);
    lastConnectionStatus = connectionStatus;
    Bean.sleep(250);
  }
  
  if(!connectionStatus)
  {
    return;
  }

  if(Serial.available() <= 0)
  {
    return; 
  }
  else
  {
    incoming = Serial.read();
    Serial.print(incoming);
  }
}
