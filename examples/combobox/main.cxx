#include <winui.h>

winui::TextField text_field;
winui::ComboBox combo_box;

int
WINAPI 
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR pCmdLine, _In_ int nCmdShow)
{
	winui::Frame frame(hInstance, "ComboBox", winui::util::Vector2i(400, 250));

	combo_box = winui::ComboBox({ 300, 400 }, { 50, 110 });
	combo_box.Draw(frame.GetHandle());

	combo_box.AddOptions({ "Option 1", "Option 2" });

	text_field = winui::TextField({ 170, 25 }, { 10, 10 });
	text_field.Draw(frame.GetHandle());

	winui::Button add("Add", { 100, 25 }, { 190, 10 });
	add.AddEventListener([]() {
		combo_box.AddOption(text_field.GetValue());
		text_field.Clear();
		});
	add.Draw(frame.GetHandle());

	winui::Button del("Delete", { 100, 25 }, { 190, 40 });
	del.AddEventListener([]() {
		combo_box.RemoveOption(combo_box.GetSelectedIndex());
		});
	del.Draw(frame.GetHandle());

	winui::Button selected("Selected", { 100, 25 }, { 190, 70 });
	selected.AddEventListener([]() {
		MessageBox(0, combo_box.GetSelectedValue().c_str(), "Selected", MB_OK);
		});
	selected.Draw(frame.GetHandle());

	combo_box.AddOption("Option 3");

	frame.Show();
}