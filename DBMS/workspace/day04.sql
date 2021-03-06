--AS(ALIAS) : 별칭
--SELECT절 : AS 뒤에 또는 한 칸 띄우고 작성
--FROM절 : 한 칸 띄우고 작성

SELECT PLAYER_ID AS "선수 번호", PLAYER_NAME 이름 FROM PLAYER;

--PLAYER 테이블에서 BACK_NO를 "등번호"로, NICKNAME을 "선수 별명"으로 바꿔서 검색
SELECT BACK_NO 등번호, NICKNAME AS "선수 별명" FROM PLAYER;

--PLAYER 테이블에서 선수이름을, TEAM 테이블에서 주소를 검색
SELECT P.PLAYER_NAME, T.ADDRESS FROM PLAYER P, TEAM T;

--SELECT P.TEAM_ID, T.TEAM_ID FROM PLAYER P, TEAM T;

SELECT * FROM TEAM;

--STADIUM 테이블에서 ADDRESS를, TEAM테이블에서 TEL 검색
SELECT S.ADDRESS AS "경기장 주소", T.TEL 전화번호 FROM STADIUM S, TEAM T;

--CONCATENATION(연결)
SELECT PLAYER_NAME||'별명은 '||NICKNAME AS 정보 FROM PLAYER;

--LIKE : 포함된 문자열의 값을 찾음
-- % : 모든 것
-- '%A' : A로 끝나는 모든 값(FDFFEWSDA, SADFSA,QE34A)
-- '_A' : A로 끝나고 두 자리인 값(AA, 2A, PA)

SELECT * FROM TEAM WHERE TEAM_NAME LIKE '%곤즈';
SELECT * FROM PLAYER WHERE PLAYER_NAME LIKE('김%') AND PLAYER_NAME LIKE('김_');

--PLAYER 테이블에서 이씨 찾기
SELECT * FROM PLAYER WHERE PLAYER_NAME LIKE('이%');
--PLAYER 테이블에서 김씨와 이씨 찾기
SELECT * FROM PLAYER WHERE PLAYER_NAME LIKE('이%') OR PLAYER_NAME LIKE('김%');
--PLAYER 테이블에서 김씨가 아닌 사람 찾기(NOT)
SELECT * FROM PLAYER WHERE NOT PLAYER_NAME LIKE('김%');

--CASE문
--CASE WHEN THEN ELSE END
--CASE WHEN 조건식 THEN TRUE ELSE FALSE END
--EMP 테이블에서 SAL 3000이상이면 HIGH 1000이상이면 MID 다 아니면 LOW
SELECT ENAME 사원명, SAL 급여,
	CASE
	WHEN SAL >= 3000 THEN 'HIGH'
	WHEN SAL >= 1000 THEN 'MID'
	ELSE 'LOW'
	END AS 클라스
FROM EMP;

--중첩 CASE문(Nested CASE)
-- EMP 테이블에서 SAL이 2000이상이면 보너스 1000
-- SAL 1000이상이면 보너스 500
-- 다 아니면 0

SELECT ENAME 사원명, SAL 급여,
	CASE
		WHEN SAL >= 2000 THEN 1000
		ELSE (CASE
				WHEN SAL >= 1000 THEN 500
				ELSE 0
				END
			 )
	END AS 보너스
FROM EMP;

--실습
--STADIUM 테이블에서 SEAT_COUNT가 0이상 30000이하면 'S'
--30001이상 50000이하면 'M' 다 아니면 'L'
SELECT STADIUM_NAME 경기장, SEAT_COUNT 좌석수,
	CASE
		WHEN SEAT_COUNT BETWEEN 0 AND 30000 THEN 'S'
		ELSE(CASE
				WHEN SEAT_COUNT BETWEEN 30001 AND 50000 THEN 'M'
				ELSE 'L'
			 END)
	END AS 규모
FROM STADIUM;
--PLAYER 테이블에서 WEIGHT가 50이상 70이하면 'L'
--71이상 80이하면 'M' NULL이면(IS NULL) '미등록' 다 아니면 'H'
--별칭은 "체격"으로 주기
SELECT PLAYER_NAME 선수이름, WEIGHT||'kg' AS 몸무게,
	CASE
		WHEN WEIGHT BETWEEN 50 AND 70 THEN 'L'
		WHEN WEIGHT BETWEEN 71 AND 80 THEN 'M'
		ELSE(CASE
				WHEN WEIGHT IS NULL THEN '미등록'
				ELSE 'H'
			END)
	END AS 체격
FROM PLAYER;

--숫자형 함수(시험에 99% 출제) FROM DUAL
--절대값
SELECT ABS(-10) FROM DUAL;

--양의정수(1), 영(0), 음의정수(-1)
SELECT SIGN(-234), SIGN(0), SIGN(123) FROM DUAL;

--나머지(% 모듈러스)
SELECT MOD(10, 8) FROM DUAL;

--값보다 큰 최근접 정수
SELECT CEIL(3.14), CEIL(-3.14) FROM DUAL;

--값보다 작은 최근접 정수
SELECT FLOOR(3.14), FLOOR(-3.14) FROM DUAL;

--반올림
SELECT ROUND(3.5515616) FROM DUAL;
SELECT ROUND(3.4515616) FROM DUAL;

--버림
SELECT TRUNC(3.9) FROM DUAL;

--ROUND(값, 자릿수)
--몸무게를 소수점 첫째자리까지 반올림
SELECT ROUND(WEIGHT, 2) FROM PLAYER;
SELECT ROUND(10.256, 2) FROM DUAL;

--키는 소수점 둘째자리까지 반올림, 몸무게는 소수점 버림
SELECT ROUND(HEIGHT, 2) ||'cm' AS 키, TRUNC(WEIGHT, 0)||'kg' AS 몸무게 FROM PLAYER;

--NULL
--자동차 테이블 생성
CREATE TABLE CAR(
	ID NUMBER(3),
	BRAND VARCHAR2(20) NOT NULL,
	COLOR VARCHAR2(10),
	PRICE NUMBER(10),
	--제약조건
	CONSTRAINT CAR_PK PRIMARY KEY(ID)
);

ALTER TABLE CAR DROP CONSTRAINT SYS_C007049;
ALTER TABLE CAR MODIFY BRAND NOT NULL;

--PLAYER 테이블에서 POSITION이 NULL인 선수 검색
SELECT * FROM PLAYER WHERE "POSITION" IS NULL;

--PLAYER 테이블에서 POSITION이 NULL이면 '미정'으로 검색하기
SELECT NVL("POSITION", '미정') FROM PLAYER WHERE "POSITION" IS NULL;
SELECT PLAYER_NAME 선수이름, NVL("POSITION", '미정') 포지션 FROM PLAYER;

--PLAYER 테이블에서 POSITION이 NULL이면 '미정' 있으면 '확정'으로 검색하기
SELECT PLAYER_NAME 선수이름,
	NVL2("POSITION", '확정', '미정') 포지션
FROM PLAYER;

--PLAYER 테이블에서 NATION이 NULL이 아니면 등록
--NULL이면 미등록으로 변경 후 선수이름, 국가 검색하기
--별칭은 국가 등록 여부로 주기
SELECT PLAYER_NAME AS "선수 이름",
	NATION 국가,
	NVL2(NATION, '등록', '미등록') AS "국가 등록 여부"
	FROM PLAYER;






































