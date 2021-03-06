
#include "MeasureRepository.h"
#include "SensorRepository.h"

#include <QDjangoQuerySet.h>

MeasureRepository* MeasureRepository::_measureRepositoryInstance = NULL;


MeasureRepository* MeasureRepository::getInstance()
{
	if(!_measureRepositoryInstance)
	{
		_measureRepositoryInstance = new MeasureRepository();
	}

	return _measureRepositoryInstance;
}

MeasureRepository::MeasureRepository()
{

}

Measure* MeasureRepository::getById(int id)
{
	Measure* measure = _persistence.getById(id);

	// set patient
	QDjangoQuerySet<Measure> query;
	query = query.filter(QDjangoWhere("id", QDjangoWhere::Equals, id));

	if(query.size() != 0)
	{

		QStringList foreignKeys = (QStringList() << "sensor_id");

		QList<QVariantMap> idList = query.values( foreignKeys );

		// there is only one result row
		QVariantMap idMap = idList.at(0);

		// returns the stored value <key, value> as QString
		QString sensorId = idMap.value("sensor_id").toString();

		SensorRepository* sensorRepository = SensorRepository::getInstance();
		Sensor* sensor = sensorRepository->getById(sensorId.toInt());

		measure->setSensor(sensor);

	}


	return measure;
}

std::vector<Measure* > MeasureRepository::getAll()
{
	std::vector<Measure* > databaseEntries;

	// get all primary keys from persistence class
	std::vector<int> entriesIdList = _persistence.getIdList();

	// call getById() for every primary key to solve foreign key dependencies
	for(int i = 0; i < entriesIdList.size(); i++)
	{
		databaseEntries.push_back( getById(entriesIdList.at(i)) );
	}

	// return
	return databaseEntries;
}

int MeasureRepository::count()
{
	return _persistence.count();
}

bool MeasureRepository::create(Measure* measure)
{
	return _persistence.create(measure);
}

bool MeasureRepository::remove(Measure* measure)
{
	return  _persistence.remove(measure);
}

bool MeasureRepository::update(Measure* measure)
{
	return _persistence.update(measure);
}

bool MeasureRepository::exists(Measure* measure)
{
	return _persistence.exists(measure);

}


std::vector<Measure* > 	MeasureRepository::getBySensorId(int sensorId)
{
	std::vector<Measure* > measures;

	 // query table
	 QDjangoQuerySet< Measure > query;
	 query = query.filter(QDjangoWhere("sensor_id", QDjangoWhere::Equals, sensorId));

	 // limit search result
	 if(query.size() != 0)
	 {
		 QList<QVariantMap> measureList = query.values( QStringList() << "id");

		 for(int i = 0; i < measureList.size(); i++)
		 {
			 QVariantMap measureIdMap = measureList.at(i);
			 QString measureId = measureIdMap.value("id").toString();
			 Measure* singleMeasure = getById(measureId.toInt());
			 measures.push_back(singleMeasure);
		 }
	 }

	return measures;
}


std::vector<Measure* >  MeasureRepository::getLatest(int size)
{
   std::vector<Measure* > measures;

   if(size > 0 && size < count())
   {
      std::vector<int> idList =  _persistence.getLatest(size);

      for(int i = 0; i < idList.size(); i++)
      {
         measures.push_back( getById(idList.at(i)) );
      }
   }

   return measures;
}
