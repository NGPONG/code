-------------------------------------------------------------------------------------------------------

-- ��ָ����/���ʽ/��ȡ����
-- ����/���ʽ/��  as  ����
select ProName as ���� from dbo.Product
select 5*5 as ����
select ����.ProName,����.* from dbo.Product as ����

-- ��ĳ�����м���һ�������У�������Ӧ���е�����
-- select  ����  from  ����
-- ע�⣺��û�������ĸ����е��������һ�������е����ݣ�ֻ����ӽ�ȥ��Ȼ���ѯ���������
select 'qweqwe',* from dbo.Product

-- ��ѯ����/ϵͳ����/���ʽ��ֵ/������������Ӧ��ֵ
-- select  ����/ϵͳ����/���ʽ/����/����
select 'sadasd' --����
select getdate() --ϵͳ����
select 1+3 --���ʽ
select ProName from dbo.Product --����

-------------------------------------------------------------------------------------------------------

-- �ۺϺ���

-- ȡ���е�����
-- select  count(����ֵ/*)  from  ����
-- count(*) : �ұ�����̵��н���������ͳ��
-- count(����ֵ) : �Գ����н���ͳ�ƣ���ͬ�� -> select '����' from ����
select count(1) as ���� from dbo.Product

-- ȡ����ָ�������ݵ�ƽ��ֵ
-- select  avg(����1),avg(����2)  from  ����
select avg(ProductID) as ƽ��ֵ1,avg(ListPrice) as ƽ��ֵ2 from SalesLT.Product

-- ȥ�������ݵ��ܺ�
-- select  sum(����1),sum(����2)  from  ����
select sum(ProductID) as �ܺ�1,sum(ListPrice) as �ܺ�2 from SalesLT.Product

-- ȡ�������ݵ����ֵ/��Сֵ
-- select  max/min(����1),max/min(����2)  from  ����
select max(ProductID) as ���ֵ,min(ListPrice) as ��Сֵ from SalesLT.Product

-------------------------------------------------------------------------------------------------------

-- ��ȡ������n�е�����
-- select  top  n  ����/*  from  ���� 
select top 2 * from SalesLT.Product

-- ָ�������� asc/�������� desc
-- select  ����  from  ����  order by  ����  asc/desc
select * from SalesLT.Product order by StandardCost
-- ��ָ�������е�ʱ��ע�⣺
-- ������ָ���Ķ����л�ϲ���һ������ı�׼
-- select  ����1,����2  from  ����  order by  ����1 asc/desc,����2 asc/desc
select StandardCost,ProductID from SalesLT.Product order by StandardCost asc,ProductID desc

-- top��order by�����ʹ��
select top 3 * from SalesLT.Product order by ProductID asc

-------------------------------------------------------------------------------------------------------

-- ȥ��ָ�������ظ�������
-- select  distinct  ����  from  ���� 
select distinct Color from SalesLT.Product
-- ��ָ�������е�ʱ��ע��
-- select  distinct  ����1,����2  from  ����
-- ��������е���һ��ȥ�ظ��ı�׼��Ȼ��ȥ���ÿһ������ñ�׼�ظ�����
select distinct Color,Name from SalesLT.Product

-------------------------------------------------------------------------------------------------------

-- �������˲�ѯ where

-- ���������ˣ� and���� or���� notȡ�ǣ����ȼ���not > and >or��
-- select  *  from  ����  where  ���ʽ
select * from SalesLT.Customer where CustomerID>10 and CustomerID <20 or LastName != 'Gee'
select * from SalesLT.Customer where not(CustomerID > 20)
-- �����ѯ��between and��in
-- select  ����  from  ����  where  ����  between  ����  and  ����
select * from SalesLT.Customer where CustomerID between 10 and 20

-- ģ����ѯ
-- ����ַ�����ѯ��ͨ�����
-- 1. 0�������ַ���%    2. ֻ��1���ַ���_     3. ���䣺[]
-- �����ַ�ת�壺'' = '  ��  [ [ ] = [ 
-- select  ����  from  ����  where  ����  like  ���ʽ(����������ʽ)
select * from SalesLT.Customer where FirstName like '%th%'
select * from SalesLT.Customer where FirstName like '_rash%'
select * from SalesLT.Customer where CompanyName like '%[0-9]%'
select * from SalesLT.Customer where CompanyName like '%[[]%' 

-- ��ѯ�����Ƿ�Ϊnull/not null
-- select  ����  from  ����  where  ����  is  null/not null
select * from SalesLT.Customer where MiddleName is not null

-------------------------------------------------------------------------------------------------------

-- ��������Ϣ�ķ���
-- select  �������/�ۺϺ���  from  ����  group by  �������
-- ע�⣺1. ע��SQL����ִ��˳��
--           2. select�������д �����������������group by ������
select Title,count(1),sum(CustomerID) from SalesLT.Customer group by Title  having count(1) >5

-- �����������
-- select  �������/�ۺϺ���  from  ����   group by  �������  having  �ۺϺ������ʽ
-- ע�⣺1. having��Ϊ�����˹�����,Ҳ����˵�Ƿ�����Ҫ������,���Ա�����group by����
--			  2. ͨ��having���ۺϺ����ļ�����Ҳ�ܵ���������ʹ�ã�����˾ۺϺ����޷�����where������
select SalesPerson,count(1) from SalesLT.Customer group by SalesPerson having count(1) >75

-------------------------------------------------------------------------------------------------------

-- �������е�ֵ�ϲ���һ���е�ֵ
-- select  ����1 + ����2  from  ����
-- ע�⣺����ת�������⣬�����ݵ����ͣ�int��nvarchar����Ҫ����ת�����ܺϲ�
select LastName+Title from SalesLT.Customer

-- ��ͬ����֮���ת�������ַ���
-- convert  (  Ŀ������  ,  ��ת��������  ,  ��ʽ�淶  )
-- cast  (  ��ת��������  as  Ŀ������  )
select convert(nvarchar(30),CustomerID)+FirstName from SalesLT.Customer
select cast(CustomerID as nvarchar(32)) + FirstName from SalesLT.Customer

-------------------------------------------------------------------------------------------------------

-- ����һ���������Copy���������ٴ�����ķ�ʽ
-- select  ����  �µı���  from  �ɵı���
select EmpId,EmpName into Employee3 from dbo.Employee where EmpId > 5

-------------------------------------------------------------------------------------------------------

-- ����һ��������ĳ������
-- insert into  ����(����1,����2,����3,....)  values(ֵ1,ֵ2,ֵ3,....)����ָ�����������µ�һ������
-- ����������ݵ�ĳ���еı�ʶΪ���Զ����� ��ʱ�����ǿ������������ַ�������ֹ����

-->1. ��дӵ���Զ��������е�����
insert into Employee (EmpName,EmpGender,EmpAddress,EmpAge) values('2','3','4',5)

-->2. �Ѹñ��identity_Insert��
set identity_Insert Employee on -- ����Ϊ����
insert into Employee(EmpId,EmpName,EmpGender,EmpAddress,EmpAge) values(1,'2','3','4',5)
set identity_Insert Employee off -- ����Ϊ�ر�

-------------------------------------------------------------------------------------------------------

-- ���������������������
-- select  ����  from  ����1
-- union all(��ȥ�ظ�)/union(ȥ�ظ���Ч�ʵ�)
-- select  ����  from  ����2
select * from dbo.Employee
union all
select * from dbo.EmployeeNew

-------------------------------------------------------------------------------------------------------

-- ��������һ���Ѵ��ڵı��������һ�����е�����
-- insert  into  ��1 (����1,����2����)  select  ����1,����2,����  from  ��2
-- ��ĳ���еı�ʾΪ�Զ�������ʱ����Ҫ����identity_Insert��������ʱ��ر�
set identity_Insert Employee on --����Ϊ����

insert into Employee(EmpId,EmpName,EmpAddress,EmpAge) 
select EmpId,EmpName,EmpAddress,EmpAge from dbo.EmployeeNew

insert into Employee(EmpId,EmpName,EmpAddress,EmpAge)
select 1,N'����',N'����',10 union
select 2,N'����',N'asd',20 union
select 3,'asd','sdff',40

set identity_Insert Employee off --����Ϊ�ر�

-------------------------------------------------------------------------------------------------------

-- ��ȡ��ǰʱ�� getdate()
select getdate()

-- ��ָ�������У�����ָ�����ڵ�λ��ʱ��
-- dateadd(  ���ڵ�λ  ,  �������  ,  �����ַ���  )
select dateadd(second,1,'2018-3-11')

-- ����������ںͿ�ʼ���ڵ�ʱ�䵥λ��
-- �������� - ��ʼ����
-- �����Ϊ��0 �Ķ�ʱ��֤��Ϊ����/��/�ꡭ
-- datediff(  ���ڵ�λ  ,  ��ʼ����  ,  ��������  )
select datediff(day,'2018-3-11','2018-2-5')

-- ��ȡһ�������ַ����У�������ָ�����ڵ�λ������
-- datepart(  ���ڵ�λ  ,  �����ַ���)
select datepart(day,'2018-3-11')

-- ��ȡһ�������ַ�������/��/�ա�
-- ���ڵ�λ(  �����ַ���  )
select year('2018-3-11')

-------------------------------------------------------------------------------------------------------

-- ָ�� ��/���� ��ɴ�д/Сд
-- upper/lower(  ����/����  )
select upper('asdasd'),* from dbo.Employee
select lower('ASDAS'),* from dbo.Employee

-- ��ȡָ�� ��/���� �� ���/�ұ� ��ʼ��ȡn���ַ�������
-- left/right(  ����/����  ,  n���ַ�  )
select left(EmpName,2),* from dbo.Employee
select right(EmpName,2),* from dbo.Employee

-- ȥ��ָ�� ��/���� �� ���/�ұ� �Ŀո�
-- Ltrim/Rtrim(  ����/����  )
select Ltrim('                     qweqqweqwe                          ')

-------------------------------------------------------------------------------------------------------
-- join on
use damon

select 
	dbo.Customer.CustomerName,
	dbo.Product.ProductName,
	dbo.Product.ProductPrice 
from 
	dbo.Customer,
	dbo.Product 
where 
	dbo.Customer.CutomerID = dbo.Product.CustomerID

 use [damon]
select 
	dbo.Customer.CustomerName,
	dbo.Customer.CustomerAge,
	dbo.Product.ProductName,
	dbo.Product.ProductPrice 
from 
	dbo.Product 
left join 
	dbo.Customer
on 
	dbo.Product.CustomerID = dbo.Customer.CutomerID


use [AdventureWorksLT2008]

select SalesLT.SalesOrderHeader.SalesOrderNumber,SalesLT.Customer.FirstName from SalesLT.SalesOrderHeader join SalesLT.Customer on SalesLT.Customer.CustomerID = SalesLT.SalesOrderHeader.CustomerID

-------------------------------------------------------------------------------------------------------
-- ����������ϰ��
-- database��Test1
-- table��CallRecords

select * from dbo.CallRecords

----��ѯͨ��ʱ�����5����¼
select top 5 datediff(second,StartDateTime,EndDateTime) as ʱ�� from dbo.CallRecords order by ʱ�� desc

----��ѯ��0��ͷ��ͨ����ʱ,����Ϊ���㵥λ
select sum(datediff(second,StartDateTime,EndDateTime)) from dbo.CallRecords where TelNum like '0%'

----��ѯ2010��7��ͨ����ʱ������ǰ��������Ա�ı��
select top 2 CallerNumber,sum(datediff(second,StartDateTime,EndDateTime)) as ͨ����ʱ�� from dbo.CallRecords where datepart(month,StartDateTime) = 7 group by CallerNumber order by ͨ����ʱ�� desc

----��ѯ2010��7�²���绰��������ǰ��������Ա�ı��
select top 2 CallerNumber,Count(1) from dbo.CallRecords where datepart(month,StartDateTime) = 7 group by CallerNumber order by count(1) desc
