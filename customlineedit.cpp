#include "customlineedit.h"

#include <utility>

class CustomLineEditData : public QSharedData
{
public:
};

CustomLineEdit::CustomLineEdit()
    : data(new CustomLineEditData)
{}

CustomLineEdit::CustomLineEdit(const CustomLineEdit &rhs)
    : data{rhs.data}
{}

CustomLineEdit::CustomLineEdit(CustomLineEdit &&rhs)
    : data{std::move(rhs.data)}
{}

CustomLineEdit &CustomLineEdit::operator=(const CustomLineEdit &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

CustomLineEdit &CustomLineEdit::operator=(CustomLineEdit &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

CustomLineEdit::~CustomLineEdit() {}
