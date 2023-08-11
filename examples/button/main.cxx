#include <winui.h>

int
WINAPI 
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR pCmdLine, _In_ int nCmdShow)
{
	winui::Window window(hInstance, "Button", winui::util::Vector2i(800, 600));

	winui::Button button("Click me", { 100, 20 }, { 50, 50 });
	button.AddEventListener([]() {
		MessageBox(NULL, "Button Pressed", "Alert", MB_ICONINFORMATION | MB_OK);
    });
	button.Draw(window.GetHandle());

	winui::Button button2("Click me", { 100, 20 }, { 150, 50 });
	button2.AddEventListener([]() {
		MessageBox(NULL, "Button2 Pressed", "Alert", MB_ICONINFORMATION | MB_OK);
		});
	button2.Draw(window.GetHandle());

	window.Show();
}