#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdint.h>
#include <Adafruit_MLX90614.h> //사용된 라이브러리

#define trigPin 2                   // trigPin을 2으로 설정
#define echoPin 3                // echoPin을 3로 설정

#define IR1 0x5B    //적외선 온도센서 5도 i2c 주소값
#define IR2 0x5A    //적외선 온도센서 80도 i2c 주소값
 
#define OLED_RESET 12  //oled 리셋 핀 12
 
Adafruit_SSD1306 display(OLED_RESET);
Adafruit_MLX90614 mlx = Adafruit_MLX90614(); //mlx 적외선 온도센서 객체 생성
int limit = 30; //거리 제한

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
 
void setup()  
{               

    Serial.begin(9600);
  mlx.begin(); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  pinMode(trigPin, OUTPUT);   // trigPin 핀을 출력핀으로 설정합니다.

  pinMode(echoPin, INPUT);    // echoPin 핀을 입력핀으로 설정합니다.


}
 
 
void loop()
{     
  
  display.clearDisplay(); //디스플레이 버퍼 제거
  bool mode = false; //적외선 온도 측정 bool
 
    if(mode ==false){  //적외선 온도 측정 false
int a= 1;
if(a ==1){
 display.clearDisplay();      
 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(0,0);
 display.println("");
  display.display();
  a--;   
  }
  }

 if(choumpa() <= limit) {//초음파 센서 인식시 적외선 온도 측정  true

    unsigned long t = millis(); //스톱워치작동!
int a=1;
    while(1){
    mode = true;
    break;
    }

if(mode){ //온도측정 코드
        tone(4, 3520); //부저작동!
        delay(50);
         noTone(4); //부저멈춤!
  t= millis();
     while(1){
    if(millis() -t >5000){
      break;
    }
 display.clearDisplay();
 mlx.AddrSet(IR1);
 float Amitemp = mlx.readAmbientTempC();

// 온도 세부지정 시작 위치
if(Amitemp > 28){  
     mlx.AddrSet(IR1);
mlx.temp1 = mlx.readObjectTempC()*1;

delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = mlx.readObjectTempC()*1; 
}
else if(Amitemp> 26 && Amitemp <= 28){    
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1)*1;
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3)*1; 
  }
else if(mlx.readAmbientTempC() >24  && mlx.readAmbientTempC() <= 26){
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1.8)*1;//210216검증
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3.6)*1; 
  
}
else if(mlx.readAmbientTempC() >22  && mlx.readAmbientTempC() <= 24){
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1.8)*1.010;
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3.6)*1.010; 
  
}
else if(mlx.readAmbientTempC() >20  && mlx.readAmbientTempC() <= 22){
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1.8)*1.015;//210216검증
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3.6)*1.015;
  
}

else if(mlx.readAmbientTempC() >15  && mlx.readAmbientTempC() <= 20){
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1.8)*1.02;//210216검증
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3.6)*1.02;
  
} 

else if(mlx.readAmbientTempC() >10  && mlx.readAmbientTempC() <= 15){
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1.8)*1.05;
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3.6)*1.05;
  
} 

 
else if(mlx.readAmbientTempC() >5  && mlx.readAmbientTempC() <= 10){
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1.8)*1.1;
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3.6)*1.1;
  
} 
else if(mlx.readAmbientTempC() >0  && mlx.readAmbientTempC() <= 5){
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1.8)*1.125;
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3.6)*1.125;
  
} 
else if(mlx.readAmbientTempC() >-5  && mlx.readAmbientTempC() <=0){
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1.8)*1.13;
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3.6)*1.13;
  
}  
else if(mlx.readAmbientTempC() >-10  && mlx.readAmbientTempC() <=-5){
   mlx.AddrSet(IR1);
mlx.temp1 = (mlx.readObjectTempC()+1.8)*1.15;
delay(100);
  mlx.AddrSet(IR2);
mlx.temp2 = (mlx.readObjectTempC()+3.6)*1.15;
  
} 
//온도 세부지정 마지막 위치








if(mlx.temp1 > mlx.temp2){

    display.setTextSize(1);
  display.setTextColor(WHITE);
    display.setCursor(0,0);
 display.print(Amitemp);



    
    display.setTextSize(2);
  display.setTextColor(WHITE);
    display.setCursor(15,8);
 display.print(mlx.temp1);
  display.print(" c");
  display.display();      
}
else if(mlx.temp1 <= mlx.temp2){
    display.setTextSize(1);
  display.setTextColor(WHITE);
    display.setCursor(0,0);
 display.print(Amitemp);




    
    display.setTextSize(2);
  display.setTextColor(WHITE);
    display.setCursor(15,8);
 display.print(mlx.temp2);
  display.print(" c");
  display.display();     
  }
   Serial.print("*tObject1 = "); Serial.print(mlx.temp1); Serial.println("*C ");
  Serial.print("*tObject2 = "); Serial.print(mlx.temp2); Serial.println("*C\n");
    }

   }

 
  
}   
}
float choumpa(){ //초음파코드
  float duration = 0;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(trigPin);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = (pulseIn(echoPin, HIGH)/29.0)/2; //cm
  return duration;
}
