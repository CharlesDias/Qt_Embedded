import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
//import QtQuick.VirtualKeyboard 2.1

// (1) We are defining a Window
Window {
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello from QML!")

    // (2) In the window, we have a column layout (QVerticalLayout in QWidgets)

    ColumnLayout {
        id: gridLayout
        width: 480
        height: 800
        rotation: 0            // the "id" we refer to the ColumnLayout by
        anchors.fill: parent      // fill the parent (the Window)

        // (3) The first row in the ColumnLayout is a Label called
        //  "greetings"
        Label {
            id: greetings
            text: qsTr("Hello from QML!")

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        // (4) The next row in the ColumnLayout is a RowLayout

        Image {
            id: image
            width: 100
            height: 100
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            source: "VIRTUS.png"
            fillMode: Image.PreserveAspectFit
        }

        RowLayout {
            // center this row vertically and horizontally
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            // (5) the leftmost item in the row is a label, "My Name
            //  is:"
            Label {
                id: nameLabel
                text: qsTr("My Name is:")

                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            }

            // (6) The next item in the row is a TextField referred to
            // by "nameField"
            TextField {
                id: nameField
                text: qsTr("")

                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter

                onAccepted: {
                    greetings.text = "Nice to meet you " + nameField.text + "!"
                }
            }
        }   // End of the RowLayout

        // (7) The next Row contains a Button, called "button" with
        // text "Enter Name"
        Button {
            id: button
            text: qsTr("Enter Name")

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            onClicked: {
                greetings.text = "Nice to meet you " + nameField.text +
                        "!"
            }
        }


    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
