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
string ICEN[] = {"SN8P2501","SN8P5702","SN8P5703","CMS8F2313","CMS8F6980","CMS8F6990","MC51F0003A4","CMS8F2892"\
,"CMS8F6790","SC92F8003"};
static string  ICChoose(string IC)
{
	int i,num,temp=0;
	/*���IC�������*/
	num= sizeof(ICEN) / sizeof(ICEN[0]);
	/*������ȡIC��IC�����Ԫ���±�*/
	for (i = 0; i <=num; i++)
	{
		if (-1 == ICEN[i].find(IC)){temp++;}
		else { break; }
	}
	 return ICEN[temp]; 
}


void CreatProject(string project, string INPUT_IC)
{
	int val;
	string name,IC;

	name = project;
	
	IC = ICChoose(INPUT_IC);

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
			CreatFold(name + "\\" + Soft + "\\" + name +"-"+ "V1.0"+"-"+  IC);
			CreatFold(name + "\\" + Soft + "\\" + name + "-" + "V1.1"+"-" + IC);
			CreatFold(name + "\\" + Soft + "\\" + name + "-" + "V1.2"+"-" + IC);
		}
		val = CreatFold(name + '\\' + Instr);
		val = CreatFold(name + '\\' + Ref);
	}
	
	if (val) { cout << "��Ŀ�ļ��д����ɹ�" << endl; }
	else { cout << "��Ŀ�ļ��д���ʧ��" << endl; }
	
}
