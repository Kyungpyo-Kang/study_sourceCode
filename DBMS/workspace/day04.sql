--AS(ALIAS) : ��Ī
--SELECT�� : AS �ڿ� �Ǵ� �� ĭ ���� �ۼ�
--FROM�� : �� ĭ ���� �ۼ�

SELECT PLAYER_ID AS "���� ��ȣ", PLAYER_NAME �̸� FROM PLAYER;

--PLAYER ���̺��� BACK_NO�� "���ȣ"��, NICKNAME�� "���� ����"���� �ٲ㼭 �˻�
SELECT BACK_NO ���ȣ, NICKNAME AS "���� ����" FROM PLAYER;

--PLAYER ���̺��� �����̸���, TEAM ���̺��� �ּҸ� �˻�
SELECT P.PLAYER_NAME, T.ADDRESS FROM PLAYER P, TEAM T;

--SELECT P.TEAM_ID, T.TEAM_ID FROM PLAYER P, TEAM T;

SELECT * FROM TEAM;

--STADIUM ���̺��� ADDRESS��, TEAM���̺��� TEL �˻�
SELECT S.ADDRESS AS "����� �ּ�", T.TEL ��ȭ��ȣ FROM STADIUM S, TEAM T;

--CONCATENATION(����)
SELECT PLAYER_NAME||'������ '||NICKNAME AS ���� FROM PLAYER;

--LIKE : ���Ե� ���ڿ��� ���� ã��
-- % : ��� ��
-- '%A' : A�� ������ ��� ��(FDFFEWSDA, SADFSA,QE34A)
-- '_A' : A�� ������ �� �ڸ��� ��(AA, 2A, PA)

SELECT * FROM TEAM WHERE TEAM_NAME LIKE '%����';
SELECT * FROM PLAYER WHERE PLAYER_NAME LIKE('��%') AND PLAYER_NAME LIKE('��_');

--PLAYER ���̺��� �̾� ã��
SELECT * FROM PLAYER WHERE PLAYER_NAME LIKE('��%');
--PLAYER ���̺��� �达�� �̾� ã��
SELECT * FROM PLAYER WHERE PLAYER_NAME LIKE('��%') OR PLAYER_NAME LIKE('��%');
--PLAYER ���̺��� �达�� �ƴ� ��� ã��(NOT)
SELECT * FROM PLAYER WHERE NOT PLAYER_NAME LIKE('��%');

--CASE��
--CASE WHEN THEN ELSE END
--CASE WHEN ���ǽ� THEN TRUE ELSE FALSE END
--EMP ���̺��� SAL 3000�̻��̸� HIGH 1000�̻��̸� MID �� �ƴϸ� LOW
SELECT ENAME �����, SAL �޿�,
	CASE
	WHEN SAL >= 3000 THEN 'HIGH'
	WHEN SAL >= 1000 THEN 'MID'
	ELSE 'LOW'
	END AS Ŭ��
FROM EMP;

--��ø CASE��(Nested CASE)
-- EMP ���̺��� SAL�� 2000�̻��̸� ���ʽ� 1000
-- SAL 1000�̻��̸� ���ʽ� 500
-- �� �ƴϸ� 0

SELECT ENAME �����, SAL �޿�,
	CASE
		WHEN SAL >= 2000 THEN 1000
		ELSE (CASE
				WHEN SAL >= 1000 THEN 500
				ELSE 0
				END
			 )
	END AS ���ʽ�
FROM EMP;

--�ǽ�
--STADIUM ���̺��� SEAT_COUNT�� 0�̻� 30000���ϸ� 'S'
--30001�̻� 50000���ϸ� 'M' �� �ƴϸ� 'L'
SELECT STADIUM_NAME �����, SEAT_COUNT �¼���,
	CASE
		WHEN SEAT_COUNT BETWEEN 0 AND 30000 THEN 'S'
		ELSE(CASE
				WHEN SEAT_COUNT BETWEEN 30001 AND 50000 THEN 'M'
				ELSE 'L'
			 END)
	END AS �Ը�
FROM STADIUM;
--PLAYER ���̺��� WEIGHT�� 50�̻� 70���ϸ� 'L'
--71�̻� 80���ϸ� 'M' NULL�̸�(IS NULL) '�̵��' �� �ƴϸ� 'H'
--��Ī�� "ü��"���� �ֱ�
SELECT PLAYER_NAME �����̸�, WEIGHT||'kg' AS ������,
	CASE
		WHEN WEIGHT BETWEEN 50 AND 70 THEN 'L'
		WHEN WEIGHT BETWEEN 71 AND 80 THEN 'M'
		ELSE(CASE
				WHEN WEIGHT IS NULL THEN '�̵��'
				ELSE 'H'
			END)
	END AS ü��
FROM PLAYER;

--������ �Լ�(���迡 99% ����) FROM DUAL
--���밪
SELECT ABS(-10) FROM DUAL;

--��������(1), ��(0), ��������(-1)
SELECT SIGN(-234), SIGN(0), SIGN(123) FROM DUAL;

--������(% ��ⷯ��)
SELECT MOD(10, 8) FROM DUAL;

--������ ū �ֱ��� ����
SELECT CEIL(3.14), CEIL(-3.14) FROM DUAL;

--������ ���� �ֱ��� ����
SELECT FLOOR(3.14), FLOOR(-3.14) FROM DUAL;

--�ݿø�
SELECT ROUND(3.5515616) FROM DUAL;
SELECT ROUND(3.4515616) FROM DUAL;

--����
SELECT TRUNC(3.9) FROM DUAL;

--ROUND(��, �ڸ���)
--�����Ը� �Ҽ��� ù°�ڸ����� �ݿø�
SELECT ROUND(WEIGHT, 2) FROM PLAYER;
SELECT ROUND(10.256, 2) FROM DUAL;

--Ű�� �Ҽ��� ��°�ڸ����� �ݿø�, �����Դ� �Ҽ��� ����
SELECT ROUND(HEIGHT, 2) ||'cm' AS Ű, TRUNC(WEIGHT, 0)||'kg' AS ������ FROM PLAYER;

--NULL
--�ڵ��� ���̺� ����
CREATE TABLE CAR(
	ID NUMBER(3),
	BRAND VARCHAR2(20) NOT NULL,
	COLOR VARCHAR2(10),
	PRICE NUMBER(10),
	--��������
	CONSTRAINT CAR_PK PRIMARY KEY(ID)
);

ALTER TABLE CAR DROP CONSTRAINT SYS_C007049;
ALTER TABLE CAR MODIFY BRAND NOT NULL;

--PLAYER ���̺��� POSITION�� NULL�� ���� �˻�
SELECT * FROM PLAYER WHERE "POSITION" IS NULL;

--PLAYER ���̺��� POSITION�� NULL�̸� '����'���� �˻��ϱ�
SELECT NVL("POSITION", '����') FROM PLAYER WHERE "POSITION" IS NULL;
SELECT PLAYER_NAME �����̸�, NVL("POSITION", '����') ������ FROM PLAYER;

--PLAYER ���̺��� POSITION�� NULL�̸� '����' ������ 'Ȯ��'���� �˻��ϱ�
SELECT PLAYER_NAME �����̸�,
	NVL2("POSITION", 'Ȯ��', '����') ������
FROM PLAYER;

--PLAYER ���̺��� NATION�� NULL�� �ƴϸ� ���
--NULL�̸� �̵������ ���� �� �����̸�, ���� �˻��ϱ�
--��Ī�� ���� ��� ���η� �ֱ�
SELECT PLAYER_NAME AS "���� �̸�",
	NATION ����,
	NVL2(NATION, '���', '�̵��') AS "���� ��� ����"
	FROM PLAYER;






































