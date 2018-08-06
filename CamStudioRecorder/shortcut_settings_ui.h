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

#pragma once

#include <afxcmn.h>
#include "ui/listbox_grid_ui.h"

#include <vector>
#include <string>
#include <array>

class settings_model;

class shortcut_settings_ui : public CDialogEx
{
    DECLARE_DYNAMIC(shortcut_settings_ui)

public:
    shortcut_settings_ui(CWnd* pParent = nullptr);
    shortcut_settings_ui(CWnd* pParent, settings_model *settings);

    virtual ~shortcut_settings_ui();

    BOOL OnInitDialog() override;

// Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_SHORTCUTS_SETTINGS_UI };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()
public:
    listbox_grid shortcut_table_;
    settings_model *settings_;
    std::vector<std::array<std::wstring, 3>> shortcut_table_data_;
    CRichEditCtrl shortcut_edit_;
    afx_msg void OnEnMsgfilterRichedit(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg LRESULT OnUpdateShortcutTextMessage(WPARAM wParam, LPARAM lParams);

    std::wstring current_shortcut_;
};
