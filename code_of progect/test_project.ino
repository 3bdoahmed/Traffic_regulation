#include <LiquidCrystal.h>
const int rs = 53, en = 52, d4 = 48, d5 = 49, d6 = 50, d7 = 51;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//****** Define the pins for Ultrasonic sensors around squear place ***********
#define trp_in1 6
#define echp_in1 7

#define trp_in2 13
#define echp_in2 12

#define trp_in3 42
#define echp_in3 43

#define trp_in4 40
#define echp_in4 41

//************************************

#define trp_out1 25
#define echp_out1 24

#define trp_out2 11
#define echp_out2 10

#define trp_out3 47
#define echp_out3 46

#define trp_out4 44
#define echp_out4 45

//**************************  Define leds *******************
#define greanled_1 2 
#define redled_1 3

#define greanled_2 9 
#define redled_2 8

#define greanled_3 39
#define redled_3 38 

#define greanled_4 37
#define redled_4 36

// *************** Function of Ultrasonic sensor & actin acording to counter ***************
float ultra_dis(int trgpin, int echopin);
void fun_action(int c);

//****************************
bool flag[8]={0};


int counter=0;
void setup() {
  
  //************* ultrasonic input **************
  pinMode(trp_in1, OUTPUT);
  pinMode(echp_in1, INPUT);

  pinMode(trp_in2, OUTPUT);
  pinMode(echp_in2, INPUT);

  pinMode(trp_in3, OUTPUT);
  pinMode(echp_in3, INPUT);

  pinMode(trp_in4, OUTPUT);
  pinMode(echp_in4, INPUT);
  
 //************* ultrasonic output **************
  pinMode(trp_out1, OUTPUT);
  pinMode(echp_out1, INPUT);

  pinMode(trp_out2, OUTPUT);
  pinMode(echp_out2, INPUT);

  pinMode(trp_out3, OUTPUT);
  pinMode(echp_out3, INPUT);

  pinMode(trp_out4, OUTPUT);
  pinMode(echp_out4, INPUT);

  //*************** leds *******************
  pinMode(greanled_1, OUTPUT);
  pinMode(redled_1, OUTPUT);
  
  pinMode(greanled_2, OUTPUT);
  pinMode(redled_2, OUTPUT);
  
  pinMode(greanled_3, OUTPUT);
  pinMode(redled_3, OUTPUT);
  
  pinMode(greanled_4, OUTPUT);
  pinMode(redled_4, OUTPUT);

  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  

  Serial.print("the distance sens1 ");
  Serial.print(ultra_dis(trp_in1, echp_in1));
  Serial.println("cm");
  Serial.print("the distance sens2 ");
  Serial.print(ultra_dis(trp_in2, echp_in2));
  Serial.println("cm");
  Serial.print("the distance sens3 ");
  Serial.print(ultra_dis(trp_in3, echp_in3));
  Serial.println("cm");
  Serial.print("the distance sens4 ");
  Serial.print(ultra_dis(trp_in4, echp_in4));
  Serial.println("cm");
  
  Serial.print("the distance sens5 ");
  Serial.print(ultra_dis(trp_out1, echp_out1));
  Serial.println("cm");
  Serial.print("the distance sens6 ");
  Serial.print(ultra_dis(trp_out2, echp_out2));
  Serial.println("cm");
  Serial.print("the distance sens7 ");
  Serial.print(ultra_dis(trp_out3, echp_out3));
  Serial.println("cm");
  Serial.print("the distance sens8 ");
  Serial.print(ultra_dis(trp_out4, echp_out4));
  Serial.println("cm");
  
  Serial.print("counter: ");
  Serial.println(counter); 
  
  //*************** teak action acording to the crowd in place square ***********************
   fun_action(counter);
  //*************** count the cars input *****************
  
  if ( ultra_dis(trp_in1, echp_in1)  <= 7 ) {    flag[0] = 1; }
  else if ( (ultra_dis(trp_in1, echp_in1)  > 7 )  && flag[0]== 1)   { counter++; flag[0] = 0;}   
 
  if ( ultra_dis(trp_in2, echp_in2) <= 7 ) {    flag[1] = 1; }
  else if ((ultra_dis(trp_in2, echp_in2) > 7) && flag[1] == 1)   { counter++; flag[1] = 0 ;}   
  
  if ( ultra_dis(trp_in1, echp_in1) <= 7 ) {    flag[2]= 1; }
  else if ((ultra_dis(trp_in3, echp_in3) > 7 )  && flag[2] == 1)   { counter++; flag[2]= 0 ;}   
 
  if (ultra_dis(trp_in4, echp_in4)  <= 7 ) {    flag[3] = 1; }
  else if (( ultra_dis(trp_in4, echp_in4) > 7) && flag[3] == 1)   { counter++; flag[3] = 0 ;}   
 
  //****************count the cars output *****************   

    if ( ultra_dis(trp_out1, echp_out1) <= 7 ) {    flag[4] = 1; }
  else if ( (ultra_dis(trp_out1, echp_out1)  >7 )   && flag[4]== 1)   { counter--; flag[4] = 0;}   
 
  if ( ultra_dis(trp_out2, echp_out2) <= 7 ) {    flag[5]= 1; }
  else if ((ultra_dis(trp_out2, echp_out2) > 7 ) && flag[5] == 1)   { counter--; flag[5] = 0 ;}   
  
  if ( ultra_dis(trp_out3, echp_out3) <= 7 ) {    flag[6] = 1; }
  else if ((ultra_dis(trp_out3, echp_out3) > 7)  && flag[6] == 1)   { counter--; flag[6] = 0 ;}   
 
  if (ultra_dis(trp_out4, echp_out4) <= 7 ) {    flag[7] = 1; }
  else if (( ultra_dis(trp_out4, echp_out4) > 7 ) && flag[7] == 1)   { counter--; flag[7] = 0 ;} 

 // delay(1000);
 
}

float ultra_dis(int trgpin, int echopin) {
  digitalWrite(trgpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trgpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trgpin, LOW);
  float x = pulseIn(echopin, HIGH);
  float dis = (x * 0.0343) / 2;
  return dis;
}

//***********************************************
void fun_action(int c)
{
   if (c >= 5)
  {
     lcd.clear();
     digitalWrite(redled_1, HIGH);
     digitalWrite(redled_2, HIGH);
     digitalWrite(redled_3, HIGH);
     digitalWrite(redled_4, HIGH);
     digitalWrite(greanled_1, LOW);
     digitalWrite(greanled_2, LOW);
     digitalWrite(greanled_3, LOW);
     digitalWrite(greanled_4, LOW);
     lcd.setCursor(0, 0);
     lcd.print("square is crowded ");
     lcd.setCursor(0, 1);
     lcd.print("there is ");
     lcd.print(c);
     lcd.print(" cars");
  }
   else 
  {
    lcd.clear();
    digitalWrite(greanled_1, HIGH);
    digitalWrite(greanled_2, HIGH);
    digitalWrite(greanled_3, HIGH);
    digitalWrite(greanled_4, HIGH);
    digitalWrite(redled_1, LOW);
    digitalWrite(redled_2, LOW);
    digitalWrite(redled_3, LOW);
    digitalWrite(redled_4, LOW);
    lcd.setCursor(0, 0);
    lcd.print("square not crowded ");
    lcd.setCursor(0, 1);
    lcd.print("there is ");
    lcd.print(c);
    lcd.print(" cars"); 
  
  } 
  
  //delay(3000);
  
}
