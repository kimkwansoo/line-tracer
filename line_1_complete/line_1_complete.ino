int IR_1 = A1;
int IR_2 = A2;
int IR_3 = A3;
int flag = 0;

int motor_A1 = 9;
int motor_A2 = 10;

int motor_B1 = 5;
int motor_B2 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);

  pinMode(motor_A1, OUTPUT);
  pinMode(motor_A2, OUTPUT);
  pinMode(motor_B1, OUTPUT);
  pinMode(motor_B2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int thresh = 600;
  
  int IR_1_data;
  int IR_2_data;
  int IR_3_data;
  IR_1_data = analogRead(IR_1); // 낮은게 검정
  IR_2_data = analogRead(IR_2);
  IR_3_data = analogRead(IR_3);

  //motor_con(100,100);
  //1 흰  0 검
  if(flag == 0 && IR_1_data > thresh && IR_2_data <= thresh && IR_3_data > thresh) // 101
  {
    motor_con(100,100);
    //flag = 0;
  }
  else if(flag == 0 && IR_1_data > thresh && IR_2_data <= thresh && IR_3_data <= thresh)//100
  {
    motor_con(30,100);  
    //flag = 1;
  }
  else if(flag == 0 && IR_1_data > thresh && IR_2_data > thresh && IR_3_data <= thresh)//110
  {
    motor_con(0, 100);
    //flag = 1;
  }
  else if(flag == 0 && IR_1_data <= thresh && IR_2_data <= thresh && IR_3_data > thresh)//001
  {
    motor_con(100,30);
    //flag = 2;
  }
  else if(flag == 0 && IR_1_data <= thresh && IR_2_data > thresh && IR_3_data > thresh)//011
  {
    motor_con(100,0);
    //flag = 2;
  }
  
/*
  else if(flag == 0 && IR_1_data > thresh && IR_2_data > thresh && IR_3_data > thresh)//111
  {
    motor_con(0,0);
  }  
  

    else if(flag == 1 && IR_1_data > thresh && IR_2_data > thresh && IR_3_data > thresh)//111
    {
      motor_con(150,10);
    }  
  
    else if(flag == 2 &&IR_1_data > thresh && IR_2_data > thresh && IR_3_data > thresh)//111
    {
      motor_con(10,150);
    }  
  */  
  

  Serial.print("data : ");
  Serial.print(IR_1_data);
  Serial.print(" ");
  Serial.print(IR_2_data);
  Serial.print(" ");
  Serial.print(IR_3_data);
  Serial.print("     flag : ");
  Serial.print(flag);
  Serial.println(" ");
}

void motor_con(int pwmA, int pwmB) {
  // MOTOR A direction
  if (pwmA > 0) {
    analogWrite(motor_A1, abs(pwmA));
    analogWrite(motor_A2, 0);
  } else if (pwmA < 0) {
    analogWrite(motor_A1, 0);
    analogWrite(motor_A2, abs(pwmA));
  } else {
    digitalWrite(motor_A1, LOW);
    digitalWrite(motor_A2, LOW);
  }

  // MOTOR B direction
  if (pwmB > 0) {
    analogWrite(motor_B1, abs(pwmB));
    analogWrite(motor_B2, 0);
  } else if (pwmB < 0) {
    analogWrite(motor_B1, 0);
    analogWrite(motor_B2, abs(pwmB));
  } else {
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, LOW);
  }

}
