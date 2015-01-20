cmake_minimum_required (VERSION 2.6)
include(FindPkgConfig)


############################
# General project settings #
############################

PROJECT(QDJANGOLIGHT)

find_package(Qt4    COMPONENTS QtCore QtGui QtSql)

                    
link_directories(
		    ${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/precise/lib	 
)

include_directories(
		3rdParty/precise/include/qdjango/db 
)


SET(SOURCES 
    
    main.cpp
    Measure.cpp
    Sensor.cpp

    repositories/Persistence.cpp
    repositories/MeasureRepository.cpp
    repositories/SensorRepository.cpp
)

SET(HEADERS 
    Measure.h
    Sensor.h

    repositories/Persistence.h
    repositories/MeasureRepository.h
    repositories/SensorRepository.h
    repositories/IRepository.h
)


 
QT_WRAP_CPP(qdjangolight SOURCES ${HEADERS})

include(${QT_USE_FILE})

add_definitions(
                ${QT_DEFINITIONS}
                )


add_executable(qdjangolight ${SOURCES} ${HEADERS})


target_link_libraries(qdjangolight qdjango-db ${QT_LIBRARIES}) 
