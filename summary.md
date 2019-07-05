#��ԴӲ�����

>��˼��

##��һ��
##ѧϰ����
    ���ѧϰ��ԴӲ��    
    �������õ���վ  
    ��������İ�װ
arduino
![](img/arduino.jpg)
fritzing
![](img/fritzing.jpg)
processing
![](img/processing.jpg)

[Arduino](https://www.arduino.cc/)

[Fritzing](http://fritzing.org/home/)

[Processing](https://processing.org/)

##�ڶ���
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
Morse.cpp
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
Mrose.ino
#include <Morse.h>
Morse morse(13);
//����һ�����ִ洢ÿ����ĸ��Ħ��˹��
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
  //�򿪴���
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available() > 0)//�ж��Ƿ�������
  {
    int i = Serial.read();
    if (i>=97 && i<=122)//�ж��Ƿ�Ϊ��ĸ
    {
      i -= 97;
      //����Ħ��˹����ÿ⺯������led��˸
      for (int j=0; j<4; ++j)
      {
        if (a[i][j]=='.')
            morse.dot();
        else if (a[i][j]=='-')
            morse.dash();
      }
      morse.c_space();//�ַ���ļ��
    }
    else if (i == 32)
        morse.w_space();//��ȡ���ո�ʱ���ʼ�ļ��
    else
        morse.s_space();//��ȡ���س�ʱ���Ӽ�ļ��
  }
}
```
������
С����·ͼ
![](car/.jpg)
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
�����
![](CD4511-LED/CD4511.jpg)
����
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
������
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
��ͬ������ʾ
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
�ܽ�
    ���������ѧϰ����arduino��������һ�����˽⣬Ƕ��ʽ�����ǼƿƵ��ĸ�����֮һ��Ҳ��Ψһһ��Ӳ��������������ԭ��̫���š����Ǿ���ʵ�����֣�����������Ӳ����������ʵ������������׵õ����ӻ������Եĳɹ����׻�óɾ͸С���Ҳ��Ϊʲô����ܶ�С��������ⷽ���ѧϰ���Զ�ͯ��˵Ȥζ����ѧϰ����ҪӰ�����أ���������Ե�ѧϰ����ʹ��python���������������һЩС���������ԣ�Ҳȱ��Ȥζ�ԡ��෴��arduino�ȵ�ѧϰ��������С��ߣ������׼�����Ȥ��Ҳ���Ϊ�ʺ���Ϊ��ͯ�Ӵ���̵�;�����㽭�¸߿����߽���̼���߿���ǰ����ʹ��VB�������꿪ʼʹ��python��ѧ������������ѧϰ�ľ��飬�ܶ�ѧ��ѧϰ��̽�Ϊ���ѣ������Ҳȱ��ʵ���ԣ�����������Ϊ��������⣬������ʵ��ʹ���к�������Ĵ��룬Ϊ���÷�һ����ˢ�⣬��������ѧ�������档����ѧϰ��ȫ�����ݲ��ȴ�һC���Զ���٣�����������Ҳ�кܶ��˻���������ķ��������Ѿ��������������ϡ����ʹ��arduino������Ҫʵ���ķ�ʽ��Ϊѧϰ���ߣ�Ҳ��Ÿ������¸߿��ĸ�ĳ��ԡ�

    ��һ������˽���arduino�ļ�������ͻ���ʹ�������Լ�liunxϵͳ��Github����רҵ��չ�������˸���һ�����˽⡣Github��ʹ����ѧϰ�����Ҫ��һ����������ѧϰ���˵Ĵ��뻹�Ƿ����Լ��Ĵ��룬�����Ǽ��뿪Դ��Ŀ��������չ���кܴ�ô���

    �ڶ����д�˵�һ��arduino������Ħ��˹��Ĺ������led�Ƶ���˸����ʱ����Է���Ƕ��ʽ��������濪���Ĳ�ͬ��Ƕ��ʽ���Ҫ�󽫴���д��΢С��оƬ�У�����ʹ�õ��ڴ�������濪����С����˴��������Ч�ʳ�Ϊ����Ҫ��һ�����������濪������Ӳ���Ĳ��Ͻ�������Ը��ʹ�ýϵ͵�����Ч�ʻ�ȡ�����ı�ݺͿ��٣�java��python�����Է�չ���ȡ���Ƕ��ʽ����ֻ��ʹ��C��C++��Ч�ʸ�Ϊ���µĻ�����Խ��п�������ȻҲ��java��ʹ��Ҳ�����࣬�����ܶ�ҡC���Եĵ�λ������arduino�����Ҳ����ÿ�α����������ռ���˶��ٿռ䣬������ʹ�ö��٣�����һ��ȫ�µ����顣����ı�д����û��̫����죬�о�������ѧ��һ���µĿ�ܡ�

    �������д��С����������������ֳ���Ӳ�����������һ����ͬ��������ʱ�����⡣arduino���ڿ��ܳ��ֵ��������������ݣ��������ı䴮�ڵ�λ�������������һ�����������Ӳ���оͱ��뿼���������Ӱ�죬���ú��ʵ���ʱȷ�����չ滮���С�ͬʱ����Ԫ�����������޵����⣬��ʵ�������óȻ����ͨ����г��ԣ��ܿ��ܻ��ջ�Ԫ����������������Ŀ��ǣ�������д����룬������������û���⡱�Ϳ���ȥ���ԡ�

    �������˽⵽Ӳ����û��java�������еĶ��̵߳ĸ����ͨ��Ӳ���ķ�ʽ��Ҳ����ʵ���������߳�����Ч���������һЩ��Ҫ�����̡߳��Ĳ�������ʵ�ܶ�ͨ�����ʵ�ֵ�Ч���ǿ���ͨ��Ӳ��ʵ�ֵģ���������ķ�ʽ��Ϊ�򵥣���Ҳ��Ϊʲô�����Ӳ�������Űɣ����Ǹ�������дһ�����������Ǹ���Ӳ����ʵ��Ч����

    ʱ����Ȼ���ݣ�Ҳ����Ե��˽���Ƕ��ʽ�ĸ�����Ժ��רҵ����Ҳ����и�����ĽӴ�����ʹ����������򣬶�Ӳ�����˽�Ҳ�����ڴ���ı�д��

