
#ifndef IREPOSITORY_H_
#define IREPOSITORY_H_

#include <vector>

/** interface definition for performing CRUD operations on database
 *  it encapsulates application logic from database access
 *  see repository design pattern
 */
template<class T>
class IRepository
{
        public:

			// CRUD operations
			virtual bool 		/* C */	create(T* item) = 0;
			virtual T*		 	/* R */	getById(int id)	= 0;
			virtual bool 		/* U */	update(T* item) = 0;
			virtual bool 		/* D */	remove(T* item) = 0;

			// additional operations
			virtual int 				count()			= 0;
			virtual std::vector<T* > 	getAll()		= 0;
			virtual bool 				exists(T *item) = 0;

};

#endif /* IREPOSITORY_H_ */
