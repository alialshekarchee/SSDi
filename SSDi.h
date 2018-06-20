#ifndef SSDi_H
#define SSDi_H
 
#include <Arduino.h>
 
class SSDi {

private:
        bool SegmentsPolarity;
        bool ShiftersPolarity;
        bool LeadingZeros = false;
        int Pin;
        int Level = 10;
        int SegmentsNumber = 7;
        int ShiftersNumber;
        int numDigits(unsigned long long Data);
        int StrngLength;
        int * Segments;
        int * Shifters;
        char * Strng;
        void on(int);
        void off(int);
        void mapper(bool,char);
        void shifter(bool, int);

public:
        SSDi (int *Segments, bool SegmentsPolarity, int *Shifters, int ShiftersNumber, bool ShiftersPolarity);
        ~SSDi ();
        void dotEnable(int Pin);
        void setBrightness (int Level);
        void setIntLeadingZeros (bool Status);
        void show (char Data, int Digit);
        void showChars (char *Chars, int CharsLength, int index = 0);
        void showDot (int Digit);
        void showString (String Data, int StringLength);
        void showInt (unsigned long long Data);
               
};
 
#endif