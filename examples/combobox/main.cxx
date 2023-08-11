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

#include <winui.h>

winui::TextField text_field;
winui::ComboBox combo_box;

int
WINAPI 
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR pCmdLine, _In_ int nCmdShow)
{
	winui::Window window(hInstance, "ComboBox", winui::util::Vector2i(400, 250));

	combo_box = winui::ComboBox({ 300, 400 }, { 50, 110 });
	combo_box.Draw(window.GetHandle());

	combo_box.AddOptions({ "Option 1", "Option 2" });

	text_field = winui::TextField({ 170, 25 }, { 10, 10 });
	text_field.Draw(window.GetHandle());

	winui::Button add("Add", { 100, 25 }, { 190, 10 });
	add.AddEventListener([]() {
		combo_box.AddOption(text_field.GetValue());
		text_field.Clear();
		});
	add.Draw(window.GetHandle());

	winui::Button del("Delete", { 100, 25 }, { 190, 40 });
	del.AddEventListener([]() {
		combo_box.RemoveOption(combo_box.GetSelectedIndex());
		});
	del.Draw(window.GetHandle());

	winui::Button selected("Selected", { 100, 25 }, { 190, 70 });
	selected.AddEventListener([]() {
		MessageBox(0, combo_box.GetSelectedValue().c_str(), "Selected", MB_OK);
		});
	selected.Draw(window.GetHandle());

	combo_box.AddOption("Option 3");

	window.Show();
}