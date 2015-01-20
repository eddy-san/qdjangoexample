
#include "Sensor.h"



Sensor::Sensor(QObject *parent) : QDjangoModel(parent)
{

	_comment = QString("none");
	_type 	 = QString("none");

}

int  Sensor::getId()	  const
{
	QVariant primaryKey = this->pk();
	return primaryKey.toInt();
}

QString  Sensor::getComment()	  const
{
	return _comment;
}
QString  Sensor::getType() 	  const
{
	return _type;
}


void Sensor::setComment		(QString 	   comment		)
{
	_comment = comment;
}

void Sensor::setType		(QString 	   type		)
{
	_type = type;
}
