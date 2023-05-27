#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class UnitConverter : public QWidget {
public:
    UnitConverter(QWidget *parent = nullptr) : QWidget(parent) {
        // Создание элементов интерфейса
        QLabel *titleLabel = new QLabel("Конвертер единиц измерения", this);
        QLabel *valueLabel = new QLabel("Значение:", this);
        valueLineEdit = new QLineEdit(this);
        QLabel *resultLabel = new QLabel("Результат:", this);
        resultLineEdit = new QLineEdit(this);
        resultLineEdit->setReadOnly(true);
        QPushButton *convertButton = new QPushButton("Конвертировать", this);

        // Расположение элементов в вертикальном слое
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(titleLabel);
        mainLayout->addWidget(valueLabel);
        mainLayout->addWidget(valueLineEdit);
        mainLayout->addWidget(resultLabel);
        mainLayout->addWidget(resultLineEdit);
        mainLayout->addWidget(convertButton);

        setLayout(mainLayout);

        // Обработка нажатия на кнопку "Конвертировать"
        connect(convertButton, &QPushButton::clicked, this, &UnitConverter::convert);
    }

private:
    QLineEdit *valueLineEdit;
    QLineEdit *resultLineEdit;

    void convert() {
        // Получение введенного значения
        QString valueText = valueLineEdit->text();
        bool ok;

        // Конвертация значения в число
        double value = valueText.toDouble(&ok);

        if (!ok) {
            // Ошибка преобразования
            resultLineEdit->setText("Ошибка ввода");
            return;
        }

        // Выполнение конвертации
        double result = convertToKilograms(value);

        // Отображение результата
        resultLineEdit->setText(QString::number(result) + " кг");
    }

    double convertToKilograms(double value) {
        // Пример простой конвертации - из граммов в килограммы
        return value / 1000.0;
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    UnitConverter unitConverter;
    unitConverter.setWindowTitle("Конвертер единиц измерения");
    unitConverter.show();

    return app.exec();
}
