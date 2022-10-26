
#include "CreatFold.h"
#include <iostream>

#include <sys/types.h>
#include <direct.h>
using namespace std;
int main()
{
    char project[20],IC[10];
    /*获取项目名称*/
    cout << "输入项目型号:" <<endl;
    cin.getline(project, 20);
    cout << "输入主控IC:" << endl;
    cin.getline(IC, 20);


    CreatProject(project,IC);
  
 
}


