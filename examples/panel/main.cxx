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
	winui::Window window(hInstance, "Panel", winui::util::Vector2i(800, 600));

	// Split window into 4 corners with panels
	winui::Panel top_left({ 400, 300 }, { 0, 0 });
	winui::Panel top_right({ 400, 300 }, { 400, 0 });
	winui::Panel bottom_left({ 400, 300 }, { 0, 300 });
	winui::Panel bottom_right({ 400, 300 }, { 400, 300 });

	// Add 4 identical labels to each panel
	winui::Label top_left_label("Top Left", { 100, 20 }, { 10, 10 });
	top_left.AddComponent(&top_left_label);

	winui::Label top_right_label("Top Right", { 100, 20 }, { 10, 10 });
	top_right.AddComponent(&top_right_label);

	winui::Label bottom_left_label("Bottom Left", { 100, 20 }, { 10, 10 });
	bottom_left.AddComponent(&bottom_left_label);

	winui::Label bottom_right_label("Bottom Right", { 100, 20 }, { 10, 10 });
	bottom_right.AddComponent(&bottom_right_label);

	// Draw each panel
	window.Draw(&top_left);
	window.Draw(&top_right);
	window.Draw(&bottom_left);
	window.Draw(&bottom_right);

	window.Show();
}