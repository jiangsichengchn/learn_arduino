#include "Arduino.h"

int _pin;
int _dottime;

void init(int pin)
{
  pinMode(pin,OUTPUT);
  _pin = pin;
  _dottime = 250;
}

void dot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void dash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}

void w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}

void s_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*10);
}

char a[][4] = {
{'.','-','*','*'},//A
{'-','.','.','.'},//B
{'-','.','-','.'},//C
{'-','.','.','*'},//D
{'.','*','*','*'},//E
{'.','.','-','.'},//F
{'-','-','.','*'},//G
{'.','.','.','.'},//H
{'.','.','*','*'},//I
{'.','-','-','-'},//J
{'-','.','-','*'},//K
{'.','-','.','.'},//L
{'-','-','*','*'},//M
{'-','.','*','*'},//N
{'-','-','-','*'},//O
{'.','-','-','.'},//P
{'-','-','.','-'},//Q
{'.','-','.','*'},//R
{'.','.','.','*'},//S
{'-','*','*','*'},//T
{'.','.','-','*'},//U
{'.','.','.','-'},//V
{'.','-','-','*'},//W
{'-','.','.','-'},//X
{'-','.','-','-'},//Y
{'-','-','.','.'} //Z
};

void setup() 
{
  init(13);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    int i = Serial.read();
    if (i>=97 && i<=122)
    {
      i -= 97;
      for (int j=0; j<4; ++j)
      {
        if (a[i][j]=='.')
            dot();
        else if (a[i][j]=='-')
            dash();
      }
      c_space();
    }
    else if (i == 32)
        w_space();
    else
        s_space();
  }
}
