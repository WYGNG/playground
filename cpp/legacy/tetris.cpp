#include <Windows.h>

//���ڴ���������
LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//��ں���
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//��һ������

	//��ƴ�����
	TCHAR szAppclassName[] = TEXT("WYG");

	WNDCLASS wc = { 0 };
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//���ذ�ɫ��ˢ
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); //���ع��
	wc.hIcon = NULL;//����ͼ��
	wc.hInstance = hInstance;//Ӧ�ó���ʵ�����
	wc.lpfnWndProc = WindowProc;//���ڴ�����
	wc.lpszMenuName = szAppclassName;//����������
	wc.style = CS_HREDRAW | CS_VREDRAW;//������ķ��

	//ע�ᴰ����
	RegisterClass(&wc);

	//����������
	HWND hWnd = CreateWindow(
		szAppclassName, // ���ڵ�������
		TEXT("WYG����˹����"),//���ڵı���
		WS_BORDER | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX, //���ڵķ��
		500,100,//�������Ͻǵ�����
		490,640,//���ڵĿ�͸�
		NULL,//�����ڵľ��
		NULL,//�˵����
		hInstance,//Ӧ�ó���ʵ�����
		NULL//����
		);

	//��ʾ������
	ShowWindow(hWnd, SW_SHOW);

	//���´���
	UpdateWindow(hWnd);

	//��Ϣѭ��
	MSG  msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//���������Ϣת��Ϊ�ַ���Ϣ
		TranslateMessage(&msg);
		//����Ϣ�ַ������ڴ�����
		DispatchMessage(&msg);
	}



	return 0;
}

//���ڴ���������
LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE://���ڹر���Ϣ
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY://����������Ϣ
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
