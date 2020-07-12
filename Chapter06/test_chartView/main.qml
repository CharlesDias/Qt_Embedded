import QtQuick 2.11
import QtQuick.Window 2.11
import QtCharts 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ChartView {
        id: line
        x: 109
        y: 65
        width: 300
        height: 300
        LineSeries {
            name: "LineSeries"
            XYPoint {
                x: 0
                y: 2
            }

            XYPoint {
                x: 1
                y: 1.2
            }

            XYPoint {
                x: 2
                y: 3.3
            }

            XYPoint {
                x: 5
                y: 2.1
            }
        }

        Text {
            id: element
            x: 63
            y: 74
            width: 24
            height: 171
            text: qsTr("Text")
            font.pixelSize: 12
        }
    }
}
