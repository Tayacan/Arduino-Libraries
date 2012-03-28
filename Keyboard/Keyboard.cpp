#include "Arduino.h"
#include "Keyboard.h"

Keyboard::Keyboard(int in1,int in2, int in3, 
	int out1, int out2, int out3, int out4)
{
	// Set input pin numbers
	_in[0] = in1;
	_in[1] = in2;
	_in[2] = in3;
	
	// Set output pin numbers
	_out[0] = out1;
	_out[1] = out2;
	_out[2] = out3;
	_out[3] = out4;
	
	// Initialize pins
	InitPins();
}

void Keyboard::InitPins()
{
	/*
		The pinmodes seem to be
		opposite, because input
		to the keyboard is output
		from the arduino.
	*/
	// Set pinmodes
	int i;
	for(i = 0; i < 3; i++)
	{
		pinMode(_in[i], OUTPUT);
		
		// Make sure there's no output:
		digitalWrite(_in[i],LOW);
	}
	
	for(i = 0; i < 4; i++)
	{
		pinMode(_out[i], INPUT);
	}
}

int Keyboard::Read()
{
	int i, j, output;
	output = 0; // Ensure that we don't get garbage
	for(i = 0; i < 3; i++)
	{
		// Start reading on column i
		digitalWrite(_in[i],HIGH);
		for(j = 0; j < 4; j++)
		{
			// Read column i, row j
			if(digitalRead(_out[j]))
			{
				/*
					Fancy math - output can be:
					11, 12, 13, 21, 22, 23,
					31, 32, 33, 41, 42, 43.
					10's are the row, 1's are
					the column.
				*/
				output = (i+1)+(j+1)*10;
			}
		}
		// Stop reading on column i
		digitalWrite(_in[i],LOW);
	}
	return output;
}