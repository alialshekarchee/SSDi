/*
    SSDi.cpp - Library for driving 7-Segments display.
    Created by Ali A. Alshekarchee, June 18, 2018.
    alielshekarchee@gmail.com
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
    along with SSDi library.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "SSDi.h"

SSDi::SSDi (int *Segments, bool SegmentsPolarity, int *Shifters, int ShiftersNumber, bool ShiftersPolarity)
{
    if (ShiftersNumber > 12)
    {
        ShiftersNumber = 12;
    }
        this->SegmentsPolarity = SegmentsPolarity;
        this->ShiftersPolarity = ShiftersPolarity;
        this->ShiftersNumber = ShiftersNumber;
        
        if (this->Segments) 
        {
            free(this->Segments);
            this->Segments = NULL;
        }
        if (this->Shifters) 
        {
            free(this->Shifters);
            this->Shifters = NULL;
        }
        this->Segments = (int*) calloc(this->SegmentsNumber, sizeof(int));
        memcpy(this->Segments, Segments, this->SegmentsNumber * sizeof(int));
        this->Shifters = (int*) calloc(ShiftersNumber, sizeof(int));
        memcpy(this->Shifters, Shifters, ShiftersNumber * sizeof(int));
        
        for (int i = 0; i < this->SegmentsNumber; i++){
            pinMode(this->Segments[i],OUTPUT);
        }
        for (int i = 0; i < this->ShiftersNumber; i++){
            pinMode(this->Shifters[i],OUTPUT);
        }
}
SSDi::~SSDi ()
{
    if (this->Segments) 
    {
        free(this->Segments);
        this->Segments = NULL;
    }
    if (this->Shifters) 
    {
        free(this->Shifters);
        this->Shifters = NULL;
    }
}



void SSDi::on (int pin)
{
    digitalWrite(pin,HIGH);
}

void SSDi::off (int pin)
{
    digitalWrite(pin,LOW);
}

void SSDi::mapper (bool flag, char data)
{
    switch (data){
        case 0:
        case '0':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                            }
                break;
        case 1:
        case '1':
                switch (flag){
                                case true:
                                            off(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                                case false:
                                            on(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                            }
                break;
        case 2:
        case '2':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            off(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            off(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            on(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            on(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 3:
        case '3':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 4:
        case '4':
                switch (flag){
                                case true:
                                            off(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            on(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 5:
        case '5':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            off(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            off(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            on(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            on(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 6:
        case '6':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            off(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            on(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 7:
        case '7':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                            }
                break;
        case 8:
        case '8':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 9:
        case '9':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            off(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            on(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 'A':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            off(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            on(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 'B':
                switch (flag){
                                case true:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 'C':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                            }
                break;
        case 'D':
                switch (flag){
                                case true:
                                            off(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            off(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            on(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            on(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 'E':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;
        case 'F':
                switch (flag){
                                case true:
                                            on(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                                case false:
                                            off(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                            }
                break;

        case 'L':
                switch (flag){
                                case true:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                                case false:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                            }
                break;

        default:
                switch (flag){
                                case true:
                                            off(this->Segments[0]);
                                            off(this->Segments[1]);
                                            off(this->Segments[2]);
                                            off(this->Segments[3]);
                                            off(this->Segments[4]);
                                            off(this->Segments[5]);
                                            off(this->Segments[6]);
                                            break;
                                case false:
                                            on(this->Segments[0]);
                                            on(this->Segments[1]);
                                            on(this->Segments[2]);
                                            on(this->Segments[3]);
                                            on(this->Segments[4]);
                                            on(this->Segments[5]);
                                            on(this->Segments[6]);
                                            break;
                            }
                break;
                
    }
}

void SSDi::shifter (bool flag, int digit)
{
    if (digit >= this->ShiftersNumber){
        digit = 100;
    }
    switch (digit){
        case 0:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[0]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[0]);
                break;
            }
            break;
        case 1:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[1]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[1]);
                break;
            }
            break;
        case 2:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[2]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[2]);
                break;
            }
            break;
        case 3:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[3]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[3]);
                break;
            }
            break;
        case 4:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[4]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[4]);
                break;
            }
            break;
        case 5:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[5]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[5]);
                break;
            }
            break;
        case 6:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[6]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[6]);
                break;
            }
            break;
        case 7:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[7]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[7]);
                break;
            }
            break;
        case 8:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[8]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[8]);
                break;
            }
            break;
        case 9:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[9]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[9]);
                break;
            }
            break;
        case 10:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[10]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[10]);
                break;
            }
            break;
        case 11:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[11]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[11]);
                break;
            }
            break;
        case 12:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                on(this->Shifters[12]);
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                off(this->Shifters[12]);
                break;
            }
            break;
        case 100:
            switch (flag){
                case true:
                    for (int i = 0; i < this->ShiftersNumber; i++){
                    off(this->Shifters[i]);
                }
                break;
                case false:
                   for (int i = 0; i < this->ShiftersNumber; i++){
                    on(this->Shifters[i]);
                }
                break;
            }
            break;
    }
}

void SSDi::show (char Data, int Digit)
{
    mapper(this->SegmentsPolarity, Data);
    shifter(this->ShiftersPolarity, Digit);
    delayMicroseconds(1000);
    mapper(this->SegmentsPolarity, '&');
    shifter(this->ShiftersPolarity, '&');
    delayMicroseconds(this->Level);
}

void SSDi::showChars (char *Chars, int CharsLength, int index)
{
    for (int i = 0; i < CharsLength && i < ShiftersNumber; i++)
    {
        SSDi::show(Chars[i], index + i);
    }
}

void SSDi::dotEnable (int Pin)
{
    this->Pin = Pin;
    pinMode(this->Pin, OUTPUT);
}

void SSDi::showDot (int Digit)
{
    if (this->SegmentsPolarity)
    {
        for (int i = 0; i < this->SegmentsNumber; i++)
        {
            digitalWrite(this->Segments[i],LOW);
        }
    }
    else
    {
        for (int i = 0; i < this->SegmentsNumber; i++)
        {
            digitalWrite(this->Segments[i],HIGH);
        }
    }
    switch (this->SegmentsPolarity)
    {
        case true: 
            switch (this->ShiftersPolarity)
            {
                case true:
                    digitalWrite(this->Pin,HIGH);
                    digitalWrite(this->Shifters[Digit],HIGH);
                    break;
            
                case false:
                    digitalWrite(this->Pin,HIGH);
                    digitalWrite(this->Shifters[Digit],LOW);
                    break;
            }
            break;
        case false:
            switch (this->ShiftersPolarity)
            {
                case true:
                    digitalWrite(this->Pin,LOW);
                    digitalWrite(this->Shifters[Digit],HIGH);
                    break;
            
                case false:
                    digitalWrite(this->Pin,LOW);
                    digitalWrite(this->Shifters[Digit],LOW);
                    break;
            }
            break;
    }
    delayMicroseconds(1000);
    switch (this->SegmentsPolarity)
    {
        case true: 
            switch (this->ShiftersPolarity)
            {
                case true:
                    digitalWrite(this->Pin,LOW);
                    digitalWrite(this->Shifters[Digit],LOW);
                    break;
            
                case false:
                    digitalWrite(this->Pin,LOW);
                    digitalWrite(this->Shifters[Digit],HIGH);
                    break;
            }
            break;
        case false:
            switch (this->ShiftersPolarity)
            {
                case true:
                    digitalWrite(this->Pin,HIGH);
                    digitalWrite(this->Shifters[Digit],LOW);
                    break;
            
                case false:
                    digitalWrite(this->Pin,HIGH);
                    digitalWrite(this->Shifters[Digit],HIGH);
                    break;
            }
            break;
    }
    delayMicroseconds(this->Level);
}

void SSDi::setBrightness (int Level)
{
    this->Level = (10 - Level) * 300;
}

void SSDi::showString (String Data, int StringLength)
{
    char temp[StringLength + 1];
    strcpy(temp, Data.c_str());
    SSDi::showChars(temp,StringLength + 1);
}

void SSDi::showInt (unsigned long long Data)
{
    int DigitsCount = numDigits(Data);
    switch (DigitsCount)
    {
        case 1:
        SSDi::show(Data,0);
        break;

        case 2:
        SSDi::show(Data%10,0);
        SSDi::show((Data - (Data%10))/10,1);
        break;

        case 3:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data - Data%100)/100,2);
        break;

        case 4:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data%1000 - Data%100)/100,2);
        SSDi::show((Data - Data%1000)/1000,3);
        break;

        case 5:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data%1000 - Data%100)/100,2);
        SSDi::show((Data%10000 - Data%1000)/1000,3);
        SSDi::show((Data - Data%10000)/10000,4);
        break;

        case 6:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data%1000 - Data%100)/100,2);
        SSDi::show((Data%10000 - Data%1000)/1000,3);
        SSDi::show((Data%100000 - Data%10000)/10000,4);
        SSDi::show((Data - Data%100000)/100000,5);
        break;

        case 7:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data%1000 - Data%100)/100,2);
        SSDi::show((Data%10000 - Data%1000)/1000,3);
        SSDi::show((Data%100000 - Data%10000)/10000,4);
        SSDi::show((Data%1000000 - Data%100000)/100000,5);
        SSDi::show((Data - Data%1000000)/1000000,6);
        break;

        case 8:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data%1000 - Data%100)/100,2);
        SSDi::show((Data%10000 - Data%1000)/1000,3);
        SSDi::show((Data%100000 - Data%10000)/10000,4);
        SSDi::show((Data%1000000 - Data%100000)/100000,5);
        SSDi::show((Data%10000000 - Data%1000000)/1000000,6);
        SSDi::show((Data - Data%10000000)/10000000,7);
        break;
        
        case 9:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data%1000 - Data%100)/100,2);
        SSDi::show((Data%10000 - Data%1000)/1000,3);
        SSDi::show((Data%100000 - Data%10000)/10000,4);
        SSDi::show((Data%1000000 - Data%100000)/100000,5);
        SSDi::show((Data%10000000 - Data%1000000)/1000000,6);
        SSDi::show((Data%100000000 - Data%10000000)/10000000,7);
        SSDi::show((Data - Data%100000000)/100000000,8);
        break;

        case 10:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data%1000 - Data%100)/100,2);
        SSDi::show((Data%10000 - Data%1000)/1000,3);
        SSDi::show((Data%100000 - Data%10000)/10000,4);
        SSDi::show((Data%1000000 - Data%100000)/100000,5);
        SSDi::show((Data%10000000 - Data%1000000)/1000000,6);
        SSDi::show((Data%100000000 - Data%10000000)/10000000,7);
        SSDi::show((Data%1000000000 - Data%100000000)/100000000,8);
        SSDi::show((Data - Data%1000000000)/1000000000,9);
        break;

        case 11:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data%1000 - Data%100)/100,2);
        SSDi::show((Data%10000 - Data%1000)/1000,3);
        SSDi::show((Data%100000 - Data%10000)/10000,4);
        SSDi::show((Data%1000000 - Data%100000)/100000,5);
        SSDi::show((Data%10000000 - Data%1000000)/1000000,6);
        SSDi::show((Data%100000000 - Data%10000000)/10000000,7);
        SSDi::show((Data%1000000000 - Data%100000000)/100000000,8);
        SSDi::show((Data%10000000000 - Data%1000000000)/1000000000,9);
        SSDi::show((Data - Data%10000000000)/10000000000,10);
        break;

        case 12:
        SSDi::show(Data%10,0);
        SSDi::show((Data%100 - Data%10)/10,1);
        SSDi::show((Data%1000 - Data%100)/100,2);
        SSDi::show((Data%10000 - Data%1000)/1000,3);
        SSDi::show((Data%100000 - Data%10000)/10000,4);
        SSDi::show((Data%1000000 - Data%100000)/100000,5);
        SSDi::show((Data%10000000 - Data%1000000)/1000000,6);
        SSDi::show((Data%100000000 - Data%10000000)/10000000,7);
        SSDi::show((Data%1000000000 - Data%100000000)/100000000,8);
        SSDi::show((Data%10000000000 - Data%1000000000)/1000000000,9);
        SSDi::show((Data%100000000000 - Data%10000000000)/10000000000,10);
        SSDi::show((Data - Data%100000000000)/100000000000,11);
        break;

    }
    
        
    if (LeadingZeros)
    {
        int ZerosCount = this->ShiftersNumber - DigitsCount;
        for (int i = 0; i < ZerosCount; i++)
        {
            SSDi::show(0, i + DigitsCount);
        }
    }
}

int SSDi::numDigits(unsigned long long Data)  
{  
    Data = abs(Data);  
    return 
        (Data < 10 ? 1 :   
        (Data < 100 ? 2 :   
        (Data < 1000 ? 3 :   
        (Data < 10000 ? 4 :   
        (Data < 100000 ? 5 :   
        (Data < 1000000 ? 6 :   
        (Data < 10000000 ? 7 :  
        (Data < 100000000 ? 8 :  
        (Data < 1000000000 ? 9 :
        (Data < 10000000000 ? 10 :
        (Data < 100000000000 ? 11 :
        (Data < 1000000000000 ? 12 :  
        10))))))))))));  
}

void SSDi::setIntLeadingZeros (bool Status)
{
    this->LeadingZeros = Status;
}
