#include "CreatFold.h"




int  CreatFold( string name)
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
