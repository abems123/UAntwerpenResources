# Exercise series 6: Active Databases



## Problem 1



### Create in PostgreSQL a schema based on the following description.



#### 1\) Re-write the text as a checklist of “things the DB must enforce”



From the description (page 2), underline every sentence that implies one of these:



##### A table (an entity like Student, Course, Professor, …)

* Student
* Course
* Academic Year
* Professor
* Course Offering



##### A key / uniqueness rule (“must be unique”, “identified by …”)

* The combination of **first and last name must be unique**
* A student can also be **identified by a unique enrolment number**
* A course has a **unique name and id**
* A professor is **identified by the combination of first and last name**.
* The combination of **year, semester and course identifies** the course offering.



##### A mandatory rule (“must be present” → NOT NULL)

* The combination of first and last name must be unique, and **both fields are mandatory**.



##### A value restriction (“between …”, “either …” → CHECK, DOMAIN, or ENUM)

* A student can also be identified by a unique enrolment number which **must be between 10\*000 and 99\*999**.
* A course has a unique name and id, **which must be a positive integer**. 
* A course also has a number of student points. The number of student points is **either 3, 6, 9 or 12**.
* The starting year should be **a year before the ending one**, and both should be **between 2000 and 2100**.
* We also store the semester: **either 'first' or 'second’**.



##### A relationship (who references who → FOREIGN KEY)

* A course offering **is** **composed of a course, an academic year and a professor**.



##### A delete/update behavior (“if X is deleted…”, “if X is updated…” → ON DELETE …, ON UPDATE …)

* If student enrolment number, professor name or course id **is updated**, all references **are updated**.
* If a student **is deleted**, **delete all** enrolments of that student.
* If a professor **is deleted**, **set reference to null**.
* If a course **is deleted**, **delete all** enrolments and teaching assignments.



#### 2\) List the tables you think you need (just names + purpose)

* Student
* Course
* Academic Year
* Professor
* Course Offering



#### 3\) For each table, decide the identifier first (PK)

* The combination of **first and last name must be unique**
* A student can also be **identified by a unique enrolment number**
* A course has a **unique name and id**
* A professor is **identified by the combination of first and last name**.
* The combination of **year, semester and course identifies** the course offering.



#### 4\) Add constraints in layers (don’t try all at once)

..









CREATE DOMAIN RealDate INT CHECK (VALUE BETWEEN 2000 AND 2100);

CREATE DOMAIN Sem VARCHAR(100) CHECK (VALUE IN ('first','second'));

CREATE DOMAIN EnrolmentNumber INT CHECK (VALUE BETWEEN 10000 AND 99999);



CREATE TABLE Student(enr\_nr EnrolmentNumber PRIMARY KEY, 

&nbsp;                    first\_name VARCHAR(100) NOT NULL, 

&nbsp;                    last\_name VARCHAR(100) NOT NULL);



CREATE TABLE Course(id INT PRIMARY KEY CHECK (id >= 0), name VARCHAR(100) UNIQUE, student\_points INT CHECK (student\_points IN (3,6,9,12)));



CREATE TABLE AcademicYear(starting\_year RealDate, ending\_year RealDate, CONSTRAINT right\_time CHECK (ending\_year-starting\_year=1), PRIMARY KEY(starting\_year, ending\_year));



CREATE TABLE Professor (first\_name VARCHAR(100), last\_name VARCHAR(100), PRIMARY KEY(first\_name, last\_name));



CREATE TABLE CourseOffering(

&nbsp; cid INT REFERENCES Course(id) ON DELETE CASCADE, 

&nbsp; ac\_start RealDate, 

&nbsp; ac\_end RealDate, 

&nbsp; pfn VARCHAR(100), 

&nbsp; pln VARCHAR(100), 

&nbsp; semester Sem, 

&nbsp; FOREIGN KEY(ac\_start, ac\_end) REFERENCES AcademicYear(starting\_year, ending\_year),

&nbsp; FOREIGN KEY(pfn, pln) REFERENCES Professor(first\_name, last\_name)

&nbsp; ON DELETE SET NULL,

&nbsp; PRIMARY KEY(ac\_start, ac\_end, semester, cid));

&nbsp; 

CREATE TABLE Enrolment(enr\_nr EnrolmentNumber, 

&nbsp;                      cid INT,

&nbsp;                      PRIMARY KEY(enr\_nr, cid),

&nbsp;                      FOREIGN KEY(enr\_nr) REFERENCES Student(enr\_nr)

&nbsp;                      ON DELETE CASCADE

&nbsp;                      ON UPDATE CASCADE,

&nbsp;                      FOREIGN KEY(cid) REFERENCES Course(id)

&nbsp;                      ON UPDATE CASCADE ON DELETE CASCADE,

&nbsp;                      ac\_start RealDate, 

&nbsp;                      ac\_end RealDate, 

&nbsp;                      semester Sem, 

&nbsp;                      FOREIGN KEY (ac\_start, ac\_end, semester, cid) 

&nbsp;                      REFERENCES CourseOffering(ac\_start, ac\_end, semester, cid));





