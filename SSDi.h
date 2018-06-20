/*
    SSDi.h - Library for driving 7-Segments display.
    Created by Ali A. Alshekarchee, June 18, 2018.
    Released into the public domain.
    This file is part of SSDi library.
    ////////////////////////////////////////////////////////////////////
    SSDi library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    SSDi library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
*/

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
