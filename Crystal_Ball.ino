#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("   Stimuler le");
  lcd.setCursor(0, 1);
  lcd.print("   REVELATEUR!");
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  
  if(switchState != prevSwitchState){
    if(switchState == LOW){
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("L'oracle dit:");
      lcd.setCursor(0, 1);

      switch(reply){
        case 0:
        lcd.print("Tu es malade");
        break;

        case 1:
        lcd.print("Tu es en forme");
        break;

        case 2:
        lcd.print("Tu es embitieux");
        break;

        case 3:
        lcd.print("Tu es courageux");
        break;

        case 4:
        lcd.print("Tu es incertain");
        break;

        case 5:
        lcd.print("Touchez encore..");
        break;

        case 6:
        lcd.print("Tu as des doutes");
        break;

        case 7:
        lcd.print("Tu es fatiguer");
        break; 
      }
    }
  }
  prevSwitchState = switchState;
}
