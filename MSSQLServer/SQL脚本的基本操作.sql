-- �������ݿ�
create database Test1

--------------------------------------------------------------------------------------------

-- ɾ�����ݿ�
drop database Test1

--------------------------------------------------------------------------------------------

-- �������ݿ�����ݿ����־�ļ����������ǵ���ϸ����
create database Test2
on
(
	name='Test2',
	size=5MB,
	filegrowth=2MB,
	fileName='C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\DATA\Test2.mdf'
)
log on
(
	name='Test2_log',
	size=2MB,
	filegrowth=2MB,
	fileName='C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\DATA\Test2_log.ldf'
)

--------------------------------------------------------------------------------------------

-- �������ݿ�
use Test1

--------------------------------------------------------------------------------------------

-- ����ִ���������
go

--------------------------------------------------------------------------------------------

-- ������
	--primary key		����Ϊ����
	--identity(n,m)		�����Ƿ��Զ�����
	--null/not null		���ÿɿ�Լ��
	--default(n)			����Ĭ��ֵԼ��
create table Employee
(
--	���� ���� (һЩԼ��) null/not null 
	EmpId int primary key identity(1,1) not null,
	EmpName nvarchar(32) null,
	EmpGender nchar(1) null,
	EmpAddress nvarchar(32) null,
	DelFlag smallint default(0) not null,
)

--------------------------------------------------------------------------------------------

-- ��ѯ���е�����
-- select ���� from ���� where �������ʽ
	--select	ѡ���У�*�Ŵ���������
	--form		�����ĸ���
	--where	�������ʽ�����ҷ��������������ڵ��У�����where����������������
select EmpId, EmpName, EmpGender, EmpAddress from dbo.Employee where EmpId>3

--------------------------------------------------------------------------------------------

-- ����������ĳ������
-- insert into  ����(����1,����2,����3,....)  values(ֵ1,ֵ2,ֵ3,....)����ָ�����������µ�һ������
-- ��ĳ���е�����Ϊ�Զ�������ΪĬ��ֵԼ����ʱ������д���е�������ֵ
insert into dbo.Employee (EmpName,EmpAddress,EmpGender) values (N'���»�',N'���',N'��')

-------------------------------------------------------------------------------------------

-- ɾ�����е�����
-- delete from ���� where �������ʽ��ɾ���ñ�������ָ����������һ��
-- һ��Ҫ��where
delete from dbo.EmployeeInfo where EmpID = 6

--------------------------------------------------------------------------------------------

-- �ı���е�����
-- update ���� set ����1=���ĵ�ֵ,����2=���ĵ�ֵ2 where �������ʽ
update dbo.Employee set EmpName = N'����' where EmpAge = 236

--------------------------------------------------------------------------------------------

