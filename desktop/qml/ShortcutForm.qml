/* Copyright (C) 2024 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

GridLayout {
    id: root

    property int indends: 0
    property bool verticalMode: parent.verticalMode !== undefined ? parent.verticalMode :
                                parent.parent.verticalMode !== undefined ? parent.parent.verticalMode :
                                parent.parent.parent.verticalMode !== undefined ? parent.parent.parent.verticalMode :
                                false
    property alias label: _label.text
    property alias text: _textField.text
    property bool compact: true
    property bool scanning: false
    signal resetClicked()

    columns: verticalMode ? 1 : 4
    columnSpacing: appWin.padding
    rowSpacing: appWin.padding
    Layout.fillWidth: true

    Label {
        id: _label

        Layout.fillWidth: true
        Layout.leftMargin: root.indends * appWin.padding
    }

    TextField {
        id: _textField

        enabled: !root.scanning
        Layout.fillWidth: root.verticalMode
        Layout.preferredWidth: root.verticalMode ? 0 : ((parent.width / 2) - (_scanButton.width + _resetButton.width + 2 * root.columnSpacing))
        Layout.leftMargin: root.verticalMode ? (root.indends + 1) * appWin.padding : 0
        color: palette.text

        TextContextMenu {}
    }

    RowLayout {
        id: buttonRow

        Layout.leftMargin: root.verticalMode ? (root.indends + 1) * appWin.padding : 0

        Button {
            id: _scanButton

            text: root.scanning ? qsTr("Press a special key...") :  qsTr("Detect special key")
            icon.name: "help-keybord-shortcuts-symbolic"
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.visible: display === AbstractButton.IconOnly ? hovered : false
            display: root.scanning || root.verticalMode ? AbstractButton.TextBesideIcon : AbstractButton.IconOnly
            ToolTip.text: qsTr("Detect special key presses (multimedia keys)")
            hoverEnabled: true
            onClicked: root.scanning = !root.scanning
            onFocusChanged: {
                if (!focus) root.scanning = false
            }

            Keys.onPressed: {
                if (!root.scanning) return

                root.scanning = false

                if (event.modifiers !== 0) return

                var key_name = app.special_key_name(event.key)
                if (key_name.length > 0) {
                    _textField.text = key_name
                }
            }
        }

        Button {
            id: _resetButton

            text: qsTr("Reset")
            icon.name: "edit-reset-symbolic"
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.visible: display === AbstractButton.IconOnly ? hovered : false
            display: root.verticalMode ? AbstractButton.TextBesideIcon : AbstractButton.IconOnly
            ToolTip.text: text
            hoverEnabled: true
            enabled: !root.scanning
            onClicked: root.resetClicked()
        }
    }
}
