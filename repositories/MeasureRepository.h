
#ifndef MEASUREREPOSITORY_H_
#define MEASUREREPOSITORY_H_

#include <iostream>
#include <vector>
#include <stdexcept>


#include "IRepository.h"
#include "Persistence.h"
#include "../Measure.h"



class MeasureRepository : public IRepository<Measure>
{
	private:

	  static MeasureRepository* _measureRepositoryInstance;
	  Persistence<Measure> 		_persistence;
	  MeasureRepository();

    public:
	  // repositories are implemented as singleton
	  static MeasureRepository* getInstance();

      // CRUD operations
      bool 						create(Measure* measure);
      Measure* 				 	getById(int id);
      bool 						update(Measure* measure);
      bool 						remove(Measure* measure);

      // additional operations
      int 					  	count();
      std::vector<Measure* > 	getAll();
      bool 						exists(Measure *measure);

      // table specific
      std::vector<Measure* > 	getBySensorId(int sensorId);
      std::vector<Measure* >  getLatest(int size);


};

#endif /* MEASUREREPOSITORY_H_ */
