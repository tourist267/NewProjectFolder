#include "CreatFold.h"
using namespace std;

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


void CreatProject(void)
{
	int val;
	val = CreatFold(Hard);
	val = CreatFold(Soft);
	val = CreatFold(Instr);
	val = CreatFold(Ref);

	if (val) { cout << "项目文件夹创建成功" << endl; }
	else { cout << "项目文件夹创建失败" << endl; }
	
}
