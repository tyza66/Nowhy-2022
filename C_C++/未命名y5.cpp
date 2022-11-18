#include<stdio.h>
#include<windows.h>

int main()
{
DWORD pid=0;
int xue;
HWND ck = FindWindow(0,"Binding of Isaac: Afterbirth+");
GetWindowThreadProcessId(ck,&pid);
printf("%d",pid);
HANDLE qx=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
printf("请输入要修改的血量");
scanf("%d",&xue);
WriteProcessMemory(qx,(LPVOID)0x11E4D500,(LPVOID)xue,sizeof(xue),0);
return 0;
}