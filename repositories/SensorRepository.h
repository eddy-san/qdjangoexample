
#ifndef SENSORREPOSITORY_H_
#define SENSORREPOSITORY_H_


#include "IRepository.h"
#include "Persistence.h"
#include "../Sensor.h"

/** this class represents a repository for sensor objects
 *
 *  @author: eroth
 *  @date:   26.10.2014
 */

class SensorRepository : public IRepository<Sensor>
{
	private:
		static SensorRepository* _sensorRepositoryInstance;
		Persistence<Sensor> 	 _persistence;
		SensorRepository();

	public:

		// Repositories are implemented as singleton
		static SensorRepository* 	getInstance();

		// CRUD operations
		bool 						create(Sensor* sensor);
		Sensor* 				 	getById(int id);
		bool 						update(Sensor* sensor);
		bool 						remove(Sensor* sensor);

		// additional operations
		int 					  	count();
		std::vector<Sensor* > 		getAll();
		bool 						exists(Sensor *sensor);

		// table specific


};


#endif /* SENSORREPOSITORY_H_ */
