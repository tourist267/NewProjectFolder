#include "CreatFold.h"


string Hard = "00.Ӳ�����";
string Soft = "01.������";
string Instr = "02.˵���ĵ�";
string Ref = "03.�ο�����";


static int  CreatFold(std::string name)
{
	int val;

	if (0 == _mkdir(name.c_str()))
	{
		val=_mkdir(name.c_str());
		cout << "�ļ���"+name+"�����ɹ�"  << endl;
	}
	else 
	{ 
		val = _mkdir(name.c_str());
		cout << "�ļ���" + name + "����ʧ��" << endl;
	}

	return val;
}
static int ICChoose(string IC)
{
	
}


void CreatProject(string project, string IC)
{
	int val;
	string name;

	name = project;
	/*������Ŀ���ļ���*/
	val = CreatFold(name);
	if (val)
	{
		val = CreatFold(name + "\\" + Hard);
		/*�����ڲ��ļ���*/
		if (val)
		{
				CreatFold(name + "\\" + Hard + "\\" + "V1.0");
				CreatFold(name + "\\" + Hard + "\\" + "V1.1");
				CreatFold(name + "\\" + Hard + "\\" + "V1.2");
		}
		
		
		val = CreatFold(name + '\\' + Soft);
		if (val)
		{
			CreatFold(name + "\\" + Soft + "\\" + "V1.0"+"-"+  IC);
			CreatFold(name + "\\" + Soft + "\\" + "V1.1"+"-" + IC);
			CreatFold(name + "\\" + Soft + "\\" + "V1.2"+"-" + IC);
		}
		val = CreatFold(name + '\\' + Instr);
		val = CreatFold(name + '\\' + Ref);
	}
	
	if (val) { cout << "��Ŀ�ļ��д����ɹ�" << endl; }
	else { cout << "��Ŀ�ļ��д���ʧ��" << endl; }
	
}
