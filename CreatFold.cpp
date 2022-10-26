#include "CreatFold.h"

string Hard = "00.硬件设计";
string Soft = "01.软件设计";
string Instr = "02.说明文档";
string Ref = "03.参考代码";

static int  CreatFold(std::string name)
{
	int val;

	if (0 == _mkdir(name.c_str()))
	{
		val=_mkdir(name.c_str());
		cout << "文件夹"+name+"创建成功"  << endl;
	}
	else 
	{ 
		val = _mkdir(name.c_str());
		cout << "文件夹" + name + "创建失败" << endl;
	}

	return val;
}
string ICEN[] = {"SN8P2501","SN8P5702","SN8P5703","CMS8F2313","CMS8F6980","CMS8F6990","MC51F0003A4","CMS8F2892"\
,"CMS8F6790","SC92F8003"};
static string  ICChoose(string IC)
{
	int i,num,temp=0;
	/*获得IC数组个数*/
	num= sizeof(ICEN) / sizeof(ICEN[0]);
	/*遍历获取IC在IC数组的元素下标*/
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

	/*创建项目主文件夹*/
	val = CreatFold(name);
	if (val)
	{
		val = CreatFold(name + "\\" + Hard);
		/*建立内部文件夹*/
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
	
	if (val) { cout << "项目文件夹创建成功" << endl; }
	else { cout << "项目文件夹创建失败" << endl; }
	
}
