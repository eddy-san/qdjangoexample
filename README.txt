
qdjango is a qt extension for object relational mapping.

usually we use sql statements to save data into a database.

qdjango takes a different way and maps c++ objects into a table row.

beyond this as a programmer you don't need to write sql statements anymore.

just use qdjango methods.

see http://doc.qdjango.org/qdjango-snapshot/ for further documentation

---

to run this example you need a valid mysql connection

default settings are:

database: testdb

user: testuser

pwd: testuser

---

see measure.h and sensor.h to define table columns

the repositories encapsulates CRUD operations for measure and sensor data

you can use the repositories like an objet oriented database.

take objects by gebById() or getAll()
