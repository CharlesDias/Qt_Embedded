import QtQuick 2.11
import QtCharts 2.0

ChartView {
    height: 480
    width: 800
    antialiasing: true
    legend.font.pixelSize: 15
    legend.visible: false;

    title: "Temperature History"
    theme: ChartView.ChartThemeQt
    titleFont: Qt.font({pixelSize: 15})

    LineSeries {
        id: temperatureSeries
        name: "Temperature"
        pointLabelsFont: Qt.font({pixelSize: 15}) // Não funcionou

        axisX: timeAxis
        axisY: temperatureAxis
    }

    ValueAxis {
        id: timeAxis
        labelsFont:Qt.font({pixelSize: 15})
    }

    ValueAxis {
        id: temperatureAxis
        min: 20
        max: 30
        labelsFont:Qt.font({pixelSize: 15})
    }

    Connections {
        target: temperatureData
        onNewReading: {
            if (temperatureSeries.count > 60)
                temperatureSeries.remove(0);
            temperatureSeries.append(temperatureData.lastReading.x, temperatureData.lastReading.y)

            // adjust time axis
            timeAxis.min = temperatureSeries.at(0).x
            timeAxis.max = temperatureSeries.at(temperatureSeries.count -1).x

            // adjust temperature axis
            if (temperatureData.lastReading.y < temperatureAxis.min)
                temperatureAxis.min = temperatureData.lastReading.y;
            if (temperatureData.lastReading.y > temperatureAxis.max)
                temperatureAxis.max = temperatureData.lastReading.y;
        }
    }
}
