
#include "repositories/MeasureRepository.h"
#include "repositories/SensorRepository.h"

#include <QDjango.h>
#include <QDjangoModel.h>
#include <QApplication>

void createSensors()
{
     // create sensor
     Sensor *sensor = new Sensor();
     sensor->setType("Kinect");
     SensorRepository* sensorRepository = SensorRepository::getInstance();
     sensorRepository->create(sensor);
   
}

void createMeasures()
{
     // get sensor from repository
     SensorRepository* sensorRepository = SensorRepository::getInstance();
     Sensor* kinectSensor = sensorRepository->getById(1);     

     // create measure
     Measure* measure_1 = new Measure();
     measure_1->setSensor(kinectSensor);
     measure_1->setValue(1.0);
     MeasureRepository* measureRepository = MeasureRepository::getInstance();
     measureRepository->create(measure_1);

     // create measure
     Measure* measure_2 = new Measure();
     measure_2->setSensor(kinectSensor);
     measure_2->setValue(2.0);
     measureRepository->create(measure_2);
     

}

#define CREATE_TABLES 0

int main( int argc, char* argv[])
{


        // establish database connection
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

	db.setDatabaseName("testdb");
	db.setUserName("testuser");
	db.setPassword("testuser");
	bool dbOpen = db.open();


	QDjango::setDebugEnabled(true);
	QDjango::setDatabase(db);

	QDjango::registerModel<Measure>();
	QDjango::registerModel<Sensor>();

	if(CREATE_TABLES)
        {
		QDjango::createTables();
		createSensors();
		createMeasures();

 	}

	// get measure from repository
	MeasureRepository* measureRepository = MeasureRepository::getInstance();
	std::vector<Measure*> measures = measureRepository->getAll();

	for(int i = 0; i < measures.size(); i++)
        {
	     Measure* measure = measures.at(i);
             std::cout << measure->getId() << " " << measure->getValue() << std::endl;
	}

        return 0;
}
