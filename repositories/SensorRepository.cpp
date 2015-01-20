

#include "SensorRepository.h"
#include <QDjangoQuerySet.h>
#include <stdexcept>


SensorRepository* SensorRepository::_sensorRepositoryInstance = NULL;


SensorRepository* SensorRepository::getInstance()
{
	if(!_sensorRepositoryInstance)
	{
		_sensorRepositoryInstance = new SensorRepository();
	}

	return _sensorRepositoryInstance;
}

SensorRepository::SensorRepository()
{
}

Sensor* SensorRepository::getById(int id)
{
	return _persistence.getById(id);
}

std::vector<Sensor* > SensorRepository::getAll()
{
	std::vector<Sensor* > databaseEntries;

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

int SensorRepository::count()
{
	return _persistence.count();
}

bool  SensorRepository::create(Sensor* sensor)
{
	return _persistence.create(sensor);
}

bool  SensorRepository::update(Sensor* sensor)
{
	return _persistence.update(sensor);
}

bool  SensorRepository::remove(Sensor* sensor)
{
	return _persistence.remove(sensor);
}

// additional operations
bool  SensorRepository::exists(Sensor *sensor)
{
	return _persistence.exists(sensor);
}

