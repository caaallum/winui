#include <winui/stdafx.h>
#include <winui/util/vector2.h>
#include <winui/components/frame.h>

#include <winui/components/component.h>
#include <winui/components/button.h>

constexpr char* CLASS_NAME = "winuiApplication";

winui::Frame::Frame(HINSTANCE instance, const std::string &title, util::Vector2i size) :
	m_instance(instance),
    m_title(title),
	m_size(size),
    m_wc({0}),
	m_hwnd(0) {
	InitWindow();
}

HWND
winui::Frame::GetHandle() const {
	return m_hwnd;
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
	}
	return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void 
winui::Frame::InitWindow() {
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

	SetTimer(m_hwnd, 0, 100, (TIMERPROC)NULL);

	SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);
}

void
winui::Frame::Show() {
    ShowWindow(m_hwnd, 1);

	MSG msg = { 0 };
	while (GetMessage(&msg, 0, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}