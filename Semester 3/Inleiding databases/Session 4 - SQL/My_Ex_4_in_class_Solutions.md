# Problem 1: Dealers, Producers and Products



1. ## Give all types of products that are produced by at least two different producers.



SELECT DISTINCT P1.type as Type FROM Products as P1, Products as P2 WHERE P1.type=P2.type AND NOT P1.producer\_id=P2.producer\_id;



## 2\. Give the minimum price of a product sold by Quality Goods.



CREATE VIEW Quality\_Goods\_Producers AS SELECT producer\_id FROM Deals WHERE dealer\_id=(SELECT dealer\_id FROM Dealers WHERE name='Quality Goods');



CREATE VIEW Products\_Sold\_By\_Quality\_Goods AS SELECT \* FROM Products NATURAL JOIN Quality\_Goods\_Producers;



SELECT MIN(price) AS "The Minimum Price" FROM Products\_Sold\_By\_Quality\_Goods;



## 3\. Give the name of the producer of the most expensive washing machine.



CREATE VIEW Price\_NAME AS SELECT DISTINCT P2.price, Produ.name FROM Products P1, Products P2, Producers Produ WHERE P1.price < P2.price AND P2.producer\_id=Produ.producer\_id ORDER BY P2.price DESC LIMIT 1;



SELECT name FROM Price\_NAME;



## 4\. Give the names of the dealers that do not sell any vacuum cleaners.



CREATE VIEW sells\_v AS (SELECT producer\_id FROM Products WHERE type='vacuum cleaner');



CREATE VIEW deals\_v AS (SELECT DISTINCT dealer\_id FROM Deals, sells\_v WHERE Deals.producer\_id=sells\_v.producer\_id);



SELECT name FROM Dealers WHERE dealer\_id IN (SELECT dealer\_id FROM Dealers 

EXCEPT

SELECT \* FROM deals\_v);





# Problem 2: Employees and Departments



1. ## Give all departments in which all employees have different salaries.



#### Relational Algebra

π name, manager (Departments ⨝ name≠e1.d\_name π e1.d\_name (σ e1.name<e2.name ∧e1.salary=e2.salary ∧ e1.d\_name=e2.d\_name (ρ e1(Employees) ⨯ ρ e2(Employees))))



#### SQL

CREATE VIEW Dep\_Same\_Salary AS (SELECT e1.d\_name FROM Employees e1, Employees e2 WHERE e1.name<e2.name AND e1.salary=e2.salary AND e1.d\_name=e2.d\_name); 

SELECT D.name, D.manager FROM Departments D, Dep\_Same\_Salary DSS WHERE D.name NOT IN (DSS.d\_name);



## 2\. Give all pairs of employees that have the same salary in the same department. Make sure you give every pair just once.



#### Relational Algebra

π e1.name, e2.name (σ e1.name<e2.name ∧ e1.salary=e2.salary ∧ e1.d\_name=e2.d\_name (ρ e1(Employees) ⨯ ρ e2(Employees)))



#### SQL

CREATE VIEW Dep\_Same\_Salary AS (SELECT e1.name as e1, e2.name AS e2 FROM Employees e1, Employees e2 WHERE e1.name<e2.name AND e1.salary=e2.salary AND e1.d\_name=e2.d\_name); 

SELECT \* FROM Dep\_Same\_Salary;



## 3\. Give all employees assigned to all departments in which Bill is manager.



#### Relational Algebra

bill\_deps = ρ d\_name←name(π name σ manager='Bill' Departments)

π name,d\_name Employees ÷ bill\_deps



#### SQL



## 4\. Give all employees assigned to any department in which Bob is manager.



#### Relational Algebra

bill\_deps = ρ d\_name←name(π name σ manager='Bob' Departments)

π name (Employees ⨝ bill\_deps)



#### SQL

CREATE VIEW Bill\_Deps AS (SELECT name FROM Departments WHERE manager='Bob');

SELECT DISTINCT name FROM Employees WHERE d\_name IN (SELECT \* FROM Bill\_Deps);





# Problem 3: Exam question (in 2017)



## 1\) Give the names of all employees currently working on more than one project.



#### Relational Algebra



π name (π a1.emp\_id (σ a1.emp\_id=a2.emp\_id ∧ a1.project\_id<a2.project\_id (ρ a1(Assignment) ⨯ ρ a2(Assignment))) ⨝ Employee)



#### SQL



CREATE VIEW EMP\_MORE AS SELECT a1.emp\_id FROM Assignment a1, Assignment a2 WHERE a1.emp\_id=a2.emp\_id AND a1.project\_id<a2.project\_id;



SELECT name FROM Employee WHERE emp\_id IN (SELECT \* FROM EMP\_MORE);



## 2\) Give the name of the highest paid employee working on Brain Drain.



#### Relational Algebra



brain\_d\_employees = π emp\_id,name,sex,salary,dept\_id (π project\_id (σ name='brain drain' Project) ⨝ Assignment ⨝ Employee)



emp\_with\_less\_salary =  π b1.emp\_id, b1.name, b1.sex, b1.salary, b1.dept\_id (σ b1.salary < b2.salary (ρ b1(brain\_d\_employees) ⨯ ρ b2(brain\_d\_employees)))



brain\_d\_employees - emp\_with\_less\_salary



#### SQL



CREATE VIEW B\_D\_Employees AS SELECT e.emp\_id, e.name, e.sex, e.salary, e.dept\_id FROM Employee AS e, Assignment AS a, Project AS p WHERE p.name='brain drain' AND a.project\_id=p.project\_id AND e.emp\_id=a.emp\_id;



SELECT name FROM (SELECT \* FROM B\_D\_Employees EXCEPT (SELECT B1.emp\_id, B1.name, B1.sex, B1.salary, B1.dept\_id FROM B\_D\_Employees AS B1, B\_D\_Employees AS B2 WHERE B1.salary < B2.salary));



## 3\) Give the names of all projects on which only men are working.

#### 

#### Relational Algebra



only\_men = Assignment - (π project\_id,emp\_id (Assignment ⨝ emp\_id=female (ρ female←emp\_id σ sex='F' Employee)))

π name (only\_men⨝Project)



#### SQL



SELECT DISTINCT p.name FROM Project AS p, Employee AS e, Assignment AS a WHERE e.sex='M' AND e.emp\_id=a.emp\_id AND a.project\_id=p.project\_id;





## 4\) Give the names of all departments that currently have no employees involved in any projects.



#### Relational Algebra



π dept\_id ((π emp\_id Employee - π emp\_id Assignment) ⨝ Employee) ⨝ Department



#### SQL



SELECT \* FROM Department WHERE dept\_id IN (SELECT dept\_id FROM Employee WHERE emp\_id IN (SELECT emp\_id FROM Employee EXCEPT (SELECT DISTINCT emp\_id FROM Assignment)));



## 5\) Give the names of departments where all employees are active in a project.



#### Relational Algebra



π name ((π emp\_id (Project ⨝ Assignment)) ⨝ ρ nn←name Employee ⨝ Department)



#### SQL



SELECT DISTINCT d.name FROM Department d, Assignment a, Employee e WHERE a.emp\_id=e.emp\_id AND d.dept\_id=e.dept\_id;



