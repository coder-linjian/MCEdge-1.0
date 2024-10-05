#include<windows.h>
#include<tchar.h>

#pragma comment(lib,"winmm.lib")
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
using namespace std;
VOID WINAPI sound1(){
	HWAVEOUT hWaveOut=0;
	WAVEFORMATEX wfx={WAVE_FORMAT_PCM,1,8000,8000,1,8,0};
	waveOutOpen(&hWaveOut,WAVE_MAPPER,&wfx,0,0,CALLBACK_NULL);
	char buffer[8000*15]={0};
	for(DWORD t=0;t<sizeof(buffer);++t){
		buffer[t]=static_cast<char>(t*((t>>12|t>>8)&63&t>>4));
	}
	WAVEHDR header={buffer,sizeof(buffer),0,0,0,0,0,0};
	waveOutPrepareHeader(hWaveOut,&header,sizeof(WAVEHDR));
	waveOutWrite(hWaveOut,&header,sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut,&header,sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound2(){
	HWAVEOUT hWaveOut=0;
	WAVEFORMATEX wfx={WAVE_FORMAT_PCM,1,8000,8000,1,8,0};
	waveOutOpen(&hWaveOut,WAVE_MAPPER,&wfx,0,0,CALLBACK_NULL);
	char buffer[8000*15]={0};
	for(DWORD t=0;t<sizeof(buffer);++t){
		buffer[t]=static_cast<char>(t*(t>>11&t>>8&123&t>>3));
	}
	WAVEHDR header={buffer,sizeof(buffer),0,0,0,0,0,0};
	waveOutPrepareHeader(hWaveOut,&header,sizeof(WAVEHDR));
	waveOutWrite(hWaveOut,&header,sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut,&header,sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound3(){
	HWAVEOUT hWaveOut=0;
	WAVEFORMATEX wfx={WAVE_FORMAT_PCM,1,8000,8000,1,8,0};
	waveOutOpen(&hWaveOut,WAVE_MAPPER,&wfx,0,0,CALLBACK_NULL);
	char buffer[8000*20]={0};
	for(DWORD t=0;t<sizeof(buffer);++t){
		buffer[t]=static_cast<char>(t*((t>>12|t>>8)&63&t>>4));
	}
	WAVEHDR header={buffer,sizeof(buffer),0,0,0,0,0,0};
	waveOutPrepareHeader(hWaveOut,&header,sizeof(WAVEHDR));
	waveOutWrite(hWaveOut,&header,sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut,&header,sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
DWORD WINAPI DrawShellIcon(LPVOID lparam){
	POINT point;
	HINSTANCE hShell32 = LoadLibrary(_T("shell32.dll"));
	//for (int i = 0; i < 256; ++i)
	//{
	//	hIcons[i] = LoadIcon(hShell32, MAKEINTRESOURCE(i));
	//}
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	while (1) {
		GetCursorPos(&point);
		DrawIcon(hdc,point.x+10,point.y+10,LoadIcon(hShell32,MAKEINTRESOURCE(rand()%256-1)));
		//Sleep(10);
	}
}
DWORD WINAPI DrawText(LPVOID lparam){
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetDC(NULL);
	int cx=GetSystemMetrics(SM_CXFULLSCREEN);
	int cy=GetSystemMetrics(SM_CYFULLSCREEN);
	//char text[100][50]={"MCEdge:Distorying...","HAHAHA","Code by Coder LinJian"};
	SetBkMode(hdc, TRANSPARENT);
	while (1) {
		SetTextColor(hdc, RGB(rand()%256-1,rand()%256-1,rand()%256-1));
		int ret=rand()%3;
		switch(ret){
		case 0:
			TextOut(hdc, rand()%cx,rand()%cy,"MCEdge:Destroying...", strlen("MCEdge:Destorying..."));
			break;
			 
		
		case 1:
			TextOut(hdc, rand()%cx,rand()%cy,"HAHAHA", strlen("HAHAHA"));
			break;
			 
		case 2:
			TextOut(hdc, rand()%cx,rand()%cy,"By Coder LinJian", strlen("By Coder LinJian"));
			break;
			 
		}
		//TextOut(hdc, rand()%cx,rand()%cy,text[rand()%3], strlen(text[rand()%3]));
		Sleep(100);
	}
}
DWORD WINAPI MENZTunnels(LPVOID lparam){
	
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	RECT rect;
	GetWindowRect(hwnd,&rect);
	while (1) {
		StretchBlt(hdc,rect.left+10,rect.top+10,rect.right-20,rect.bottom-20,hdc,rect.left,rect.top,rect.right,rect.bottom,SRCCOPY);
		Sleep(100);
	}
}
DWORD WINAPI Lines(LPVOID lparam){
	int cx=GetSystemMetrics(SM_CXFULLSCREEN);
	int cy=GetSystemMetrics(SM_CYFULLSCREEN);
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	MoveToEx(hdc,rand()%cx,rand()%cy,NULL);
	while (1) {
		HPEN hPen=CreatePen(PS_SOLID,10,RGB(rand()%255,rand()%255,rand()%255));
		SelectObject(hdc,hPen);
		LineTo(hdc,rand()%cx,rand()%cy);
		//Sleep(100);
	}
}
DWORD WINAPI Rectangles(LPVOID lparam){
	int cx=GetSystemMetrics(SM_CXSCREEN);
	int cy=GetSystemMetrics(SM_CYSCREEN);
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	while (1) {
		COLORREF color=RGB(rand()%255,rand()%255,rand()%255);
		HPEN hPen=CreatePen(PS_SOLID,1,color);
		HBRUSH hBrush=CreateSolidBrush(color);
		SelectObject(hdc,hPen);
		SelectObject(hdc,hBrush);
		Rectangle(hdc,0,0,cx,cy);
		Sleep(100);
	}
}
DWORD WINAPI ScreenFanSe(LPVOID lparam){
	
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	RECT rect;
	GetWindowRect(hwnd,&rect);
	while (1) {
		BitBlt(hdc,0,0,rect.right,rect.bottom,hdc,0,0,3342348);
		Sleep(100);
	}
}
DWORD WINAPI HuaPing(LPVOID lparam){
	int cx=GetSystemMetrics(SM_CXSCREEN);
	int cy=GetSystemMetrics(SM_CYSCREEN);
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	while (1) {
		for (int i=0;i<cy;i++){
			for (int j=0;j<cx;j++){
				SetPixel(hdc,j,i,RGB(rand()%255,rand()%255,rand()%255)); 
			}
		}
	}
}
int main(){
	srand(time(NULL));
	MessageBox(NULL,"Hey,I am MCEdge.I will DESTROY your computer.\nEnjoy This!:D","MCEdge.exe",MB_OK|MB_ICONSTOP);
	sound1();
	HANDLE thread1=CreateThread(NULL,0,DrawShellIcon,NULL,0,NULL);
	HANDLE thread2=CreateThread(NULL,0,DrawText,NULL,0,NULL);
	HANDLE thread3=CreateThread(NULL,0,MENZTunnels,NULL,0,NULL);
	Sleep(15000);
	//TerminateThread(thread1,0);
	TerminateThread(thread2,0);
	TerminateThread(thread3,0);
	sound2();
	HANDLE thread4=CreateThread(NULL,0,Lines,NULL,0,NULL);
	HANDLE thread5=CreateThread(NULL,0,Rectangles,NULL,0,NULL);
	Sleep(15000);
	TerminateThread(thread1,0);
	TerminateThread(thread4,0);
	TerminateThread(thread5,0);
	sound3();
	HANDLE thread6=CreateThread(NULL,0,HuaPing,NULL,0,NULL);
	HANDLE thread7=CreateThread(NULL,0,ScreenFanSe,NULL,0,NULL);
	Sleep(20000);
	TerminateThread(thread6,0);
	TerminateThread(thread7,0);
	return 0;
}
