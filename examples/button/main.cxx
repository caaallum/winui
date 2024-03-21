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

int
WINAPI 
WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR pCmdLine, _In_ int nCmdShow)
{
	winui::Window window(hInstance, "Button", winui::util::Vector2i(800, 600));

	winui::Button button("Click me", { 100, 20 }, { 50, 50 });
	button.AddEventListener([]() {
		MessageBox(NULL, "Button Pressed", "Alert", MB_ICONINFORMATION | MB_OK);
    });
	window.Draw(&button);

	winui::Button button2("Click me", { 100, 20 }, { 150, 50 });
	button2.AddEventListener([]() {
		MessageBox(NULL, "Button2 Pressed", "Alert", MB_ICONINFORMATION | MB_OK);
		});
	window.Draw(&button2);

	window.Show();
}