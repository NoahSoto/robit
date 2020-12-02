#include "Arduino.h"
//The setup function is called once at startup of the sketch



class CRobot{

private:

	String cadetName1;//Noah Soto
	String cadetName2; //Casey Owen

	String robotName; // Robot name: Alfonzo
	int robotSpeed;

public:

	CRobot(String name1, String name2, String robotName2, int robotSpeed2){

		cadetName1=name1;
		cadetName2=name2;
		robotName=robotName2;
		robotSpeed=robotSpeed2;
	}

	String getCadetNames(){

		return cadetName1 + " " + cadetName2;


	}
	String getRobotNames(){

		return robotName;

	}
	int getRobotSpeed(){

		return robotSpeed;

	}
	void displayInfo(){

		Lcd.init();
		Lcd.print(getCadetNames() + " " + getRobotNames());


	}
	void displayText(String text1, String text2){

		Lcd.init();
		Lcd.print(text1);
		Lcd.locate(1,0);
		Lcd.print(text2);
		delay(500);
		Lcd.clear();

	}
	int setSpeed(String speed){

		if(speed == "Fast"){

			robotSpeed=3;
			return 1;

		}else if(speed="Medium"){

			robotSpeed=2;
			return 1;

		}else if(speed){

			robotSpeed=1;
			return 1;

		}else{

			return 0;

		}


	}
	void forward(int seconds){

		//InitEmoro;

		EmoroServo.attach(SERVO_0); //starboard motor

		EmoroServo.attach(SERVO_4); //port motor

		int speed=getRobotSpeed();

		switch (speed){

			case 1:
				EmoroServo.write(SERVO_0,1600);

				EmoroServo.write(SERVO_4,1400);

				delay(1000);

				break;
			case 2:
				EmoroServo.write(SERVO_0,1700);

				EmoroServo.write(SERVO_4,1300);

				delay(1000);
			case 3:
				EmoroServo.write(SERVO_0,1700);

				EmoroServo.write(SERVO_4,1200);

				delay(1000);
			}

	}
	void stop(){

		EmoroServo.write(SERVO_0,1500);

		EmoroServo.write(SERVO_4,1500);

	}

	int turnRobot(char turn){

		switch(turn){

			case 'R':
				Gyr.resetDegrees();

				while (Gyr.readDegreesZ()<90){
					EmoroServo.write(SERVO_0, 1300); //stop stb motor

					EmoroServo.write(SERVO_4, 1300);
				}
				return 0;
				break;
		    case 'L':
		    	Gyr.resetDegrees();
		    	EmoroServo.write(SERVO_0, 1500); //stop stb motor

		    	EmoroServo.write(SERVO_4, 1500);

		    	delay(100);

		    	while (Gyr.readDegreesZ()>270){
		    		EmoroServo.write(SERVO_0, 1300); //stop stb motor
		    		EmoroServo.write(SERVO_4, 1300);
		    	}
		    	return 0;
		    	break;
		    case 'A':
		    	Gyr.resetDegrees();
		    	while (Gyr.readDegreesZ()<180){
		    		EmoroServo.write(SERVO_0, 1300); //stop stb motor

		    		EmoroServo.write(SERVO_4, 1300);
		    	}
		    	return 0;
		    	break;
		}

		return 1;
	}

	void forwardUntil(double inches){

		double cm;

		cm=inches * 2.54;

		int reading;

		while(reading < cm){

			reading=Ultrasonic.read(GPP_0);
			forward(1000);

		}
		stop();

	}


};




void setup()
{
// Add your initialization code here
	InitEmoro();
	Lcd.init();
	Ultrasonic.attach(GPP_0);
	Gyr.init();

	String cadet1="noah";
	String cadet2="casey";
	String robotname="Alfonzo";
	int robotSpeed=1;

	CRobot robot=CRobot(cadet1,cadet2,robotname,robotSpeed);
/*
	robot.displayInfo();
	robot.forward(2);
	robot.stop();
	robot.turnRobot('R');
	robot.turnRobot('L');
	robot.turnRobot('A');
	robot.displayText("hi", "santa");
	robot.forwardUntil(6.2);
*/
	robot.forward(4);

}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here


}
