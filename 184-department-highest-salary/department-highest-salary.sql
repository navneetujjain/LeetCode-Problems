# Write your MySQL query statement below
SELECT Department.name as Department, Employee.name as Employee, Employee.salary as Salary
FROM Employee
LEFT JOIN Department
ON Employee.departmentId = Department.Id
WHERE(Department.Id, Employee.Salary) IN (SELECT DepartmentId, MAX(Salary) FROM Employee GROUP BY DepartmentId)
