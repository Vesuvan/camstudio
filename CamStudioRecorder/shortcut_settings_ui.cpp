/**
 * Copyright(C) 2018  Steven Hoving
 *
 * This program is free software : you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include "stdafx.h"
#include "shortcut_settings_ui.h"
#include "afxdialogex.h"
#include "utility/make_array.h"

using namespace std::string_literals;

IMPLEMENT_DYNAMIC(shortcut_settings_ui, CDialogEx)

#define WM_UPDATE_SHORTCUT_TEXT_MESSAGE (WM_USER + 100)

shortcut_settings_ui::shortcut_settings_ui(CWnd* pParent /*=nullptr*/)
    : shortcut_settings_ui(pParent, nullptr)
{
}

shortcut_settings_ui::shortcut_settings_ui(CWnd* pParent, settings_model *settings)
    : CDialogEx(IDD_SHORTCUTS_SETTINGS_UI, pParent)
    , shortcut_table_()
    , settings_(settings)
{
}

shortcut_settings_ui::~shortcut_settings_ui()
{
}

BOOL shortcut_settings_ui::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    shortcut_edit_.SetEventMask(ENM_KEYEVENTS);

    shortcut_table_.set_text_callback(
        [this](int row, int col) -> const wchar_t *
        {
            // just failsafe for now
            if (row >= shortcut_table_data_.size())
                return nullptr;

            const auto &row_entry = shortcut_table_data_.at(row);
            if (col >= row_entry.size())
                return nullptr;

            return row_entry.at(col).c_str();
        }
    );

    shortcut_table_.add_column(L"Action", 200);
    shortcut_table_.add_column(L"Shortcut", 100);
    shortcut_table_.add_column(L"State", 100);

    shortcut_table_data_.emplace_back(make_array(L"Start/Pause recording"s, L"F8"s, L"Enabled"s));
    shortcut_table_data_.emplace_back(make_array(L"Stop recording"s, L"F9"s, L"Enabled"s));
    shortcut_table_data_.emplace_back(make_array(L"Cancel recording"s, L"F10"s, L"Enabled"s));
    shortcut_table_data_.emplace_back(make_array(L"Toggle zoom"s, L""s, L"Undefined"s));
    shortcut_table_data_.emplace_back(make_array(L"Toggle auto pan"s, L""s, L"Undefined"s));

    shortcut_table_.set_row_count(static_cast<int>(shortcut_table_data_.size()));

    return TRUE;
}

void shortcut_settings_ui::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_SHORTCUTS_TABLE, shortcut_table_);
    DDX_Control(pDX, IDC_RICHEDIT22, shortcut_edit_);
}

BEGIN_MESSAGE_MAP(shortcut_settings_ui, CDialogEx)
    ON_NOTIFY(EN_MSGFILTER, IDC_RICHEDIT22, &shortcut_settings_ui::OnEnMsgfilterRichedit)
    ON_MESSAGE(WM_UPDATE_SHORTCUT_TEXT_MESSAGE, &shortcut_settings_ui::OnUpdateShortcutTextMessage)
END_MESSAGE_MAP()

/* \todo code can be a lot better... */
void shortcut_settings_ui::OnEnMsgfilterRichedit(NMHDR *pNMHDR, LRESULT *pResult)
{
    MSGFILTER *pMsgFilter = reinterpret_cast<MSGFILTER *>(pNMHDR);

    if (pMsgFilter->msg != WM_KEYDOWN && pMsgFilter->msg != WM_SYSKEYDOWN)
    {
        *pResult = 0;
        return;
    }

    const auto virtual_key = pMsgFilter->wParam;
    bool ignore_key = false;
    switch(virtual_key)
    {
    case VK_CONTROL:
    case VK_LCONTROL:
    case VK_RCONTROL:
    case VK_SHIFT:
    case VK_LSHIFT:
    case VK_RSHIFT:
    case VK_MENU:
    case VK_LMENU:
    case VK_RMENU:
        ignore_key = true;
        break;
    }

    if (!ignore_key)
    {
        const auto control_key_state = (GetKeyState(VK_CONTROL) & 0x8000) != 0;
        const auto shift_key_state = (GetKeyState(VK_SHIFT) & 0x8000) != 0;
        const auto alt_key_state = HIWORD(pMsgFilter->lParam) & KF_ALTDOWN;

        std::wstring key_combo;
        if (control_key_state)
            key_combo += L"ctrl";
        if (shift_key_state)
            key_combo += L"+shift";
        if (alt_key_state)
            key_combo += L"+alt";

        bool is_alpha_numberic = (virtual_key >= '0' && virtual_key <= '9')
            || (virtual_key >= 'A' && virtual_key <= 'Z');

        bool is_function_key = virtual_key >= VK_F1 && virtual_key <= VK_F24;

        bool is_numpad = virtual_key >= VK_MULTIPLY && virtual_key <= VK_DIVIDE;

        bool is_space = virtual_key == VK_SPACE;

        if (is_alpha_numberic && !is_function_key)
        {
            if (!key_combo.empty()) key_combo += L"+";
            key_combo += static_cast<wchar_t>(tolower(static_cast<int>(virtual_key)));
        }
        else if (is_function_key)
        {
            constexpr auto function_key_names = make_array(L"F1",L"F2",L"F3",L"F4",L"F5",L"F6",
                L"F7",L"F8",L"F9",L"F10",L"F11",L"F12",L"F13",L"F14",L"F15",L"F16",L"F17",L"F18",L"F19",L"F20",L"F21",L"F22",L"F23",
                L"F24"
            );
            if (!key_combo.empty()) key_combo += L"+";
            key_combo += function_key_names.at(virtual_key - VK_F1);
        }
        else if (is_numpad)
        {
            constexpr auto function_key_names = make_array( L"*", L"+", L" ",L"-",L".",L"/");

            if (!key_combo.empty()) key_combo += L"+";
            key_combo += function_key_names.at(virtual_key - VK_MULTIPLY);
        }
        else if (is_space)
        {
            if (!key_combo.empty()) key_combo += L"+";
            key_combo += L"space";
        }

        current_shortcut_ = key_combo;

        PostMessage(WM_UPDATE_SHORTCUT_TEXT_MESSAGE);
    }

    *pResult = 1;
}

LRESULT shortcut_settings_ui::OnUpdateShortcutTextMessage(WPARAM wParam, LPARAM lParams)
{
    shortcut_edit_.SetWindowText(current_shortcut_.c_str());
    return 0;
}

