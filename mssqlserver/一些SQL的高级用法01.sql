--select * from dbo.UserInfo


---- �ж�һ�ű��У�ĳһ������������ĺ���
---- �����÷�
---- �÷�һ��������c#�е� switch case
---- select  case  ����  when  ��������Ӧ��ֵ  then  ����ĺ���  else  ����ĺ���  end  from  ����
--select *,case DelFlag when 0 then N'δɾ��' when 1 then N'ɾ��' else N'δ֪' end as N'ɾ��״̬' from dbo.UserInfo




---- �ж�һ�ű��У�ĳһ������������ĺ���
---- �����÷�
---- �÷�����������c#�е� if - else if - else
---- select  case  when  ��������Ӧ��ֵ�ı��ʽ  then  ����ĺ���  else  ����ĺ���  end  from  ����
--select *,case when DelFlag < 1 then N'δɾ��' when DelFlag=1 then N'ɾ��' else N'���ɾ��' end as N'ɾ��״̬' from dbo.UserInfo





---- ����һ�����������Ҹ�������ֵ������ӡ����

---- �������� : declare  @������  ����
--declare @variable int

---- ���ַ�ʽ��������ֵ : 
---- 1. set  @������  =  ֵ
--set @variable = (select count(1) from dbo.UserInfo where DelFlag <1)
---- 2. select  @������  =  ֵ
--select @variable = 10

---- ��ӡ : print  ����
--print @variable





---- if  else if  else / if else  �����жϵ�ʹ��
---- if( ���ʽ )
----		begin  
----			SQL���  
----		end
---- else if( ���ʽ )
----		begin  
----			SQL���  
----		end
---- else
----		begin 
----			SQL���  
----		end

--declare @n int -- ��������
--set @n = 10 -- ��������ֵ
--if(@n = 10)
--	begin
--		select * from dbo.UserInfo
--	end
--else if(@n <10)
--	begin
--		select UserName from dbo.UserInfo
--	end
--else
--	begin
--		select ID from dbo.UserInfo
--	end

	 



---- whileѭ����ʹ��
---- while( ���ʽ )
----		begin
----			SQL���
----		end
--declare @i int
--select @i = 0
--while(@i<100)
--	begin
--		print @i
--		select @i=@i+1
--	end






--use [AdventureWorksLT2008]
---- �Ӳ�ѯ
---- 1. ��һ����ѯ�Ľ�������صı��������β�ѯ����ı���ʹ��
---- ע�⣺�����Ӳ�ѯ��������ʹ�õ�ʱ�򣬱����� as ��Ϊ��ѯ�����صı���һ������
--select * from (select CustomerID from SalesLT.Customer where Title = 'Mr.' ) as T where T.CustomerID < 50

---- 2. ��һ����ѯ�Ľ��������һ�����ʽ��ʹ��
---- ע�⣺�Ӳ�ѯ�����ص��У���������β�ѯ�е� where/haveing�� �������жϵ������Ӧ

---- ���β�ѯ�ж϶��β�ѯ�ı�������CustomerID�����Ӳ�ѯ�����ص�ƽ����������
--select * from SalesLT.Customer where CustomerID > (select avg(CustomerID) from SalesLT.Customer )

---- ���β�ѯͨ�� in ���ж϶��β�ѯ�ı��е�CompanyName���У������Ӳ�ѯ�����ص�CompanyName�е�����
--select * from SalesLT.Customer where CompanyName in
--(
-- select CompanyName from SalesLT.Customer group by CompanyName having count(1) >=2
-- )


---- ��ѯ�˿ͱ�������ͬһ�ҹ�˾���������˿͵Ĺ�˾����
--select * from SalesLT.Customer where CompanyName in( select CompanyName from SalesLT.Customer group by CompanyName having count(1) >=2)

---- ��ѯ�˿ͱ���  ��ͬ��˾�������� �˿���Ϣ
--select * from SalesLT.Customer where CompanyName =( select top 1 CompanyName from SalesLT.Customer group by CompanyName order by count(1) desc )

---- ��ѯ ��ͬ��˾�������Ĺ˿͵Ķ�����Ϣ
--select * from SalesLT.SalesOrderHeader where CustomerID in
--(
--select CustomerID from SalesLT.Customer where CompanyName in ( select top 1 CompanyName from SalesLT.Customer group by CompanyName order by Count(1) desc)
--)

--use damon
---- ��ѯɽ��ʡ�����г��е���Ϣ
--select * from dbo.AreaFull where AreaPid in ( select AreaId from dbo.AreaFull where AreaName = N'ɽ��ʡ')

---- --��ѯɽ��ʡ�������ؼ��е�
--select * from dbo.AreaFull where AreaPid in
--(
--select AreaId from dbo.AreaFull where AreaPid in ( select AreaId from dbo.AreaFull where AreaName = N'ɽ��ʡ')
--)
--and AreaName like '%��'







---- ˫order by�����ҳ�� : Խ����������ȡ������

---- ȡ�� m ҳ�����ݣ�ÿҳ�� n ������
---- select  top  n  *  from  ����  where  ����ID  not  in
---- (
---- select  top  ( ( m - 1 ) * n )  ����ID  from  ����  order  by  ����ID
---- )
---- order  by  ����ID
---- n = ÿҳ�м�������     m = ȡ�ڼ�ҳ������

---- ���´����Ҫ��Ϊ��ȡ��4ҳ�����ݣ�ÿҳ������3��
--select top 3 * from dbo.UserInfo where ID not in --���β�ѯ����ȡ������
--(
--select top ((4-1)*3) ID from dbo.UserInfo order by ID --�Ӳ�ѯ�Ľ����ʾ��ҪԽ��������
--)
--order by ID

---- row_number() over() �����ķ�ҳ����

---- ȡ�� m ҳ�����ݣ�ÿҳ�� n ������
---- select  ����  from
---- ( select  ���� , row_number()  over( order by ���� )  as  �Զ�������R  from  ���� )  as  �Զ������T
---- where  �Զ�������R  between  ( ( m - 1 ) * n + 1 )  and  ( n*m )
---- n = ÿҳ�м�������     m = ȡ�ڼ�ҳ������

---- ���´����Ҫ��Ϊ��ȡ��5ҳ�����ݣ�ÿҳ������3��
--select * from
--(select *,row_number() over(order by ID) as num from dbo.UserInfo) as T
--where T.num between ((5-1)*3+1) and (5*3)









---- row_number()��ʹ�ñ�����Ͽ����������ҿ����������������дһ��order by
---- select  row_number()  over( order  by  ���� )
--select row_number() over( order by ID ) from dbo.UserInfo

---- �������� over()
---- select  ������ , over( ѡ�� )  from  ����
--select count(1) over(),* from dbo.UserInfo




-- inner join : ������
-- ͨ��һ�� on �������ж������������е�����
-- ����ֻ�з���on���������ݲŻ�����������
select * from dbo.Product as P inner join dbo.Category as C on P.CategoryID = C.CatId

-- right join : ������
-- ͨ��һ�� on �������ж������������е�����
-- ����Ҫ�Ǵ��ڲ�ƥ�� on������ Ҳ�᷵�����ݣ�����ֻ�᷵���ұ�����ݣ���������Ϊnull
select * from dbo.Product as P right join dbo.Category as C on P.CategoryID = C.CatId

-- left join : ������
-- ͨ��һ�� on �������ж������������е�����
-- ����Ҫ�Ǵ��ڲ�ƥ�� on������ Ҳ�᷵�����ݣ�����ֻ�᷵���������ݣ��ұ������Ϊnull
select * from dbo.Product as P left join dbo.Category as C on P.CategoryID = C.CatId

-- full join : ȫ����
-- ͨ��һ�� on �������ж������������е�����
-- ����Ҫ�Ǵ��ڲ�ƥ�� on������ Ҳ�᷵�����ݣ��������ұ�����ݶ����أ����Ҷ�����nullֵ
-- full joinȫ���ӿ��Կ����� left join �� right join �ĺϲ�ʹ��
select * from dbo.Product as P full join dbo.Category as C on P.CategoryID = C.CatId


-- cross join : �ѿ���������
-- ��������������ݣ�ͨ���ѿ���������������п���ƥ�������
select * from dbo.Product as P
cross join dbo.Category as C