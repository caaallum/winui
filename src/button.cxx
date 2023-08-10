#include <winui/stdafx.h>
#include <winui/components/component.h>
#include <winui/components/button.h>

#include <winui/components/frame.h>

LRESULT 
CALLBACK ButtonProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (uMsg == WM_LBUTTONDOWN) {
		OutputDebugString("Clicked\n");
	}

	return CallWindowProc(winui::WindowProc, hwnd, uMsg, wParam, lParam);
}

winui::Button::Button(const std::string& title) :
	m_title(title),
	Component({ 100, 20 }, { 0, 0 }) {
	
}

winui::Button::Button(const std::string& title, util::Vector2i size, util::Vector2i position) :
	m_title(title),
	Component(size, position) {
}

void
winui::Button::SetTitle(const std::string& title) {
	m_title = title;

	if (m_hwnd) {
		SetWindowText(m_hwnd, title.c_str());
	}
}

std::string
winui::Button::GetTitle() const {
	return m_title;
}

void 
winui::Button::Draw(HWND hwndFrame) {
	m_hwnd = CreateWindow(
		"BUTTON",
		m_title.c_str(),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD | BS_PUSHBUTTON,
		m_position.x, m_position.y,
		m_size.x, m_size.y,
		hwndFrame,
		NULL,
		HINST_THISCOMPONENT,
		NULL
	);

	//SetWindowLongPtr(m_hwnd, GWLP_WNDPROC, (LONG_PTR)&ButtonProc);
	//SetWindowLongPtr(hwndFrame, GWLP_USERDATA, (LONG_PTR)this);
}