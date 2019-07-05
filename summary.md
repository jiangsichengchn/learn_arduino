# 开源硬件设计

>蒋思成

## 第一天

#### 学习内容
    如何学习开源硬件    
    几个常用的网站  
    三个软件的安装

    arduino
![](img/arduino.jpg)  
    fritzing
![](img/fritzing.jpg)  
    processing
![](img/processing.jpg)  

![Arduino](https://www.arduino.cc/)
![Fritzing](http://green.fritzing.org/home/)
![Processing](https://processing.org/)


## 第二天

    Morse.h
```c
    #ifndef _MORSE_H
    #define _MORSE_H
    class Morse
    {
    public:
        Morse(int pin);
        void dot();
        void dash();
        void c_space();
        void w_space();
        void s_space();
    private:
        int _pin;
        int _dottime;
    };
    #endif /*_MORSE_H*/

```
    Morse.cpp
```c
#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_dottime=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*4);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*2);
}

void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*6);
}

void Morse::s_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*10);
}

```

    Mrose.ino
```c
#include <Morse.h>

Morse morse(13);
//定义一个数字存储每个字母的摩尔斯码
char a[26][4] = {
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
  //打开串口
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)//判断是否有输入
  {
    int i = Serial.read();
    if (i>=97 && i<=122)//判断是否为字母
    {
      i -= 97;
      //根据摩尔斯码调用库函数控制led闪烁
      for (int j=0; j<4; ++j)
      {
        if (a[i][j]=='.')
            morse.dot();
        else if (a[i][j]=='-')
            morse.dash();
      }
      morse.c_space();//字符间的间隔
    }
    else if (i == 32)
        morse.w_space();//读取到空格时单词间的间隔
    else
        morse.s_space();//读取到回车时句子间的间隔
  }
}

```

## 第三天

    小车电路图
![](car/1.jpg)
    
```c
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

int income = 0;

void loop()
{
  if (Serial.available()>0)
  {
    income = Serial.read();
  }
  switch(income)
  {
    case 'f':
        forward();
        break;
    case 'b':
        backward();
        break;
    case 'l':
        left();
        break;
    case 'r':
        right();
        break;
    case 's':
        stop();
        break;
    default:
        break;
  }
}

void forward()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void backward()
{
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
}

void left()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
}

void right()
{
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void stop()
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

```

    数码管
![](CD4511-LED/CD4511.jpg)

    代码
```c
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}
byte income=0;
void loop()
{
  if(Serial.available()>0)
  {
    income = Serial.read();
    income = income - '0';
    digitalWrite(2,LOW);
    delay(10);
    if(income & 0x1)
    {
      digitalWrite(3,HIGH);
    }
    else
    {
      digitalWrite(3,LOW);
    }
    if((income>>1) & 0x1)
    {
      digitalWrite(4,HIGH);
    }
    else
    {
      digitalWrite(4,LOW);
    }
    if((income>>2) & 0x1)
    {
      digitalWrite(5,HIGH);
    }
    else
    {
      digitalWrite(5,LOW);
    }
    if((income>>3) & 0x1)
    {
      digitalWrite(6,HIGH);
    }
    else
    {
      digitalWrite(6,LOW);
    }
    delay(10);
    digitalWrite(2,HIGH);
    delay(10);
  }
}

```

## 第四天
    morse2
![](morse2/morse2.jpg)
```c
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

```

    不同数字显示
![](4LED/4LED.jpg)
```c
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}
byte income=0;
void loop()
{
  if(Serial.available()>0)
  {
    income = Serial.read();
    income = income - '0';
    digitalWrite(2,LOW);
    delay(10);
    if(income & 0x1)
    {
      digitalWrite(3,HIGH);
    }
    else
    {
      digitalWrite(3,LOW);
    }
    if((income>>1) & 0x1)
    {
      digitalWrite(4,HIGH);
    }
    else
    {
      digitalWrite(4,LOW);
    }
    if((income>>2) & 0x1)
    {
      digitalWrite(5,HIGH);
    }
    else
    {
      digitalWrite(5,LOW);
    }
    if((income>>3) & 0x1)
    {
      digitalWrite(6,HIGH);
    }
    else
    {
      digitalWrite(6,LOW);
    }
    delay(10);
    digitalWrite(2,HIGH);
    delay(10);
  }
}

```