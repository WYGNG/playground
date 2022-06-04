#include <Windows.h>

//窗口处理函数声明
LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//入口函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//做一个窗口

	//设计窗口类
	TCHAR szAppclassName[] = TEXT("WYG");

	WNDCLASS wc = { 0 };
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//加载白色画刷
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); //加载光标
	wc.hIcon = NULL;//加载图标
	wc.hInstance = hInstance;//应用程序实例句柄
	wc.lpfnWndProc = WindowProc;//窗口处理函数
	wc.lpszMenuName = szAppclassName;//窗口类型名
	wc.style = CS_HREDRAW | CS_VREDRAW;//窗口类的风格

	//注册窗口类
	RegisterClass(&wc);

	//创建窗口类
	HWND hWnd = CreateWindow(
		szAppclassName, // 窗口的类型名
		TEXT("WYG俄罗斯方块"),//窗口的标题
		WS_BORDER | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX, //窗口的风格
		500,100,//窗口左上角的坐标
		490,640,//窗口的宽和高
		NULL,//父窗口的句柄
		NULL,//菜单句柄
		hInstance,//应用程序实例句柄
		NULL//参数
		);

	//显示窗口类
	ShowWindow(hWnd, SW_SHOW);

	//更新窗口
	UpdateWindow(hWnd);

	//消息循环
	MSG  msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//将虚拟键消息转换为字符消息
		TranslateMessage(&msg);
		//将消息分发给窗口处理函数
		DispatchMessage(&msg);
	}



	return 0;
}

//窗口处理函数定义
LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE://窗口关闭消息
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY://窗口销毁消息
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
