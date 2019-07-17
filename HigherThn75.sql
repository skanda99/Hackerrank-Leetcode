
-- PROBLEM: "https://www.hackerrank.com/challenges/more-than-75-marks/problem"

SELECT NAME FROM STUDENTS WHERE MARKS>75 ORDER BY RIGHT(NAME,3) ASC,ID ASC;
