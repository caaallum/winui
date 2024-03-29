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

#include <winui/stdafx.h>
#include <winui/components/component.h>
#include <winui/components/panel.h>
#include <sstream>

winui::Panel::Panel(util::Vector2i size, util::Vector2i position) :
	Component(size, position) {
}

void
winui::Panel::Draw(HWND hwndWindow) {
	for (const auto& c : m_components) {
		c->SetPosition(m_position + c->GetPosition());
		c->Draw(hwndWindow);
	}
}

void
winui::Panel::AddComponent(Component *component) {
	m_components.push_back(component);
}
