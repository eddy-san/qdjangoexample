#ifndef SENSOR_H_
#define SENSOR_H_

#include "3rdParty/precise/include/qdjango/db/QDjango.h"
#include "3rdParty/precise/include/qdjango/db/QDjangoModel.h"
#include <QObject>
#include <QObject>

/**
 *  this class represents different sensor types
 */

class Sensor : public QDjangoModel
{
  Q_OBJECT

  Q_PROPERTY(QString 		type 	 READ getType		WRITE setType	 	 )
  Q_PROPERTY(QString 		comment  READ getComment	WRITE setComment	 )

  Q_CLASSINFO("__meta__"	, "db_table=Sensor")
  Q_CLASSINFO("id"			, "auto_increment=true db_index=true rimary_key=true")
  Q_CLASSINFO("type"		, "max_length=45")
  Q_CLASSINFO("comment"		, "max_length=200")


  private:

    QString 	  		  _comment;
    QString				  _type;

  public:
    Sensor(QObject *parent = 0);

    // getter
    int					  getId() const;
    QString 			  getComment()	  const;
    QString 			  getType() 	  const;

    // setter
    void setComment		(QString 	   comment		);
    void setType		(QString 	   type			);

};
#endif /* SENSOR_H_ */
