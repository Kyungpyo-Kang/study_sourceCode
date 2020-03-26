--PLAYER 테이블에서 NATION이 NULL이 아니면 등록
--NULL이면 미등록으로 변경 후 선수이름, 국가 검색하기
--CASE문으로 사용
--CASE WHEN THEN ELSE END
SELECT PLAYER_NAME, NATION, 
	CASE
		WHEN NATION IS NULL THEN '미등록'
		ELSE '등록'
	END AS "국가 등록 여부"
FROM PLAYER;

--COALESCE(코얼레스) : 합치다, 연동하다
--NULL이 아니면 1차 선택, NULL이면 2차 선택, 둘 다 NULL이면 NULL
SELECT PLAYER_NAME, NICKNAME,
	COALESCE(NICKNAME, PLAYER_NAME) AS KNOWN
FROM PLAYER;

--PLAYER 테이블에서 NICKNAME이 없으면 '별명 없음'으로 변경 후 검색
SELECT PLAYER_NAME, NICKNAME,
	COALESCE(NICKNAME, '별명 없음') AS 별명
FROM PLAYER;

--집계 함수(NULL은 포함하지 않는다.)
--WHERE절에서는 사용할 수 없다.
--여러개의 값을 하나의 값으로 나타냄
--AVG() 평균
--MAX() 최댓값
--MIN() 최솟값
--SUM()	총합
--COUNT() 갯수
SELECT AVG(HEIGHT), MAX(HEIGHT), MIN(HEIGHT), SUM(HEIGHT) FROM PLAYER;

SELECT * FROM PLAYER;

SELECT COUNT(HEIGHT) FROM PLAYER;

--PLAYER 테이블에서 HEIGTH 개수 검색(NULL포함해서 COUNT하기)
SELECT COUNT(NVL(HEIGHT, 0)) FROM PLAYER;

--ORDER BY : 정렬
--ASC : 오름차순(생략 가능)
--DESC : 내림차순

--PLAYER 테이블에서 키 순으로 검색(오름차순)
SELECT PLAYER_NAME, HEIGHT 
FROM PLAYER
WHERE HEIGHT IS NOT NULL
ORDER BY HEIGHT ASC;

--PLAYER 테이블에서 키 순, 몸무게 순(오름차순)으로 검색
--NULL이 아닌 값만 검색
--첫번째 컬럼값(튜플)이 같으면 두번째 정렬을 한다.
SELECT PLAYER_NAME, HEIGHT, WEIGHT 
FROM PLAYER
WHERE HEIGHT IS NOT NULL AND WEIGHT IS NOT NULL
ORDER BY HEIGHT, WEIGHT;

--GROUP BY : ~별(예 : 포지션 별 평균키)

--SELECT ??? FROM ???
--GROUP BY 컬럼명
--HAVING 조건식

--PLAYER 테이블에서 포지션 검색
SELECT "POSITION"
FROM PLAYER
GROUP BY "POSITION"
HAVING "POSITION" IS NOT NULL;

--WHERE절에서 조건을 처리할 수 있다면 반드시 WHERE절에서 먼저 처리해준다.
--HAVING절보다 더 효율적이다.
SELECT "POSITION"
FROM PLAYER
WHERE "POSITION" IS NOT NULL
GROUP BY "POSITION";

--PLAYER 테이블에서 몸무게가 80이상인 선수들의 평균키가 180이상인 포지션 검색
SELECT "POSITION", AVG(HEIGHT), MIN(WEIGHT)
FROM PLAYER
WHERE WEIGHT >= 80
GROUP BY "POSITION"
HAVING AVG(HEIGHT) >= 180;

--EMPLOYEES 테이블에서 JOB_ID별로 평균 SALARY가 10000미만인
--(SALARY 합계, 평균, 최댓값, 최솟값, JOB_ID별 명수) 검색하기
--JOB_ID 알파벳 순으로 정렬(오름차순)
SELECT JOB_ID , SUM(SALARY), AVG(SALARY),
	MAX(SALARY), MIN(SALARY), COUNT(JOB_ID)
FROM EMPLOYEES
GROUP BY JOB_ID
HAVING AVG(SALARY) < 10000
ORDER BY JOB_ID;

--SUB_QUERY : SQL문 내부에 SQL문 선언
--FROM절		: IN LINE VIEW
--SELECT절	: SCALAR
--WHERE절	: SUB_QUERY

--PLAYER 테이블에서 TEAM_ID가 'K01'인 선수 중에 POSITION이 'GK'인 선수
SELECT * FROM(
	SELECT * FROM PLAYER
	WHERE TEAM_ID = 'K01'
)
WHERE "POSITION" = 'GK';

--WHERE만 사용하기
SELECT * FROM PLAYER
WHERE TEAM_ID = 'K01' AND "POSITION" = 'GK';

--PLAYER 테이블에서 평균키보다 작은 선수 검색
SELECT * FROM PLAYER
WHERE HEIGHT < (SELECT AVG(HEIGHT) FROM PLAYER);

--SCALAR SUB-QUERY
--전체 평균과 포지션별 평균키 구하기
SELECT "POSITION", AVG(HEIGHT),
	(SELECT AVG(HEIGHT) FROM PLAYER)
FROM PLAYER
WHERE "POSITION" IS NOT NULL
GROUP BY "POSITION";

SELECT
	ROUND(AVG(CASE "POSITION" WHEN 'DF' THEN HEIGHT END), 2) AS DF,
	ROUND(AVG(CASE "POSITION" WHEN 'GK' THEN HEIGHT END), 2) AS GK,
	ROUND(AVG(CASE "POSITION" WHEN 'FW' THEN HEIGHT END), 2) AS FW,
	ROUND(AVG(CASE "POSITION" WHEN 'MF' THEN HEIGHT END), 2) AS MF,
	ROUND(AVG(HEIGHT), 2) AS "전체 평균"
FROM PLAYER;

--PLAYER 테이블에서 NICKNAME이 NULL인 선수들은 정태민 선수의 닉네임으로 바꾸기
UPDATE PLAYER
SET (NICKNAME) = (SELECT NICKNAME FROM PLAYER WHERE PLAYER_NAME = '정태민')
WHERE NICKNAME IS NULL;

SELECT * FROM PLAYER;

--NICKNAME이 NULL인 선수들의 이름도 정태민으로 바꾸기
UPDATE PLAYER
SET (PLAYER_NAME, NICKNAME) =
(
	SELECT PLAYER_NAME, NICKNAME 
	FROM PLAYER 
	WHERE PLAYER_NAME = '정태민'
)
WHERE NICKNAME IS NULL;

SELECT * FROM PLAYER;

--EMPLOYEES 테이블에서 평균급여보다 낮은 사람들의 급여를 10% 인상하기(UPDATE)

SELECT SALARY
FROM EMPLOYEES
WHERE SALARY < (SELECT AVG(SALARY) FROM EMPLOYEES);

UPDATE EMPLOYEES
SET SALARY = SALARY * 1.1
WHERE SALARY < (SELECT AVG(SALARY) FROM EMPLOYEES);

--PLAYER 테이블에서 평균키보다 큰 선수들 삭제
--DELETE FROM 테이블 WHERE 조건;
SELECT ROUND(AVG(HEIGHT), 2) FROM PLAYER;

DELETE FROM PLAYER
WHERE HEIGHT > (SELECT AVG(HEIGHT) FROM PLAYER);

SELECT MAX(HEIGHT) FROM PLAYER;

--문자형 함수
--소문자, 대문자, ASCII코드, CHR
SELECT LOWER('BUS'), UPPER('bus'), ASCII('A'), CHR(65)
FROM DUAL;














