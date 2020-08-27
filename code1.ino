const int a = 8;  //For displaying segment "a"
const int b = 9;  //For displaying segment "b"
const int c = 4;  //For displaying segment "c"
const int d = 5;  //For displaying segment "d"
const int e = 6;  //For displaying segment "e"
const int f = 2;  //For displaying segment "f"
const int g = 3;  //For displaying segment "g"

bool bPress = false;
const int IncbuttonPin = 10;
const int DecbuttonPin = 11;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses

int IncbuttonState = 0;         // current state of the button
int lastIncbuttonState = 0;     // previous state of the button

int DecbuttonState = 0;         // current state of the button
int lastDecbuttonState = 0;     // previous state of the button


void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G

  pinMode( IncbuttonPin , INPUT_PULLUP );
  pinMode( DecbuttonPin , INPUT_PULLUP );
  Serial.begin(9600);
  
  displayDigit(buttonPushCounter);
  
}

void loop() {
  
   IncbuttonState = digitalRead(IncbuttonPin);
   DecbuttonState = digitalRead(DecbuttonPin);

   checkIncButtonPress();
   checkDecButtonPress();
  
  if( bPress ){
    bPress = false;
     turnOff();
     displayDigit(buttonPushCounter);
  }

   /*
  for(int i=0;i<10;i++)
 {
   displayDigit(i);
   delay(1000);
   turnOff();
 }
 */
}

void checkIncButtonPress()
{
   // compare the IncbuttonState to its previous state
  if (IncbuttonState != lastIncbuttonState) {
    // if the state has changed, increment the counter
    if (IncbuttonState == LOW) {
      // if the current state is HIGH then the button went from off to on:
      bPress = true;
      buttonPushCounter++;
      if( buttonPushCounter > 9) buttonPushCounter =0 ;
      Serial.println("on");
      
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastIncbuttonState = IncbuttonState;

}
void checkDecButtonPress()
{
   // compare the IncbuttonState to its previous state
  if (DecbuttonState != lastDecbuttonState) {
    // if the state has changed, increment the counter
    if (DecbuttonState == LOW) {
      // if the current state is HIGH then the button went from off to on:
      bPress = true;
      buttonPushCounter--;
      if( buttonPushCounter < 0) buttonPushCounter =9 ;
      Serial.println("on");
      
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastDecbuttonState = DecbuttonState;

}  

void displayDigit(int digit)
{
 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);

 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);

 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);

 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);

 //Conditions for displaying segment e 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);

 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);

}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
