#define ms_per_hour  3600000//1 time
#define ms_per_min    60000 //1 minutt
#define ms_per_sec    1000  //1 sekund

const int buttonPin1=2;//Definere pins
const int buttonPin2=3;//Definere pins
int buttonState1=0; //Definere knapper
int buttonState2=0; //Definere knapper
int lastButtonState = 0; //Sette buttonstate
int sum = 0; //Vann counter
int vannMengde = 2500; //Daglig anbefaling av vann
int litenKopp = 350;//Gjennomsnittlig størrelse på et vanlig glass.
int storKopp = 550;//Gjennomsnittlig størrelse på et stort glass.
unsigned long lastReset = ms_per_hour*24; //24 timer teller

const int resistorLED4=220;//Resistorverdi
const int resistorLED5=220;
const int resistorLED6=220;
const int resistorLED7=220;
const int resistorLED8=220;
const int resistorLED9=220;
const int resistorLED10=220;





void setup() {
  Serial.begin(9600);
  Serial.println("Program started");
  pinMode(buttonPin1,INPUT_PULLUP);//Sette knapper
  pinMode(buttonPin2, INPUT_PULLUP);//Sette knapper
  pinMode(4, OUTPUT); //Setter hvordan LED skal lyse på starten av programmet.
  digitalWrite(4,HIGH);
  pinMode(5, OUTPUT);
  digitalWrite(5,HIGH);
  pinMode(6, OUTPUT);
  digitalWrite(6,HIGH);
  pinMode(7, OUTPUT);
  digitalWrite(7,HIGH);
  pinMode(8, OUTPUT);
  digitalWrite(8,HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9,HIGH);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  
  
}

void loop() {

  if(digitalRead(buttonPin1) == HIGH){
    sum += litenKopp; //legger til lite glass i dagens mengde.
    Serial.println("Knapp trykket");//
    Serial.println("SUM: ");
    Serial.println(sum);
    delay(700);//For å unngå at knappen registrerer flere trykk på ett trykk.
  }

  if(digitalRead(buttonPin2) == HIGH){
    sum += storKopp; //legger til stort glass i dagens mengde.
    Serial.println("Knapp trykket");
    Serial.println("SUM: ");
    Serial.println(sum);
    delay(700);  //For å unngå at knappen registrerer flere trykk på ett trykk.
  }
      if(sum >= ( vannMengde*0.166666667)){
        analogWrite(4,0);//Skrur av første røde LED.
      }
      
      if(sum >= ( vannMengde*0.166666667)*2){
        analogWrite(5, 0);//Skrur av andre røde LED
      }
      
      if(sum >= ( vannMengde*0.166666667)*3){
       analogWrite(6, 0);//Skrr av tredje røde LED.
      }
      
      if(sum >= ( vannMengde*0.166666667)*4){
        analogWrite(7, 0);//Skrur av fjerde røde LED
      }
      
      if(sum >= ( vannMengde*0.166666667)*5){
        analogWrite(8, 0); //Skrur av femte røde LED
      }
      
      if(sum >= ( vannMengde*0.166666667)*6){
        analogWrite(9, 0); //Skrur av siste røde LED 
        analogWrite(10, 255); //Grønn LED for å indikere at man har drukket sitt dagsbehov.
      }
      
      if(millis() > lastReset){
        lastReset += lastReset;//Legger til samme verdien på nytt så nedtelling skjer igjen.
        sum=0; //Nullstiller counter på vannmengden.
        analogWrite(4,255); //Slår på alle LED som viser hvor mye vann som gjenstår
        analogWrite(5, 255);
        analogWrite(6,255);
        analogWrite(7, 255);
        analogWrite(8,255);
        analogWrite(9, 255);
        analogWrite(10,0); //Skrur av grønn LED som indikerer at man er ferdig
      }
}
