#include <LiquidCrystal.h>
const int RS = 2;
const int E  = 3;
const int D4 = 4;
const int D5 = 5;
const int D6 = 6;
const int D7 = 7;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

int v = A0;
int volt = 0;
int c1 = A1;
int c1v = 0;
int c2 = A2;
int c2v = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(v, INPUT);
  pinMode(c1, INPUT);
  pinMode(c2, INPUT);
 
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("  ENERGY METER ");
  lcd.setCursor(0,1);
  lcd.print("THEFT DETECTION");
  delay(2000);
  Serial.begin(9600);         // Setting the baudrate at 9600
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

  volt = analogRead(v);
  c1v = analogRead(c1);
  c2v = analogRead(c2);
  
  lcd.setCursor(0,0);
  lcd.print("V :");
  lcd.print(volt);
  lcd.print(" ");
  
  lcd.setCursor(0,1);
  lcd.print("DI:");
  lcd.print(c1v);
  lcd.print(" ");
  
  lcd.setCursor(12,0);
  lcd.print("LI:");
  lcd.print(c2v);
  lcd.print(" ");

  Serial.print(volt);
  Serial.print(" ");
  Serial.print(c1v);
  Serial.print(" ");
  Serial.print(c2v);
  Serial.print(" ");
  Serial.println();  
  delay(500);

}
