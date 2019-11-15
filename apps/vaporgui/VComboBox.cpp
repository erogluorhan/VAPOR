#include "VComboBox.h"


VComboBox::VComboBox( const std::vector<std::string> &values )
: VContainer( this )
{
    _combo = new QComboBox;
    layout()->addWidget(_combo);
    SetOptions( values );

    connect( _combo, SIGNAL( currentIndexChanged( QString ) ),
        this, SLOT( emitComboChanged( QString ) ) );
}


// Stas thinks that we should have setValues and setValue instead of Update
//
void VComboBox::SetOptions( const std::vector<std::string> &values)
{
    _combo->blockSignals(true);
    _combo->clear();
    for (auto i : values) {
        _combo->addItem( QString::fromStdString(i) );
    }
    _combo->blockSignals(false);
}

void VComboBox::SetIndex( int index ) {
    if (index > _combo->count()) 
        return;

    _combo->blockSignals(true);
    _combo->setCurrentIndex( index );
    _combo->blockSignals(false);
}

void VComboBox::SetValue( const std::string& value ) {
    QString qValue = QString::fromStdString( value );
    int index = _combo->findText( qValue );
    if ( index >= 0 )
        SetIndex( index );
}

int VComboBox::GetCurrentIndex() const {
    return _combo->currentIndex();
}

std::string VComboBox::GetCurrentString() const {
    return _combo->currentText().toStdString();
}

void VComboBox::emitComboChanged( QString value ) {
    emit ValueChanged( value.toStdString() );
}