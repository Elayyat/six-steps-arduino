int A_1=7;


int B_1=9;
int C_1=10;


int en1=3;
int en2=4;
int en3=8;
float deay1_prev= 1800;

int bmfA=A2;
int bmfB=A3;
int bmfC=A4;
int bmf=A1;
int state=1;

int IN=A5;
int tiempo=4000;


//unsigned long previousMillis = 0; 

void setup() {
Serial.begin(9600);
  pinMode(A_1,OUTPUT);
 
  pinMode(B_1,OUTPUT);
  //pinMode(BB2,OUTPUT);
  pinMode(C_1,OUTPUT);
 

  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(en3,OUTPUT);

  

  pinMode(IN,INPUT);
  //pinMode(A0,INPUT);
  pinMode(bmfA,INPUT);
  pinMode(bmfB,INPUT);
  pinMode(bmfC,INPUT);

  
  //previousMillis = micros();
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en3,HIGH);
  
  
}

void loop() {

    //int bmf = analogRead(A0);
      


  //Phase1 C-B
  switch(state){
    case 1:
      digitalWrite(en1,LOW);
      digitalWrite(en2,HIGH);
      digitalWrite(en3,HIGH);
     
      digitalWrite(B_1,LOW);
      digitalWrite(C_1,HIGH);
      break;

  //Phase2 A-B
    case 2:
      digitalWrite(en1,HIGH);
      digitalWrite(en2,HIGH);
      digitalWrite(en3,LOW);

      digitalWrite(B_1,LOW);
      digitalWrite(A_1,HIGH);
      
      break;

  //Phase3 A-C
    case 3: 
      digitalWrite(en1,HIGH);
      digitalWrite(en2,LOW);
      digitalWrite(en3,HIGH);

      digitalWrite(B_1,LOW);    
      digitalWrite(C_1,LOW);
      digitalWrite(A_1,HIGH);
    break;   
  
  //Phase4 B-C
  case 4:
      digitalWrite(en1,LOW);
      digitalWrite(en2,HIGH);
      digitalWrite(en3,HIGH);
      
      digitalWrite(C_1,LOW);
      digitalWrite(B_1,HIGH);
      
      break;

  //Phase5 B-A 
  case 5:
      digitalWrite(en1,HIGH);
      digitalWrite(en2,HIGH);
      digitalWrite(en3,LOW);

      digitalWrite(A_1,LOW);
      digitalWrite(B_1,HIGH);
      break;

  //Phase6 C-A
  case 6:

      digitalWrite(en1,HIGH);
      digitalWrite(en2,LOW);
      digitalWrite(en3,HIGH);

      digitalWrite(A_1,LOW);
      digitalWrite(C_1,HIGH);
    
  break;}



  int t =analogRead(A5);
 tiempo=map(t,70,1100,1000,1);

  
  if (state<6){
    state=state+1;}
  else{
    state=1;
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
   delayMicroseconds(600);
  
}

