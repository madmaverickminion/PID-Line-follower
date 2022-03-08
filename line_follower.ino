int a[4:0];
bool a_digital[4:0];// 1 value for white surface and 0 for black surface 
int error=0;

const int thres=100;

void setup(){
}

void loop(){
a[0]=analogRead();
a[1]=analogRead();
a[2]=analogRead();
a[3]=analogRead();
a[4]=analogRead();

if(a[0]>thres){
  a_digital[0]=1;  
 }else a_digital[0]=0;
 if(a[1]>thres){
  a_digital[1]=1;  
 }else a_digital[1]=0;
 if(a[2]>thres){
  a_digital[2]=1;  
 }else a_digital[2]=0;
 if(a[3]>thres){
  a_digital[3]=1;  
 }else a_digital[3]=0;
 if(a[4]>thres){
  a_digital[4]=1;  
 }else a_digital[4]=0;

 if(a_digital[0]==1 && a_digital[1]==1 && a_digital[2]==0 && a_digital[3]==1 && a_digital[4]==1){
  error=0;
 }else if(a_digital[0]==1 && a_digital[1]==1 && a_digital[2]==0 && a_digital[3]==1 && a_digital[4]==1){
  
 }
}
