#pragma once

#include <Windows.h>
#include <string>

namespace Gravitum
{
	class Window
	{
	private:
		HWND			m_Id;
		int				m_Width;
		int				m_Height;
		std::string		m_Title;
		int				m_StartPosX;
		int				m_StartPosY;
		DWORD			m_Style;
		HCURSOR			m_Cursor;
		HICON			m_Icon;
		HBRUSH			m_BackgroundColor;

	public:
		Window();

		void Create();

	private:
		static LRESULT WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	};
}