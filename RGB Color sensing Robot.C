#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define s0 A0
#define s1 10
#define s2 A1
#define s3 A2
#define out 13

int data = 0;

void setup()
{
    pinMode(s0, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(out, INPUT);

    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.setCursor(0, 0);
    lcd.print("RGB");
    lcd.setCursor(0, 1);
    lcd.print("ROBOT");
    delay(2000);
    digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
}
void loop()
{
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    Serial.print("Red Value = ");
    GetData();

    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    Serial.print("Blue Value= ");
    GetData();

    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    Serial.print("Green Value= ");
    GetData();

    Serial.println();

    delay(2000);
}

void GetData() {
    data = pulseIn(out, LOW);
    Serial.print(data);
    Serial.print("\t");
    delay(20);
  lcd.setCursor(0, 0);
  lcd.print("RGB ROBOT");
  lcd.setCursor(0, 1);
  lcd.print(data);
  delay(2000);
  lcd.clear();
       if(data>=10)
    {
     digitalWrite(6, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(8, HIGH);
     digitalWrite(9, LOW);
    }
    else
       {
     digitalWrite(6, LOW);
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
      lcd.setCursor(0, 0);
      lcd.print("ROBOT");
      lcd.setCursor(0, 1);
      lcd.print("STOPED");
       delay(3000);
       lcd.clear();
       }
}