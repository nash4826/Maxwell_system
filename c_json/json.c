#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "parson.h"
#include "json.h"
/*�ʱ� ����,����,���� ���� ���� ������ ������ fix*/

void init_Information_json(char *name)
{
	JSON_Value *rootValue;
	JSON_Object *rootObject;

	rootValue = json_value_init_object();
	rootObject = json_value_get_object(rootValue);

	json_object_set_string(rootObject, "name", name);
	json_object_set_number(rootObject, "accumulated_power", 100);
	json_object_set_number(rootObject, "frequency", 60);
	json_object_set_number(rootObject, "line_voltage", 380);
	json_object_set_number(rootObject, "phase_voltage", 220);
	json_object_set_number(rootObject, "average_current", 10);
	json_object_set_number(rootObject, "temperature", 50);
	json_object_set_number(rootObject, "power_factor", 99);
	json_object_set_number(rootObject, "real_power", 80);
	json_object_set_number(rootObject, "reactive_power", 60);
	json_object_set_number(rootObject, "ESS", 10);
	json_serialize_to_file_pretty(rootValue, "status.json");

	json_value_free(rootValue);
}

void reset_status_json()
{
	JSON_Value *rootValue;
	JSON_Object *rootObject;
	srand(time(NULL));
	rootValue = json_parse_file("status.json");
	rootObject = json_value_get_object(rootValue);

	//�������·�
	double accumulated_power = json_object_get_number(rootObject, "accumulated_power");
	accumulated_power += 5;
	//��ȿ����, ��ȿ����, �ǻ�����, ���� ������
	double real_power = json_object_get_number(rootObject, "real_power");
	real_power = rand() % (100 - 90 + 1) + 90; // 90~100kw ���� ����

	double reactive_power = json_object_get_number(rootObject, "reactive_power");
	reactive_power = rand() % (10 - 1 + 1) + 1;

	double apparent_Power = sqrt(pow(real_power, 2) + pow(reactive_power, 2));
	double power_factor = (real_power / apparent_Power) * 100;

	// ess ���͸� ������
	double ess = json_object_get_number(rootObject, "ESS");
	const int add_charging_ess = rand() % (10 - 1 + 1) + 1;

	if ((ess + add_charging_ess) > 100)
	{
		ess = 100;
	}
	else
	{
		ess += add_charging_ess;
	}

	json_object_set_number(rootObject, "accumulated_power", accumulated_power);
	json_object_set_number(rootObject, "line_voltage", 380);
	json_object_set_number(rootObject, "phase_voltage", 220);
	json_object_set_number(rootObject, "average_current", 10);
	json_object_set_number(rootObject, "temperature", 50);
	json_object_set_number(rootObject, "power_factor", power_factor);
	json_object_set_number(rootObject, "real_power", real_power);
	json_object_set_number(rootObject, "reactive_power", reactive_power);
	json_object_set_number(rootObject, "ESS", ess);

	json_serialize_to_file_pretty(rootValue, "status.json");

	json_value_free(rootValue);
}

void printStatus()
{
	JSON_Value *rootValue;
	JSON_Object *rootObject;

	rootValue = json_parse_file("status.json");
	rootObject = json_value_get_object(rootValue);

	printf("name : %s\n", json_object_get_string(rootObject, "name"));
	printf("�������·� : %.1f [kWh]\n", json_object_get_number(rootObject, "accumulated_power"));
	printf("��ռ������� : %.1f [kV]\n", json_object_get_number(rootObject, "line_voltage"));
	printf("��ջ����� : %.1f [kV]\n", json_object_get_number(rootObject, "phase_voltage"));
	printf("������� : %.2f [mA]\n", json_object_get_number(rootObject, "average_current"));
	printf("�µ� : %.1f [��]\n", json_object_get_number(rootObject, "temperature"));
	printf("��տ��� : %.2f [%%]\n", json_object_get_number(rootObject, "power_factor"));
	printf("�����ȿ���� : %.1f [kw]\n", json_object_get_number(rootObject, "real_power"));
	printf("��չ�ȿ���� : %.1f [kvar]\n", json_object_get_number(rootObject, "reactive_power"));
	printf("ESS : %.1f [%%]\n", json_object_get_number(rootObject, "ESS"));
}
