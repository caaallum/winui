#include <Windows.h>
#include <string>
#include <winui.h>

int
WINAPI 
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR pCmdLine, _In_ int nCmdShow)
{
	winui::Frame frame(hInstance, "Test", winui::util::Vector2i(800, 600));

	winui::Label label("Label", { 100, 100 }, { 10, 10 });
	label.Draw(frame.GetHandle());

	winui::Button button("Button", { 100, 20 }, { 50, 50 });
	button.AddEventListener([]() {
		MessageBox(NULL, "Button Pressed", "Alert", MB_ICONINFORMATION | MB_OK);
		});
	button.Draw(frame.GetHandle());


	winui::TextField textField({ 50, 20 }, { 100, 100 });
	textField.Draw(frame.GetHandle());

	frame.Show();
}