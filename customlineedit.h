#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QLineEdit>
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include<QKeyEvent>

class CustomLineEditData;

class CustomLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    CustomLineEdit();
    CustomLineEdit(const CustomLineEdit &);
    CustomLineEdit(CustomLineEdit &&);
    CustomLineEdit &operator=(const CustomLineEdit &);
    CustomLineEdit &operator=(CustomLineEdit &&);
    ~CustomLineEdit();

protected:
    void keyPressEvent(QKeyEvent *event) override {
        // block Ctrl+V
        if (event->matches(QKeySequence::Paste)) {
            return; // Ignoring event
        }
        // block Ctrl+C
        if (event->matches(QKeySequence::Copy)) {
            return; // Ignoring event
        }
        QLineEdit::keyPressEvent(event); // Process other events
    }

    void contextMenuEvent(QContextMenuEvent *event) override {
        // Disabling context menu
    }

private:
    QSharedDataPointer<CustomLineEditData> data;
};

#endif // CUSTOMLINEEDIT_H\


