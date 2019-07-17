
-- problem: "https://www.hackerrank.com/challenges/weather-observation-station-5/problem"

SELECT TOP 1 CITY,LEN(CITY) AS LEN_CITY FROM STATION ORDER BY LEN_CITY ASC,CITY ASC;

SELECT TOP 1 CITY,LEN(CITY) AS LEN_CITY FROM STATION ORDER BY LEN_CITY DESC,CITY ASC;
