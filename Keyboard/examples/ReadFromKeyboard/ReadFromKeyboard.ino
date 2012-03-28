#include <Keyboard.h>

Keyboard k(10,9,8,2,3,4,5);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int inp = k.Read();
  if(inp != 0)
  {
    Serial.println(inp);
  }
}
