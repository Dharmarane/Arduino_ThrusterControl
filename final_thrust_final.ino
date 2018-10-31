long unsigned w,w1,w2;
int a,b,c,flag,ctr;
int g[5];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,INPUT);
  g[0]=g[1]=g[2]=g[3]=0;
  TCCR1B = TCCR1B & B11111000 | B00001100;
}

void loop() {
  // put your main code here, to run repeatedly:
  
w=pulseIn(7,HIGH);


if(w==0)
b=b+1;


while(b>1)
{
  c=0;
  Serial.print("hi");
  while(c<7)
  {
  w2=pulseIn(7,HIGH);
  if((w2>600)&&(w2<750))
  c++;
  }
  Serial.print("hi2");
  
  ctr=0;
  while(ctr<5)
  {   w2=pulseIn(7,HIGH);
      if((w2>350)&&(w2<500))
      {g[ctr]=0;
      ctr=ctr+1;}
      if((w2>=600)&&(w2<=800))
      {g[ctr]=1;
      ctr=ctr+1;
      }
     }
  
  Serial.print(g[0]);
  Serial.print(g[1]); 
  Serial.print(g[2]);
  Serial.print(g[3]);
  Serial.print(g[4]);
  Serial.print("\n");
  b=0;
  //thruster part
if(g[0]==1)//forward
{
  analogWrite(5,200);
  analogWrite(6,200);
}
if(g[1]==1)//stop
{
  digitalWrite(2,HIGH);
  delay(5000);
  digitalWrite(2,LOW);
  }
if(g[2]==1)//left
{
  analogWrite(5,127);
  analogWrite(6,200);
}
if(g[3]==1)//right
{
  analogWrite(5,200);
  analogWrite(6,127);
}

if((g[0]==0)&&(g[1]==0)&&(g[2]==0)&&(g[3]==0))
 
  {analogWrite(5,0);
  analogWrite(6,0);
  }
  }
  }
  

}
