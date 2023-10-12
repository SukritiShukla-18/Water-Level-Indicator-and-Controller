//sukriti123miniproject@gmail.com


#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

#define level1Input 2
#define level2Input 3
#define level3Input 4
#define level1Led 5
#define level2Led 6
#define level3Led 7
#define relay 8
int waterLevel= 0 ;

void setup() {
  // put your setup code here, to run once:
  delay(500);
  Serial.begin(9600);
  Serial.println("Water Level Controller");
  lcd.begin(16,2);
  pinMode (level1Input,INPUT);
  pinMode (level2Input,INPUT);
  pinMode (level3Input,INPUT);
  pinMode (level1Led,OUTPUT);
  pinMode (level2Led,OUTPUT);
  pinMode (level3Led,OUTPUT);
  pinMode (relay,OUTPUT);
  digitalWrite(level1Led,LOW);
  digitalWrite(level2Led,LOW);
  digitalWrite(level3Led,LOW);
  digitalWrite(relay,LOW);
  lcd.clear();
  lcd.home();
  lcd.print("Water Level:");
  lcd.setCursor(0,1);
  lcd.print("Pump Status:");
}

void loop() {
  // put your main code here, to run repeatedly:
  waterLevel =0 ;
  //check level-1
  if(digitalRead(level1Input)==true){
    waterLevel++;
  }

  //check level-2
  if(digitalRead(level2Input) ==true){
    waterLevel++;
  }

  //check level-3
  if(digitalRead(level3Input)==true){
    waterLevel++;
  }

  //turn off all water level led's

  digitalWrite(level1Led,LOW);
  digitalWrite(level2Led,LOW);
  digitalWrite(level3Led,LOW);

  //update pump status & update led

  switch(waterLevel){
    case 0:
    digitalWrite(relay,HIGH);
    digitalWrite(level1Led,LOW);
    digitalWrite(level2Led,LOW);
    digitalWrite(level3Led,LOW);
    lcd.setCursor(12,0);
    lcd.print("Empty");
    lcd.setCursor(12,1);
    lcd.print("On ");
    break;

    case 1:
    digitalWrite(level1Led,HIGH);
    digitalWrite(level2Led,LOW);
    digitalWrite(level3Led,LOW);
    lcd.setCursor(12,0);
    lcd.print("Lv-1 ");
    break;

    case 2:
    digitalWrite(level1Led,LOW);
    digitalWrite(level2Led,HIGH);
    digitalWrite(level3Led,LOW);
    lcd.setCursor(12,0);
    lcd.print("Lv-2 ");
    break;

    case 3:
    digitalWrite(level1Led,LOW);
    digitalWrite(level2Led,LOW);
    digitalWrite(level3Led,HIGH);
    digitalWrite(relay,LOW);
    lcd.setCursor(12,0);
    lcd.print("Lv-3 ");
    lcd.setCursor(12,1);
    lcd.print("Off");
    break;

  }



  
}
