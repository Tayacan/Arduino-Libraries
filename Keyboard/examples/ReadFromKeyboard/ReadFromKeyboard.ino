#include <Keyboard.h>

// The numbers are pins. Modify depending on your setup.
Keyboard k(10,9,8,2,3,4,5);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  // Get a keycode from the keyboard
  int inp = k.Read();
  // 0 means no input
  if(inp != 0)
  {
    Serial.println(inp);
  }
}
