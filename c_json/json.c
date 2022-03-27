#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "parson.h"
#include "json.h"
/*�ʱ� ����,����,���� ���� ���� ������ ������ fix*/


void init_Information_json(char* name)
{
	JSON_Value* rootValue;
	JSON_Object* rootObject;

	rootValue = json_value_init_object();
	rootObject = json_value_get_object(rootValue);

	json_object_set_string(rootObject, "�̸�", name);
	json_object_set_number(rootObject, "�������·�",100);
	json_object_set_number(rootObject, "���ļ�", 60);
	json_object_set_number(rootObject, "��ռ�������", 380);
	json_object_set_number(rootObject, "��ջ�����", 220);
	json_object_set_number(rootObject, "�������", 10);
	json_object_set_number(rootObject, "�µ�", 50);
	json_object_set_number(rootObject, "��տ���", 99);
	json_object_set_number(rootObject, "�����ȿ����", 80);
	json_object_set_number(rootObject, "��չ�ȿ����", 60);
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

	//�������·�
	double accumulated_power = json_object_get_number(rootObject, "�������·�");
	accumulated_power += 5;
	//��ȿ����, ��ȿ����, �ǻ�����, ���� ������
	double real_power = json_object_get_number(rootObject, "�����ȿ����");
	real_power = rand() % (100 - 90 + 1) + 90; //90~100kw ���� ����
	
	double reactive_power = json_object_get_number(rootObject, "��չ�ȿ����");
	reactive_power = rand() % (10 - 1 + 1) + 1;
	
	double apparent_Power = sqrt(pow(real_power, 2) + pow(reactive_power, 2));
	double power_factor = (real_power / apparent_Power) * 100;
	
	//ess ���͸� ������
	double ess = json_object_get_number(rootObject, "ESS");
	const int add_charging_ess = rand() % (10 - 1 + 1) + 1;
	
	if ((ess + add_charging_ess) > 100) {
		ess = 100;
	}
	else {
		ess += add_charging_ess;
	}
	
	
	json_object_set_number(rootObject, "�������·�", accumulated_power);
	json_object_set_number(rootObject, "��ռ�������", 380);
	json_object_set_number(rootObject, "��ջ�����", 220);
	json_object_set_number(rootObject, "�������", 10);
	json_object_set_number(rootObject, "�µ�", 50);
	json_object_set_number(rootObject, "��տ���", power_factor);
	json_object_set_number(rootObject, "�����ȿ����", real_power);
	json_object_set_number(rootObject, "��չ�ȿ����", reactive_power);
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

	printf("�̸� : %s\n", json_object_get_string(rootObject, "�̸�"));
	printf("�������·� : %.1f [kWh]\n", json_object_get_number(rootObject, "�������·�"));
	printf("��ռ������� : %.1f [kV]\n", json_object_get_number(rootObject, "��ռ�������"));
	printf("��ջ����� : %.1f [kV]\n", json_object_get_number(rootObject, "��ջ�����"));
	printf("������� : %.2f [mA]\n", json_object_get_number(rootObject, "�������"));
	printf("�µ� : %.1f [��]\n", json_object_get_number(rootObject, "�µ�"));
	printf("��տ��� : %.2f [%%]\n", json_object_get_number(rootObject, "��տ���"));
	printf("�����ȿ���� : %.1f [kw]\n", json_object_get_number(rootObject, "�����ȿ����"));
	printf("��չ�ȿ���� : %.1f [kvar]\n", json_object_get_number(rootObject, "��չ�ȿ����"));
	printf("ESS : %.1f [%%]\n", json_object_get_number(rootObject, "ESS"));
}