#include "CreatFold.h"




int  CreatFold( string name)
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
