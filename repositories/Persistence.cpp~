
#include "Persistence.h"

#include "../Measure.h"
#include "../Sensor.h"

#include <QDjango.h>
#include <QDjangoModel.h>
#include <QDjangoQuerySet.h>

#include <stdexcept>
#include <iostream>


#include <algorithm>



template <class T>
T* Persistence<T>::getById(int id)
{
	if(id < 1)
	{
		throw std::invalid_argument("Persistence::getById() ids only greater than 1 are valid");
	}

	QDjangoQuerySet<T> query;
	T* item = query.get(QDjangoWhere("id", QDjangoWhere::Equals, id), NULL);

	if(item == NULL)
	{
		throw std::invalid_argument("Persistence::getById() not in database!");
	}

	_list.push_back(item);

	return item;

}



template <class T>
int Persistence<T>::count()
{
	QDjangoQuerySet<T> query;
	int count = query.count();

	return count;
}

template <class T>
bool Persistence<T>::create(T *item)
{
	if(item == NULL)
	{
		throw std::invalid_argument("Persistence::create() item to create is a null pointer");
	}

	bool created = false;

	// not in database
	if(item->getId() < 1)
	{
		created = item->save();
		int itemId = item->getId();
		_list.push_back(item);

	}

	return created;
}

template <class T>
bool Persistence<T>::remove(T *item)
{
	if(item == NULL)
	{
		throw std::invalid_argument("Persistence::remove() item to delete is a null pointer");
	}

	bool deleted = item->remove();

	return deleted;

}

template <class T>
bool Persistence<T>::update(T *item)
{
	if(item == NULL)
	{
		throw std::invalid_argument("Persistence::update() item to update is a null pointer");
	}

	bool update = item->save();

	if(update)
	{
		// search list for given id
		for(int i = 0; i < _list.size(); i++)
		{
			T* tmp = _list.at(i);

			if(tmp->getId() == item->getId())
			{
				// update existing instance
				QDjangoQuerySet<T> query;
				tmp = query.get(QDjangoWhere("id", QDjangoWhere::Equals, tmp->getId()), tmp);
			}
		}

	}

	return update;

}


template <class T>
bool Persistence<T>::exists(T* item)
{
	if(item == NULL)
	{
		throw std::invalid_argument("Persistence::exists() item to check for is a null pointer");
	}

	bool exists = false;

	QDjangoQuerySet<T> query;
	query = query.filter(QDjangoWhere("id", QDjangoWhere::Equals, item->getId()));

	// query failed, item not existent
	if(query.count() != 0)
	{
		exists = true;
	}

	return exists;
}

template <class T>
Persistence<T>::~Persistence()
{
	for(int i = 0; i < _list.size(); i++)
	{
		delete _list.at(i);
	}

}

template <class T>
std::vector<int> Persistence<T>::getIdList()
{

	std::vector<int> primaryKeys;

	QDjangoQuerySet<T> query;
	query = query.all();
	QList<QVariantMap> idList = query.values( QStringList(QString("id")));

	// iterate all ids
	for(int i = 0; i < idList.size(); i++)
	{
		QVariantMap idMap = idList.at(i);
		QString value = idMap.value("id").toString();

	 	primaryKeys.push_back (value.toInt());
	}

	return primaryKeys;
}

/** this functions sorts all primary keys in ascending order
 *
 *
 */
template <class T>
std::vector<int> Persistence<T>::getLatest(int size)
{

   std::vector<int> primaryKeys;

   std::vector<int> sortedIdList = getIdList();
   std::sort(sortedIdList.begin(), sortedIdList.end()); // sort ASC    .. 243 244 (245)

   if(size > 0 && size < count())
   {

      for(std::vector<int>::iterator it = sortedIdList.end() - size; it != sortedIdList.end(); it++)
      {
         primaryKeys.push_back(*it);
      }

   }

   return primaryKeys;
}


// Explicit template instantiation
 
template class Persistence<Measure>;
template class Persistence<Sensor>;
 

 
