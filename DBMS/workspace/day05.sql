--PLAYER ���̺��� NATION�� NULL�� �ƴϸ� ���
--NULL�̸� �̵������ ���� �� �����̸�, ���� �˻��ϱ�
--CASE������ ���
--CASE WHEN THEN ELSE END
SELECT PLAYER_NAME, NATION, 
	CASE
		WHEN NATION IS NULL THEN '�̵��'
		ELSE '���'
	END AS "���� ��� ����"
FROM PLAYER;

--COALESCE(�ھ󷹽�) : ��ġ��, �����ϴ�
--NULL�� �ƴϸ� 1�� ����, NULL�̸� 2�� ����, �� �� NULL�̸� NULL
SELECT PLAYER_NAME, NICKNAME,
	COALESCE(NICKNAME, PLAYER_NAME) AS KNOWN
FROM PLAYER;

--PLAYER ���̺��� NICKNAME�� ������ '���� ����'���� ���� �� �˻�
SELECT PLAYER_NAME, NICKNAME,
	COALESCE(NICKNAME, '���� ����') AS ����
FROM PLAYER;

--���� �Լ�(NULL�� �������� �ʴ´�.)
--WHERE�������� ����� �� ����.
--�������� ���� �ϳ��� ������ ��Ÿ��
--AVG() ���
--MAX() �ִ�
--MIN() �ּڰ�
--SUM()	����
--COUNT() ����
SELECT AVG(HEIGHT), MAX(HEIGHT), MIN(HEIGHT), SUM(HEIGHT) FROM PLAYER;

SELECT * FROM PLAYER;

SELECT COUNT(HEIGHT) FROM PLAYER;

--PLAYER ���̺��� HEIGTH ���� �˻�(NULL�����ؼ� COUNT�ϱ�)
SELECT COUNT(NVL(HEIGHT, 0)) FROM PLAYER;

--ORDER BY : ����
--ASC : ��������(���� ����)
--DESC : ��������

--PLAYER ���̺��� Ű ������ �˻�(��������)
SELECT PLAYER_NAME, HEIGHT 
FROM PLAYER
WHERE HEIGHT IS NOT NULL
ORDER BY HEIGHT ASC;

--PLAYER ���̺��� Ű ��, ������ ��(��������)���� �˻�
--NULL�� �ƴ� ���� �˻�
--ù��° �÷���(Ʃ��)�� ������ �ι�° ������ �Ѵ�.
SELECT PLAYER_NAME, HEIGHT, WEIGHT 
FROM PLAYER
WHERE HEIGHT IS NOT NULL AND WEIGHT IS NOT NULL
ORDER BY HEIGHT, WEIGHT;

--GROUP BY : ~��(�� : ������ �� ���Ű)

--SELECT ??? FROM ???
--GROUP BY �÷���
--HAVING ���ǽ�

--PLAYER ���̺��� ������ �˻�
SELECT "POSITION"
FROM PLAYER
GROUP BY "POSITION"
HAVING "POSITION" IS NOT NULL;

--WHERE������ ������ ó���� �� �ִٸ� �ݵ�� WHERE������ ���� ó�����ش�.
--HAVING������ �� ȿ�����̴�.
SELECT "POSITION"
FROM PLAYER
WHERE "POSITION" IS NOT NULL
GROUP BY "POSITION";

--PLAYER ���̺��� �����԰� 80�̻��� �������� ���Ű�� 180�̻��� ������ �˻�
SELECT "POSITION", AVG(HEIGHT), MIN(WEIGHT)
FROM PLAYER
WHERE WEIGHT >= 80
GROUP BY "POSITION"
HAVING AVG(HEIGHT) >= 180;

--EMPLOYEES ���̺��� JOB_ID���� ��� SALARY�� 10000�̸���
--(SALARY �հ�, ���, �ִ�, �ּڰ�, JOB_ID�� ���) �˻��ϱ�
--JOB_ID ���ĺ� ������ ����(��������)
SELECT JOB_ID , SUM(SALARY), AVG(SALARY),
	MAX(SALARY), MIN(SALARY), COUNT(JOB_ID)
FROM EMPLOYEES
GROUP BY JOB_ID
HAVING AVG(SALARY) < 10000
ORDER BY JOB_ID;

--SUB_QUERY : SQL�� ���ο� SQL�� ����
--FROM��		: IN LINE VIEW
--SELECT��	: SCALAR
--WHERE��	: SUB_QUERY

--PLAYER ���̺��� TEAM_ID�� 'K01'�� ���� �߿� POSITION�� 'GK'�� ����
SELECT * FROM(
	SELECT * FROM PLAYER
	WHERE TEAM_ID = 'K01'
)
WHERE "POSITION" = 'GK';

--WHERE�� ����ϱ�
SELECT * FROM PLAYER
WHERE TEAM_ID = 'K01' AND "POSITION" = 'GK';

--PLAYER ���̺��� ���Ű���� ���� ���� �˻�
SELECT * FROM PLAYER
WHERE HEIGHT < (SELECT AVG(HEIGHT) FROM PLAYER);

--SCALAR SUB-QUERY
--��ü ��հ� �����Ǻ� ���Ű ���ϱ�
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
	ROUND(AVG(HEIGHT), 2) AS "��ü ���"
FROM PLAYER;

--PLAYER ���̺��� NICKNAME�� NULL�� �������� ���¹� ������ �г������� �ٲٱ�
UPDATE PLAYER
SET (NICKNAME) = (SELECT NICKNAME FROM PLAYER WHERE PLAYER_NAME = '���¹�')
WHERE NICKNAME IS NULL;

SELECT * FROM PLAYER;

--NICKNAME�� NULL�� �������� �̸��� ���¹����� �ٲٱ�
UPDATE PLAYER
SET (PLAYER_NAME, NICKNAME) =
(
	SELECT PLAYER_NAME, NICKNAME 
	FROM PLAYER 
	WHERE PLAYER_NAME = '���¹�'
)
WHERE NICKNAME IS NULL;

SELECT * FROM PLAYER;

--EMPLOYEES ���̺��� ��ձ޿����� ���� ������� �޿��� 10% �λ��ϱ�(UPDATE)

SELECT SALARY
FROM EMPLOYEES
WHERE SALARY < (SELECT AVG(SALARY) FROM EMPLOYEES);

UPDATE EMPLOYEES
SET SALARY = SALARY * 1.1
WHERE SALARY < (SELECT AVG(SALARY) FROM EMPLOYEES);

--PLAYER ���̺��� ���Ű���� ū ������ ����
--DELETE FROM ���̺� WHERE ����;
SELECT ROUND(AVG(HEIGHT), 2) FROM PLAYER;

DELETE FROM PLAYER
WHERE HEIGHT > (SELECT AVG(HEIGHT) FROM PLAYER);

SELECT MAX(HEIGHT) FROM PLAYER;

--������ �Լ�
--�ҹ���, �빮��, ASCII�ڵ�, CHR
SELECT LOWER('BUS'), UPPER('bus'), ASCII('A'), CHR(65)
FROM DUAL;














