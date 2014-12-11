#include <VirtualWire.h>
#include <VirtualWire_Config.h>


void setup()
{
  Serial.begin(9600);
  
  // Initialize the IO and ISR
  vw_set_ptt_inverted(true);
  vw_setup(2000); // Bits per sec
}
void loop()
{
  const char *msg = "hello";
  
  digitalWrite(13, true); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Wait until the whole message is gone
  Serial.println("Escribe");
  digitalWrite(13, false); 
  delay(3000);
}
void send (char *msg)
{
  
}
