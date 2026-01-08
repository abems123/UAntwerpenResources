1. ##### What is the name of the last employee in the database?



###### SELECT first\_name, last\_name FROM employees ORDER BY emp\_no DESC LIMIT 1;



##### 2\. List the department he works for?



SELECT d.dept\_no, d.dept\_name

FROM departments as d,

&nbsp;    (SELECT \* FROM employees ORDER BY emp\_no DESC LIMIT 1) AS e,

&nbsp;    dept\_emp AS de

WHERE d.dept\_no = de.dept\_no

&nbsp; AND e.emp\_no = de.emp\_no;



##### 3\. What is the name of his current boss?



CREATE VIEW Works\_For AS

SELECT d.dept\_no, d.dept\_name

FROM departments as d,

&nbsp;    (SELECT \* FROM employees ORDER BY emp\_no DESC LIMIT 1) AS e,

&nbsp;    dept\_emp AS de

WHERE d.dept\_no = de.dept\_no

&nbsp; AND e.emp\_no = de.emp\_no;



SELECT e.first\_name, e.last\_name

FROM dept\_manager as dm,

&nbsp;    Works\_For as wf,

&nbsp;    employees as e

WHERE dm.dept\_no = wf.dept\_no

&nbsp; AND e.emp\_no = dm.emp\_no

&nbsp; AND dm.from\_date <= now()

&nbsp; AND dm.to\_date >= now();



##### 4\. What is his current salary?



SELECT s.salary

FROM employees as e,

&nbsp;    salaries as s

WHERE s.emp\_no = e.emp\_no

ORDER BY e.emp\_no DESC

LIMIT 1;



##### 5\. List the number of employees working in each department.



SELECT COUNT(\*), dept\_no FROM dept\_emp GROUP BY dept\_no;



##### 6\. List all departments and the name of the current manager.



SELECT d.dept\_name, e.first\_name, e.last\_name

FROM departments as d,

&nbsp;    dept\_manager as dm,

&nbsp;    employees as e

WHERE d.dept\_no = dm.dept\_no

&nbsp; AND dm.emp\_no = e.emp\_no;



##### 7\. Find the names of managers that earn less than the highest paid manager.



SELECT DISTINCT e.first\_name, e.last\_name

FROM employees AS e,

&nbsp;    dept\_manager AS dm,

&nbsp;    salaries as s,

&nbsp;    (SELECT s.salary

&nbsp;     FROM salaries AS s,

&nbsp;          dept\_manager as dm

&nbsp;     WHERE s.emp\_no = dm.emp\_no

&nbsp;     ORDER BY s.salary DESC

&nbsp;     LIMIT 1) AS h

WHERE s.salary < h.salary

&nbsp; AND s.emp\_no = e.emp\_no

&nbsp; AND dm.emp\_no = e.emp\_no;



##### 8\. Find all employees that have worked for at least two departments.



SELECT DISTINCT e.emp\_no, e.first\_name, e.last\_name

FROM employees as e,

&nbsp;    dept\_emp as de1,

&nbsp;    dept\_emp as de2

WHERE e.emp\_no = de1.emp\_no

&nbsp; AND de1.emp\_no = de2.emp\_no

&nbsp; AND de1.dept\_no < de2.dept\_no

ORDER BY e.emp\_no;



##### 9\. Find all employees that had the same title during their career.



SELECT DISTINCT e1.first\_name, e1.last\_name, e2.first\_name, e2.last\_name

FROM employees AS e1,

&nbsp;    employees AS e2,

&nbsp;    (SELECT t1.emp\_no AS first, t2.emp\_no AS second

&nbsp;     FROM titles t1,

&nbsp;          titles t2

&nbsp;     WHERE t1.emp\_no < t2.emp\_no

&nbsp;       AND t1.title = t2.title

&nbsp;       AND t1.from\_date < t2.from\_date

&nbsp;       AND t2.to\_date > t1.from\_date) AS d

WHERE e1.emp\_no = d.first

&nbsp; AND e2.emp\_no = d.second LIMIT 100;



##### 10\. ! Find all employees that had all possible titles during their career.

##### 11\. ! Find all employees that had an increase, between their first and current salary, that is at least 2 times the average increase in salary for any employee in the same department.

##### 12\. Find the top-10 employees with the highest last salary

##### 13\. Find for each department the total, maximal, average and minimal salary.

