/**********************************************************
 * This file is part of winui.
 *
 * winui is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License
 * as published by the Free SoftwareFoundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * winui is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with winui. If not, see <https://www.gnu.org/licenses/>.
 **********************************************************/

#include <winui/stdafx.h>
#include <winui/util/vector2.h>
#include <winui/components/component.h>
#include <winui/components/window.h>

#include <winui/components/component.h>
#include <winui/components/button.h>
#include <winui/components/combobox.h>
#include <winui/components/checkbox.h>

constexpr char* CLASS_NAME = "winuiApplication";

winui::Window::Window(HINSTANCE instance, const std::string &title, util::Vector2i size) :
	m_instance(instance),
    m_title(title),
	m_size(size),
    m_wc({0}),
	m_hwnd(0) {
	InitWindow();
}

HWND
winui::Window::GetHandle() const {
	return m_hwnd;
}

winui::util::Vector2i 
winui::Window::GetSize() const {
	return m_size;
}

void
winui::Window::Draw(winui::Component *c) {
	c->Draw(m_hwnd);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
	{
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);
    }
    return 0;

	case WM_COMMAND:
	{
		winui::Component* com = (winui::Component*)GetWindowLongPtr((HWND)lParam, GWLP_USERDATA);

		if (winui::Button* button = dynamic_cast<winui::Button*>(com)) {
			if (button->m_event_listener) {
				button->m_event_listener();
			}
		}

		if (HIWORD(wParam) == CBN_SELCHANGE) {
			if (winui::ComboBox* comboBox = dynamic_cast<winui::ComboBox*>(com)) {
				if (comboBox->m_event_listener) {
					comboBox->m_event_listener();
				}
			}
		}

		if (HIWORD(wParam) == BN_CLICKED) {
			if (winui::CheckBox* checkBox = dynamic_cast<winui::CheckBox*>(com)) {
				if (checkBox->m_event_listener) {
					checkBox->m_event_listener();
				}
			}
		}
	}
	return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void 
winui::Window::InitWindow() {
	m_wc = { 0 };

	m_wc.cbSize = sizeof(m_wc);
	m_wc.lpszClassName = CLASS_NAME;
	m_wc.hInstance = m_instance;
	m_wc.lpfnWndProc = WindowProc;

	m_wc.style = CS_HREDRAW | CS_VREDRAW;
	m_wc.cbClsExtra = 0;
	m_wc.cbWndExtra = sizeof(long);
	m_wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	m_wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	m_wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	m_wc.lpszMenuName = NULL;

	RegisterClassEx(&m_wc);

	OUTPUT_LAST_ERROR

	m_hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		m_title.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		m_size.x, m_size.y,
		NULL,
		NULL,
		m_instance,
		NULL
	);

	OUTPUT_LAST_ERROR

	SetTimer(m_hwnd, 0, 100, (TIMERPROC)NULL);

	SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);
}

void
winui::Window::Show() {
    ShowWindow(m_hwnd, 1);

	MSG msg = { 0 };
	while (GetMessage(&msg, 0, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}