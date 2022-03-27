#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "parson.h"
#include "json.h"
/*초기 전압,전류,역률 등의 값은 고정된 값으로 fix*/


void init_Information_json(char* name)
{
	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_value_init_object();
	rootObject = json_value_get_object(rootValue);

	json_object_set_string(rootObject, "이름", name);
	json_object_set_number(rootObject, "누적전력량",100);
	json_object_set_number(rootObject, "주파수", 60);
	json_object_set_number(rootObject, "평균선간전압", 380);
	json_object_set_number(rootObject, "평균상전압", 220);
	json_object_set_number(rootObject, "평균전류", 10);
	json_object_set_number(rootObject, "온도", 50);
	json_object_set_number(rootObject, "평균역률", 99);
	json_object_set_number(rootObject, "평균유효전력", 80);
	json_object_set_number(rootObject, "평균무효전력", 60);
	json_object_set_number(rootObject, "ESS", 10);
	json_serialize_to_file_pretty(rootValue, "status.json");

	json_value_free(rootValue);

}

void reset_status_json()
{
	JSON_Value* rootValue;
	JSON_Object* rootObject;
	srand(time(NULL));
	rootValue = json_parse_file("status.json");
	rootObject = json_value_get_object(rootValue);

	//누적전력량
	double accumulated_power = json_object_get_number(rootObject, "누적전력량");
	accumulated_power += 5;
	//유효전력, 무효전력, 피상전력, 역률 순으로
	double real_power = json_object_get_number(rootObject, "평균유효전력");
	real_power = rand() % (100 - 90 + 1) + 90; //90~100kw 범위 랜덤
	
	double reactive_power = json_object_get_number(rootObject, "평균무효전력");
	reactive_power = rand() % (10 - 1 + 1) + 1;
	
	double apparent_Power = sqrt(pow(real_power, 2) + pow(reactive_power, 2));
	double power_factor = (real_power / apparent_Power) * 100;
	
	//ess 배터리 충전량
	double ess = json_object_get_number(rootObject, "ESS");
	const int add_charging_ess = rand() % (10 - 1 + 1) + 1;
	
	if ((ess + add_charging_ess) > 100) {
		ess = 100;
	}
	else {
		ess += add_charging_ess;
	}
	
	
	json_object_set_number(rootObject, "누적전력량", accumulated_power);
	json_object_set_number(rootObject, "평균선간전압", 380);
	json_object_set_number(rootObject, "평균상전압", 220);
	json_object_set_number(rootObject, "평균전류", 10);
	json_object_set_number(rootObject, "온도", 50);
	json_object_set_number(rootObject, "평균역률", power_factor);
	json_object_set_number(rootObject, "평균유효전력", real_power);
	json_object_set_number(rootObject, "평균무효전력", reactive_power);
	json_object_set_number(rootObject, "ESS", ess);
	
	json_serialize_to_file_pretty(rootValue, "status.json");

	json_value_free(rootValue);

}

void printStatus()
{
	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_parse_file("status.json");
	rootObject = json_value_get_object(rootValue);

	printf("이름 : %s\n", json_object_get_string(rootObject, "이름"));
	printf("누적전력량 : %.1f [kWh]\n", json_object_get_number(rootObject, "누적전력량"));
	printf("평균선간전압 : %.1f [kV]\n", json_object_get_number(rootObject, "평균선간전압"));
	printf("평균상전압 : %.1f [kV]\n", json_object_get_number(rootObject, "평균상전압"));
	printf("평균전류 : %.2f [mA]\n", json_object_get_number(rootObject, "평균전류"));
	printf("온도 : %.1f [도]\n", json_object_get_number(rootObject, "온도"));
	printf("평균역률 : %.2f [%%]\n", json_object_get_number(rootObject, "평균역률"));
	printf("평균유효전력 : %.1f [kw]\n", json_object_get_number(rootObject, "평균유효전력"));
	printf("평균무효전력 : %.1f [kvar]\n", json_object_get_number(rootObject, "평균무효전력"));
	printf("ESS : %.1f [%%]\n", json_object_get_number(rootObject, "ESS"));
}