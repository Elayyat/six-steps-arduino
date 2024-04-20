int AA1=3;
int AA2=5;
int BB1=6;
int BB2=9;
int CC1=10;
int CC2=11;

int en1=4;
int en2=7;
int en3=8;

int enable=2;
int emfA=A2;
int emfB=A3;
int emfC=A4;
int emf=A1;
int fase=1;

int IN=A0;
int tiempo=4000;


unsigned long previousMillis = 0; 

void setup() {
Serial.begin(9600);
  pinMode(AA1,OUTPUT);
  pinMode(AA2,OUTPUT);
  pinMode(BB1,OUTPUT);
  pinMode(BB2,OUTPUT);
  pinMode(CC1,OUTPUT);
  pinMode(CC2,OUTPUT);

  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(en3,OUTPUT);

  pinMode(enable,OUTPUT);

  pinMode(IN,INPUT);
  pinMode(emfA,INPUT);
  pinMode(emfB,INPUT);
  pinMode(emfC,INPUT);

  
  digitalWrite(enable,HIGH);
  previousMillis = micros();
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en3,HIGH);
  
  
}

void loop() {

 
      
      int emC = analogRead(A3);
      int emB = analogRead(A2);
      int emA = analogRead(A1);
      int sum = (emA+emB+emC)/3; 
      // Serial.println(sum);
  //if(currentMillis - previousMillis >= tiempo){
  
    //  previousMillis += tiempo;
   
  //Phase1 C-B
  switch(fase){
    case 1:
      digitalWrite(AA1,LOW);
      digitalWrite(BB1,LOW);
      digitalWrite(CC1,HIGH);
      break;

  //Phase2 A-B
    case 2:
      
      digitalWrite(BB1,LOW);
      digitalWrite(CC1,LOW);
      
      digitalWrite(AA1,HIGH);
      
      break;

  //Phase3 A-C
    case 3: 
      
      digitalWrite(BB1,LOW);
      
      digitalWrite(CC1,LOW);
  
      digitalWrite(AA1,HIGH);
    break;   
  
  //Phase4 B-C
  case 4:
      digitalWrite(AA1,LOW);
      digitalWrite(CC1,LOW);
      digitalWrite(BB1,HIGH);
      
      break;

  //Phase5 B-A 
  case 5:
      digitalWrite(AA1,LOW);
 
      digitalWrite(CC1,LOW);
      
    
      digitalWrite(BB1,HIGH);
      break;

  //Phase6 C-A
  case 6:
      digitalWrite(AA1,LOW);
      digitalWrite(BB1,LOW);
     
      digitalWrite(CC2,LOW);
      digitalWrite(CC1,HIGH);
    
  break;}



  int t =analogRead(IN);
 tiempo=map(t,0,1024,1000,0);

  
  if (fase<6){
    fase=fase+1;}
  else{
    fase=1;
  }
  float deay1 = tiempo;
    delay(deay1);
  
  


  
}

