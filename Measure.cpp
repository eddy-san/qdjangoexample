

#include <stdexcept>

#include "Measure.h"
#include "Sensor.h"

Measure::Measure(QObject *parent) : QDjangoModel(parent)
{
    _sensor 	= NULL;
    _dateTime	= QDateTime( QDateTime::currentDateTime());
    _value      = 0.0;
    _comment    = QString("none");

}

// getter
int Measure::getId()
{
	QVariant primaryKey = this->pk();
	return primaryKey.toInt();
}

QDateTime 		Measure::getDateTime()
{
	return _dateTime;
}

Sensor*		Measure::getSensor()
{

	Sensor *sensor = NULL;
	sensor = dynamic_cast<Sensor *>(foreignKey("sensor"));

	if(sensor != NULL)
	{
		return sensor;
	}
	else
	{
		throw std::invalid_argument("Measure::getPatient() null pointer");
	}
}

double			Measure::getValue()
{
	return _value;
}

QString 		Measure::getComment()
{
	return _comment;
}


// setter
void Measure::setDateTime(QDateTime dateTime)
{
	_dateTime = dateTime;
}
void Measure::setSensor(Sensor* sensor)
{
	setForeignKey("sensor", sensor);
}
void Measure::setValue(double value)
{
	_value = value;
}
void Measure::setComment(QString comment)
{
	_comment = comment;
}
 

