#ifndef MEASURE_H_
#define MEASURE_H_

#include "3rdParty/precise/include/qdjango/db/QDjango.h"
#include "3rdParty/precise/include/qdjango/db/QDjangoModel.h"
 
#include <QDateTime>


class Sensor;

/** this class represents a single sensor measure
 *
 */
 
class Measure : public QDjangoModel
{
  Q_OBJECT

  // table columns
  Q_PROPERTY(Sensor* 		sensor 	 	 READ getSensor 	 	WRITE setSensor		)
  Q_PROPERTY(QDateTime 		datetime 	 READ getDateTime 		WRITE setDateTime	)
  Q_PROPERTY(double 		value	 	 READ getValue			WRITE setValue		)
  Q_PROPERTY(QString 		comment 	 READ getComment		WRITE setComment	)


  // table meta definition
  Q_CLASSINFO("__meta__"	, "db_table=Measure")
  Q_CLASSINFO("id"		, "auto_increment=true db_index=true rimary_key=true")
  Q_CLASSINFO("sensor"		, "on_delete=cascade")
  Q_CLASSINFO("comment"		, "max_length=200")


  
  private:
    // private members corresponds to table columns
    Sensor* 			  _sensor;
    QDateTime			  _dateTime;
    bool			  _value;
    QString 	  		  _comment;

  public:
    Measure(QObject *parent = 0);

    // qdjango function
    int				  getId(); 

    // getter corresponds to table columns
    QDateTime 			  getDateTime();
    Sensor*			  getSensor();
    double	  	          getValue();
    QString 			  getComment();

    // setter corresponds to table columns
    void setDateTime		(QDateTime	dateTime	);
    void setSensor		(Sensor* 	sensor		);
    void setValue		(double		value		); 
    void setComment		(QString 	comment		);



};

#endif /* MEASURE_H_ */
