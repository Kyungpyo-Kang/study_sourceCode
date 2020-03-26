--PLAYER ���̺����� ���� �ִ� �������� ������ 
--TEAM_ID, REGION_NAME, PLAYER_NAME, WEIGTH �˻�(WHERE IN ����ϱ�)
SELECT T.TEAM_ID, T.REGION_NAME, P.PLAYER_NAME, P.WEIGHT
FROM TEAM T, PLAYER P
WHERE P.TEAM_ID = T.TEAM_ID AND
(P.TEAM_ID, P.WEIGHT) IN 
(SELECT TEAM_ID, MAX(WEIGHT) FROM PLAYER GROUP BY TEAM_ID);

--DEPT ���̺��� LOC�� ��� �޿��� �ݿø��� ����
--�� LOC�� SAL �� ���� �˻��ϱ�
SELECT D.LOC, ROUND(AVG(SAL)) "��� �޿�", SUM(SAL) "�� �޿�"
FROM EMP E JOIN DEPT D
ON E.DEPTNO = D.DEPTNO
GROUP BY D.LOC;

--EMP ���̺����� HIREDATE�� FORD�� �Ի�⵵�� ���� ��� ��ü ���� �˻�
SELECT * FROM EMP E
WHERE TO_CHAR(HIREDATE, 'YYYY-MM-DD')
LIKE(
(SELECT SUBSTR(TO_CHAR(HIREDATE, 'YYYY-MM-DD'), 1, 4)
FROM EMP WHERE ENAME = 'FORD')||'%');

SELECT TO_CHAR(HIREDATE) FROM EMP WHERE ENAME = 'FORD';

--JOBS ���̺����� JOB_TITLE�� ����� ��� �޿� �˻�
--JOB_TITLE�� ����
--���� : FROM -> WHERE -> GROUP BY -> HAVING -> SELECT -> ORDER BY
SELECT J.JOB_TITLE, AVG(E.SALARY)
FROM JOBS J JOIN EMPLOYEES E
ON J.JOB_ID = E.JOB_ID
GROUP BY JOB_TITLE
ORDER BY 1;

--AVG�Լ��� ���� �ʰ� PLAYER ���̺����� ������ ��� Ű ���ϱ�(NULL������)
SELECT ROUND(SUM(HEIGHT) / COUNT(HEIGHT)) ���Ű FROM PLAYER;

SELECT * FROM PLAYER;

