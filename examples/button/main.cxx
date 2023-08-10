#include <winui.h>

int
WINAPI 
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR pCmdLine, _In_ int nCmdShow)
{
	winui::Frame frame(hInstance, "Button", winui::util::Vector2i(800, 600));

	winui::Button button("Click me", { 100, 20 }, { 50, 50 });
	button.AddEventListener([]() {
		MessageBox(NULL, "Button Pressed", "Alert", MB_ICONINFORMATION | MB_OK);
    });
	button.Draw(frame.GetHandle());

	frame.Show();
}