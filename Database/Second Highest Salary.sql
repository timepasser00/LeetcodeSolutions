-- [Problem Statement Link]
-- https://leetcode.com/problems/second-highest-salary/description/

-- [Problem Solution]
Select MAX(salary) as SecondHighestSalary
From Employee 
Where salary < (Select max(salary) From Employee)
