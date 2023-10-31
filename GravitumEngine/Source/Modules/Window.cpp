#include "Window.h"

#include <assert.h>

namespace Gravitum
{
	Window::Window()
	{
		m_Id = NULL;
		m_Width = 1366;
		m_Height = 768;
		m_Title = "Simulation Window";
		m_StartPosX = 0;
		m_StartPosY = 0;
		m_Style = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
		m_Cursor = NULL;
		m_Icon = NULL;
		m_BackgroundColor = CreateSolidBrush(RGB(0, 0, 0));
	}

	void Window::Create()
	{
		WNDCLASS wndClass = { 0 };
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.lpfnWndProc = Window::WinProc;
		wndClass.lpszClassName = "SimulationWindowClass";
		wndClass.hbrBackground = m_BackgroundColor;
		wndClass.hCursor = m_Cursor;
		wndClass.hIcon = m_Icon;
		wndClass.hInstance = GetModuleHandle(NULL);
		wndClass.lpszMenuName = NULL;
		wndClass.style = CS_OWNDC;

		int code = RegisterClass(&wndClass);
		assert(code);

		m_Id = CreateWindow(
			wndClass.lpszClassName,
			m_Title.c_str(),
			m_Style,
			m_StartPosX,
			m_StartPosY,
			m_Width,
			m_Height,
			NULL,
			NULL,
			GetModuleHandle(NULL),
			NULL
		);

		assert(m_Id);

		RECT winRect = { 0, 0, m_Width, m_Height };
		AdjustWindowRect(&winRect, m_Style, FALSE);

		m_StartPosX = (GetSystemMetrics(SM_CXSCREEN) / 2.0f) - ((winRect.right - winRect.left) / 2.0f);
		m_StartPosY = (GetSystemMetrics(SM_CYSCREEN) / 2.0f) - ((winRect.bottom - winRect.top) / 2.0f);

		MoveWindow(m_Id, m_StartPosX, m_StartPosY, winRect.right - winRect.left, winRect.bottom - winRect.top, TRUE);

		ShowWindow(m_Id, SW_SHOW);
	}

	LRESULT Window::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}

		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}