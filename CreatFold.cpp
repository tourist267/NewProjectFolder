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
static void CreatFlie(string filename)
{
	ofstream outfile;
	/*�½��汾�޸ļ�¼�ļ�*/
	outfile.open(filename);
	
	if (filename.find(VESER_RECORD) != -1)
	{
		outfile << "V1.0 :" << endl;
		outfile << "V1.0->V1.1 :" << endl;
		outfile << "V1.1->V1.2 :" << endl;
	}
	else if (filename.find(REQUESTION) != -1)
	{
		outfile << "V1.0 :" << endl;
		outfile << "V1.1 :" << endl;
		outfile << "V1.2 :" << endl;
	}
	else if (filename.find(JOINPEOPLE) != -1) 
	{
		outfile << "��� : �ֺ���" << endl;
		outfile << "Ӳ�� : " << endl;
		outfile << "�ṹ :" << endl;
		outfile << "ҵ�� :" << endl;
	}
	else
	{
		;
	}

	outfile.close();
}



void CreatProject(string project, string INPUT_IC)
{
	int val;
	string name,IC,path;

	name = project;
	
	IC = ICChoose(INPUT_IC);

	/*������Ŀ���ļ���*/
	val = CreatFold(name);
	if (val)
	{
		/*����������Ա�������ļ�*/
		CreatFlie(name + "\\" + REQUESTION);
		CreatFlie(name + "\\" + JOINPEOPLE);

		val = CreatFold(name + "\\" + Hard);
		/*�����ڲ��ļ���*/
		if (val)
		{
			path = name + "\\" + Hard + "\\";
			CreatFold(path + "V1.0");
			CreatFold(path + "V1.1");
			CreatFold(path + "V1.2");
		}
		
		val = CreatFold(name + '\\' + Soft);
		if (val)
		{	/*�����ļ��кͰ汾��¼�ļ�*/
			//V1.0
			path = name + "\\" + Soft + "\\" + "V1.0" + "\\";
			CreatFold(path);
			CreatFold(path + name + "-" + "V1.0" + "-" + IC);
			CreatFlie(path + VESER_RECORD);
			//V1.1
			path = name + "\\" + Soft + "\\" + "V1.1" + "\\";
			CreatFold(path);
			CreatFold(path + name + "-" + "V1.1"+"-" + IC);
			CreatFlie(path + VESER_RECORD);
			//V1.2
			path = name + "\\" + Soft + "\\" + "V1.2" + "\\";
			CreatFold(path);
			CreatFold(path + name + "-" + "V1.2"+"-" + IC);
			CreatFlie(path + VESER_RECORD);
		}
		val = CreatFold(name + '\\' + Instr);
		val = CreatFold(name + '\\' + Ref);
	}
	
	if (val) { cout << "��Ŀ�ļ��д����ɹ�" << endl; }
	else { cout << "��Ŀ�ļ��д���ʧ��" << endl; }
	
}
