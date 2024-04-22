int AA1=6;
int AA2=5;
//int BB1=6;
int BB1=9;
int CC1=10;
int CC2=11;

int en1=3;
int en2=7;
int en3=8;
float deay1_prev= 1800;
int enable=2;
int emfA=A2;
int emfB=A3;
int emfC=A4;
int emf=A1;
int fase=1;

int IN=A5;
int tiempo=4000;


//unsigned long previousMillis = 0; 

void setup() {
Serial.begin(9600);
  pinMode(AA1,OUTPUT);
  pinMode(AA2,OUTPUT);
  pinMode(BB1,OUTPUT);
  //pinMode(BB2,OUTPUT);
  pinMode(CC1,OUTPUT);
  pinMode(CC2,OUTPUT);

  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(en3,OUTPUT);

  pinMode(enable,OUTPUT);

  pinMode(IN,INPUT);
  //pinMode(A0,INPUT);
  pinMode(emfA,INPUT);
  pinMode(emfB,INPUT);
  pinMode(emfC,INPUT);

  
  digitalWrite(enable,HIGH);
  //previousMillis = micros();
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en3,HIGH);
  
  
}

void loop() {

    //int bmf = analogRead(A0);
      
      // int emC = analogRead(A3);
      // int emB = analogRead(A2);
      // int emA = analogRead(A1);
      // int sum = (emA+emB+emC)/3; 
       //Serial.println(bmf);

  //Phase1 C-B
  switch(fase){
    case 1:
      digitalWrite(en1,LOW);
      digitalWrite(en2,HIGH);
      digitalWrite(en3,HIGH);
     
      digitalWrite(BB1,LOW);
      digitalWrite(CC1,HIGH);
      break;

  //Phase2 A-B
    case 2:
      digitalWrite(en1,HIGH);
      digitalWrite(en2,HIGH);
      digitalWrite(en3,LOW);

      digitalWrite(BB1,LOW);
      digitalWrite(AA1,HIGH);
      
      break;

  //Phase3 A-C
    case 3: 
      digitalWrite(en1,HIGH);
      digitalWrite(en2,LOW);
      digitalWrite(en3,HIGH);

      digitalWrite(BB1,LOW);    
      digitalWrite(CC1,LOW);
      digitalWrite(AA1,HIGH);
    break;   
  
  //Phase4 B-C
  case 4:
      digitalWrite(en1,LOW);
      digitalWrite(en2,HIGH);
      digitalWrite(en3,HIGH);
      
      digitalWrite(CC1,LOW);
      digitalWrite(BB1,HIGH);
      
      break;

  //Phase5 B-A 
  case 5:
      digitalWrite(en1,HIGH);
      digitalWrite(en2,HIGH);
      digitalWrite(en3,LOW);

      digitalWrite(AA1,LOW);
      digitalWrite(BB1,HIGH);
      break;

  //Phase6 C-A
  case 6:

      digitalWrite(en1,HIGH);
      digitalWrite(en2,LOW);
      digitalWrite(en3,HIGH);

      digitalWrite(AA1,LOW);
      digitalWrite(CC1,HIGH);
    
  break;}



  int t =analogRead(A5);
 tiempo=map(t,70,1100,1000,1);

  
  if (fase<6){
    fase=fase+1;}
  else{
    fase=1;
  }

 
  float deay1 = 10*tiempo;
   // delayMicroseconds(deay1);
     if (abs(deay1- deay1_prev) > 300){
    deay1_prev = deay1;}
  else{
    deay1_prev=deay1_prev;
  }
  //Serial.println(deay1_prev);
  delayMicroseconds(deay1_prev);
   delayMicroseconds(2400);
  
}

