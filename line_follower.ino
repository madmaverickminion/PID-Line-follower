int a[5];
bool a_digital[5];// 1 value for white surface and 0 for black surface 
//-ve for left +ve for right
//motor_left1=3
int error=0;
int ki=0;
int kp=0;
int kd=0;

int previous_error=0;
const int thres=100;
int speed_left=153;
int speed_right=153;
int pid_value=0;
int i=0;
int d=0;

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
 }else if(a_digital[0]==1 && a_digital[1]==1 && a_digital[2]==0 && a_digital[3]==0 && a_digital[4]==1){
  error=-1;
 }
 else if(a_digital[0]==1 && a_digital[1]==1 && a_digital[2]==1 && a_digital[3]==0 && a_digital[4]==1){
  error=-2;
 }else if(a_digital[0]==1 && a_digital[1]==1 && a_digital[2]==1 && a_digital[3]==0 && a_digital[4]==0){
  error=-3;
 }else if(a_digital[0]==1 && a_digital[1]==1 && a_digital[2]==1 && a_digital[3]==1 && a_digital[4]==0){
  error=-4;
 }else if(a_digital[0]==1 && a_digital[1]==0 && a_digital[2]==0 && a_digital[3]==1 && a_digital[4]==1){
  error=1;
 }else if(a_digital[0]==1 && a_digital[1]==0 && a_digital[2]==1 && a_digital[3]==1 && a_digital[4]==1){
  //10111
  error=2;
 }else if(a_digital[0]==0 && a_digital[1]==0 && a_digital[2]==1 && a_digital[3]==1 && a_digital[4]==1){
  error=3;
 }else if(a_digital[0]==0 && a_digital[1]==1 && a_digital[2]==1 && a_digital[3]==1 && a_digital[4]==1){
  error=4;
 }
  i=i+previous_error;
  d=error-previous_error;
  
  previous_error=error;
  
  pid_value=kp*error+ki*i + kd*d;

  speed_left=153-pid_value;
  speed_right=153+pid_value;

  analogWrite(3,speed_left);
  analogWrite(6,0);
  analogWrite(9,speed_right);
  analogWrite(10,0);
  
  
 
}
