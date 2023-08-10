#include <winui.h>

int
WINAPI 
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR pCmdLine, _In_ int nCmdShow)
{
	winui::Frame frame(hInstance, "Label", winui::util::Vector2i(800, 600));

	winui::Label label("Text", { 100, 20 }, { 50, 50 });
	label.Draw(frame.GetHandle());

	frame.Show();
}