# SSDi
An Arduino library for the 7-Segments LED display, Lightweight, easy to use and has many features.

Features:
	*Support up to 12 digits.
	*Support for the (Decimal Dot) as individual variable for flexibility and full control.
	*Support for ten levels of brightness (MAX level as default).
	*Support for common-cathode, common-anod with and without transistors, In other words you can output segments as LOW,High 	   and common lines (shifters) as LOW,HIGH independently.
	*Leading Zeroz set/unset function is supported.
	*Direct display of characters and numbers on a specific digit.
	*Support for Charechters array.
	*Support for Strings.
	*Support for Numbers as an Unsigned Long Long up to 999999999999 (12 digits).

Implementation:
	After importing the library to your project folder and including the SSDi.h into your code you need to instantiate an 		object of the class SSDi like so:
	
	
	#include <SSDi.h>
	SSDi ssdi(Segments, SegmentsPolarity, Shifters, ShiftersNumber, ShiftersPolarity);
	
	
	Five parameters needed to make this object:
	*An array holding the pins numbers which the display's segments are attached to.
	*The polarity of the segments Active-high (true) or active-low (false).
	*An array holding the pins numbers which the display's common lines (Shifters) are attached to.
	*The number of the digits you want to run.
	*The polarity of the common lines (Shifters) Active-high (true) or active-low (false).
	
	Then you can call the settings functions inside the Setup() function of the Arduino sketch. (Optional)
	
	ssdi.dotEnable(Pin)							Pin: Is the pin which the decimal dot attached to.
    ssdi.setIntLeadingZeros(Status)				Status: It can be True or False, Default is False.
    ssdi.setBrightness(Level)					Level: It can be in the range (0-10) Defalut is 10 which is the Max 															   brightness.
	
	Now, You can call any function you like to show your data on the 7-Segments display as below:
	
	show (char Data, int Digit)
	It displays a single character (or number) on a specific digit.
	
    showChars (char Chars, int CharsLength, int index)
	It displays an array of characters, It needs the number of array elements and optionally the starting digit. (Default is 	 the digit 0)
	
    showDot (int Digit)
	It displays the decimal dot on a specific digit.
	
    showString (String Data, int StringLength)
	it displays a String, You need to provide the number of characters that the String has.
	
    showInt (unsigned long long Data)
	It displays an integer on all the available digits.
	
	For more information, please check the examples folder.
