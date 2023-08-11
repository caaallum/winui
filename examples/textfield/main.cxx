#include <winui.h>

int
WINAPI 
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR pCmdLine, _In_ int nCmdShow)
{
	winui::Window window(hInstance, "TextField", winui::util::Vector2i(800, 600));

	winui::TextField text_field({ 100, 20 }, { 50, 50 });
	text_field.Draw(window.GetHandle());

	window.Show();
}