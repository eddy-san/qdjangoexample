

#ifndef PERSISTENCE_H_
#define PERSISTENCE_H_



#include <vector>

template <class T>
class Persistence
{
	private:
 		std::vector<T*> _list;

	public:
 		~Persistence();

		T* getById(int id);
		std::vector<int> getIdList();
		std::vector<int> getLatest(int size);
		bool create(T* item);
		bool remove(T* item);
		bool update(T* item);
		bool exists(T* item);
		int count();


};

#endif
