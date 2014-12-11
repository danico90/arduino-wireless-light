#include <VirtualWire.h>
#include <VirtualWire_Config.h>

//
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message
int outPin = 1;
int inPin = 0;

char code[100] = "123"; //
boolean correct = false;

void setup()
{
  pinMode(outPin, OUTPUT);
  
  // Initialise the IO and ISR
  vw_set_rx_pin(inPin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);	 // Bits per sec

  vw_rx_start();       // Start the receiver PLL running
}
void loop()
{
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;


  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    
    int i;
    for (i = 0; i < buflen; i++)
    {
      if (buf[i] == code[i]) {
        digitalWrite(outPin, true);
      }
      else {
        digitalWrite(outPin, false);
      }
    }
    //delay(1);
    
    
  }
  
}


