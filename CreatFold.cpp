#include "CreatFold.h"
using namespace std;

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


void CreatProject(void)
{
	int val;
	val = CreatFold(Hard);
	val = CreatFold(Soft);
	val = CreatFold(Instr);
	val = CreatFold(Ref);

	if (val) { cout << "��Ŀ�ļ��д����ɹ�" << endl; }
	else { cout << "��Ŀ�ļ��д���ʧ��" << endl; }
	
}
