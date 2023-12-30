-- Problem Statement Link
-- https://leetcode.com/problems/combine-two-tables/

-- Problem Solution 
Select p.firstName, p.lastName, a.city, a.state
From Person p  
Left Join Address a
On p.personId = a.personId
