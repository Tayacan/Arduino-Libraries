/*
	Keyboard.h - Translate keyboard input to sensible signals
	Created by Maya Saietz
*/

#ifndef Keyboard_h
#define Keyboard_h
#include "Arduino.h"

class Keyboard
{
	public:
		// The ints in the constructor are pin numbers
		Keyboard(int in1,int in2, int in3, 
			int out1, int out2, int out3, int out4);
		int Read(); // Return a keycode
	private:
		void InitPins(); // Helper function
		// Arrays to hold pin numbers
		int _in[3];
		int _out[4];
};

#endif