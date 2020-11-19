String voice;
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

Servo s1,s2;
int _ABVAR_1_a=0;
//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  lcd.begin();
  s1.attach(9,880,2200);
  s2.attach(10,880,2200);
  s1.write(90);
  s2.write(90);
}
 
//-----------------------------------------------------------------------//  `
void loop() {
  while (Serial.available())
  {  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#'
    break; //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//  
  //----------Control LEDs----------// 
    if(voice == "*how do you feel")
    { 
      angry();    
    }
      
  else if(voice == "*wish for birthday")
  {
    birthday();
  }
   else if(voice == "*calm down" || voice == "*normal")
   {
  normal();
  }
  else if(voice == "*wink")
   {
  winkboth();
  }
 
  else if(voice == "*smart")
   {
  smarteye();
  }
 
  else if(voice == "*double smart")
   {
  doublesmarteye();
  }
  else if(voice == "*do you know priya")
   {
  priya();
   }
  else if(voice == "*which is the best country")
   {
  india();
   }
  else if(voice == "*what is your name")
  {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("My name is");
  lcd.setCursor(2,1);
  lcd.print("Expressobot");
  }
  else if(voice == "*who made you")
  {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Khushi");
  }
voice="";} //Reset the variable after initiating 
} 
//-----------------------------------------------------------------------------------------//

void india()
{ 
  lcd.setCursor(0,0);
  lcd.print("india") ;
}
 
void smarteye()
{
  s1.write(50);
  s2.write(90);
  delay(300);
  s1.write(90);
  s2.write(90);
 }
 
void doublesmarteye()
{
   s1.write(50);
  s2.write(90);
  delay(300);
  s1.write(90);
  s2.write(90);
  delay(300);
  s1.write(90);
  s2.write(130);
  delay(300);
  s1.write(90);
  s2.write(90);
}
 
void priya()
{
  s1.write(50);
  s2.write(90);
  delay(300);
  s1.write(90);
  s2.write(90);
  delay(300);
  s1.write(90);
  s2.write(130);
  delay(300);
  s1.write(90);
  s2.write(90);
  delay(500);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
 
  s1.write(170);
  s2.write(90);
  delay(1000);
  
  s1.write(90);
  s2.write(90);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
void winkboth()
{
  s1.write(0);
  s2.write(90);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  delay(1000);
  s1.write(90);
  s2.write(180);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(1000);
  s1.write(90);
  s2.write(90);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(1000);
}

void birthday()
{
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("HAPPY");
  lcd.setCursor(4,1);
  lcd.print("BIRTHDAY");
  tone(11, 261, 100);
  delay( 750 );
  tone(11, 294, 100);
  delay( 750 );
  tone(11, 330, 100);
  delay( 750 );
  tone(11, 349, 100);
  delay( 750 );
  tone(11, 392, 100);
  delay( 750 );
  tone(11, 440, 100);
  delay( 750 );
  tone(11, 494, 100);
  delay( 750 );
  tone(11, 515, 100);
  delay( 750 ); 
}
 
void angry()
 
{
  lcd.setCursor(4, 0);
  lcd.print("angry");
  s1.write(50);
  s2.write(130);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  for(int i=0;i<10;i++)
  {
    lcd.noBacklight();
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(100);     
    lcd.backlight();
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    delay(100);
    }
}

void normal()
{
  s1.write(90);
  s2.write(90);
  lcd.clear();
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
