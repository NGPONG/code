
-- ����ȫ����ʱ��
-- �����ʹ�����ͨ�ı���ͬ��ֻ��Ҫ�ڴ����ı���ǰ��+����#

-- ��ʽһ��
create table ##TemporaryTable
(
	TemporaryID int not null,
	TemporaryName nvarchar(32) not null
)
-- ��ʽ����
select * into ##TemporaryTable from dbo.UserInfo

-- ֻ�е������û����Ͽ��˶�ȫ����ʱ������ӺͻỰ�Ĳ�������ʱ��Ż��Զ��ͷŵ�
-- ����Ҳ�����ֶ����ͷŵ�ȫ����ʱ��
drop table ##TemporaryTable










-- SQL�в����쳣�ķ�������c#�﷨����
-- begin try
-- SQL���
-- end try
-- begin catch
-- SQL���
-- end catch
begin try
	update dbo.UserInfo set ErrorTime=N'����' where ID=2
end try
begin catch
	print N'ʧ����'
end catch












begin try
	begin transaction -- ��������
		update dbo.UserInfo set UserName=N'asqw' where ID=2;
		update dbo.UserInfo set ErrorTime=N'����' where ID=3
	commit transaction -- �ύ����
end try
begin catch
	rollback transaction -- �ع�����
end catch
go














-- �ж�ϵͳ�����ж����У��Ƿ��Ѵ�����Ҫ�����Ĵ洢���̵����֣�������ڣ���ɾ���ٴ���һ���µ�
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' �洢���̵����� ' ) )   drop  procedure  �洢���̵�����
-- exists()���жϵ�ʱ�����ʹ���������
-- sys.all_objects������ϵͳ�е����ж���
if(exists(select * from sys.all_objects where name='Pro_UserInfo_GetUserInfo'))
	drop procedure Pro_UserInfo_GetUserInfo
go
-- �����洢����
-- create  procedure  �洢��������
-- ���������  �����������
-- ���������  ����������ͣ����洢�����д��������������ô�ڴ洢����ִ�е�SQL�ű���as -> go������ǰ������Ϊ�丳ֵ��
-- as
-- �Լ������һ��SQL�ű�
-- go
create procedure Pro_UserInfo_GetUserInfo
@Num int,
@test int output
as
select * from dbo.UserInfo where ID < @Num
set @test=(select count(1) from dbo.UserInfo where ID < @Num)
go
-- ���ô洢����
-- exec  �洢������  ������� , ��������� out
-- �������ڴ洢������д����������������������ô�ڵ��õ�ʱ��Ҳ��Ҫ�ں��洫��
-- ��������һ���洢�����ж�����һ�������������ô�ڵ��ô洢����ǰ��������Ҫ�Լ�����һ������
-- Ȼ����ִ�д洢���̵ĺ���д����������� out
-- ���洢����ִ����ɺ����ǾͿ��Ի�ȡ���ô洢���������صĲ�����ֵ
declare @test int
exec Pro_UserInfo_GetUserInfo 10,@test out
print @test


-- ������ҳ�洢����
if(exists(select * from sys.all_objects where name='Pro_UserInfo_GetPages'))
	drop procedure Pro_UserInfo_GetUserInfo
go
create procedure Pro_UserInfo_GetPages
@pageIndex int,
@pageSize int,
@count int output
as 
	select * from
	(select *,row_number() over(order by ID) as rowNumber from dbo.UserInfo) as T
	where T.rowNumber between ( ( @pageIndex - 1 )*@pageSize + 1 ) and ( @pageIndex * @pageSize )
	--���������ֵ
	set @count=(select count(1) from dbo.UserInfo)
go

--���÷�ҳ�洢����
declare @count int
exec Pro_UserInfo_GetPages 7,3,@count out
print @count


-- ����ϵͳ�Ĵ洢����
exec sp_databases														-- �鿴���е����ݿ�

exec sp_tables																-- �鿴ָ�����ݿ��е����еı�

exec sp_columns UserInfo,dbo,damon,UserName		-- �鿴��

exec sp_helpindex 'UserInfo'										-- �鿴����

exec sp_helpconstraint 'UserInfo'								-- �鿴Լ��

exec sp_stored_procedures											-- �鿴�洢����

exec sp_helptext 'Pro_UserInfo_GetPages'					-- �鿴�洢���̵���ϸ����

exec sp_rename 'ProductUpdate','Product'				-- ���� ���������С��������ȵ�����

exec sp_renamedb 'damon','demo'							-- �������ݿ������

exec sp_defaultdb 'master','myDataBase'					-- ���ĵ�¼��Ĭ�����ݿ������

exec sp_helpdb 'damon'												-- �鿴���ݿ������������Ϣ


-- �洢���̶�̬��ִ��SQL�ű�

-- ��ʽһ��ͨ��������ִ��
-- ע�⣺��������
declare @SqlsScript nvarchar(max) -- �������
select @SqlSscript = 'select * from dbo.UserInfo' -- ������ֵ
exec (@SqlSscript) -- ��ִ̬��SQL�ű�

-- ��ʽ����ֱ����д�ַ���
-- ע�⣺ʹ������
exec ('select * from dbo.UserInfo') -- ��ִ̬��SQL�ű�

-- ��ʽ����ͨ��ϵͳ�洢���������� (�����Ը�ǿ)
declare @SqlScript nvarchar(max) -- �������
select @SqlScript = 'select * from dbo.UserInfo' -- ������ֵ
exec sp_executesql @SqlScript -- ��ִ̬��SQL�ű�
go












-- ����ֵ����
-- �ж�ϵͳ�����ж����У��Ƿ��Ѵ�����Ҫ�����ĺ��������֣�������ڣ���ɾ���ٴ���һ���µ�
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' ���������� ' ) )   drop  function  ����������
-- exists()���жϵ�ʱ�����ʹ���������
-- sys.all_objects������ϵͳ�е����ж���
if(exists(select * from sys.all_objects where name='Fun_GetUserInfoCount'))
drop function Fun_GetUserInfoCount
go
-- ��������ֵ����
-- create  function  ������  (������  ��������)
-- returns  ����ֵ����
-- as
-- begin
--	�Լ������һ��SQL�ű�
-- return  ����
-- end
create function Fun_GetUserInfoCount(@Number int)
returns int
as
begin
	declare @result int
	select @result = (select count(1) from dbo.UserInfo where DelFlag = @Number )
	return @result
end
go
-- ���ñ���ֵ����
-- select  ������ ( ���� )
select dbo.Fun_GetUserInfoCount(1)


-- ��ֵ����
-- �ж�ϵͳ�����ж����У��Ƿ��Ѵ�����Ҫ�����ĺ��������֣�������ڣ���ɾ���ٴ���һ���µ�
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' ���������� ' ) )   drop  function  ����������
-- exists()���жϵ�ʱ�����ʹ���������
-- sys.all_objects������ϵͳ�е����ж���
if(exists(select * from sys.all_objects where name = 'Fun_UserInfo'))
-- ɾ������
-- drop  function  ������
drop function Fun_UserInfo
go
-- ������ֵ����
-- create  function  ������  (������  ��������)
-- returns  table
-- as
-- return  ��ѯ������ر��SQL�ű�
create function Fun_UserInfo(@Num int)
returns table
as
	return select * from dbo.UserInfo where DelFlag = @Num
go

-- ���ñ�ֵ����
-- select  ����  from  ��ֵ���� ( ���� )
select * from Fun_UserInfo(0)











-- �������Ҳ�ܹ�����������
-- ʹ��inserted������ȡ��ǰ�����������������Ӧ�е�ID
-- ֻ��insertʹ�ã���
insert into dbo.UserInfo(UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag) output inserted.ID values ('qwesaf','qwreqr14',0,'2018-03-16 19:34:26.000',1)

-- ������
-- �ж�ϵͳ�����ж����У��Ƿ��Ѵ�����Ҫ�����Ĵ����������֣�������ڣ���ɾ���ٴ���һ���µ�
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' ���������� ' ) )   drop  function  ����������
-- exists()���жϵ�ʱ�����ʹ���������
-- sys.all_objects������ϵͳ�е����ж���
if(exists(select *  from sys.all_objects where name='Tr_UserInfo_Insert'))
-- ɾ��������
-- drop  trigger  ��������
drop trigger Tr_UserInfo_Insert
go
-- ���� for ������
-- create  trigger  ��������  on  ����
-- for  delete��update��insert����
-- as
-- begin
--	�Լ�����ĵ��ɹ���������������ִ�е�SQL�ű�
-- end
create trigger Tr_UserInfo_Insert on dbo.UserInfo
for insert
as
begin
	declare @ID int
	select @ID = (select ID from inserted)

	update dbo.UserInfo set UserName = UserName + cast(getdate() as nvarchar(max)) where ID = @ID		
end
-- �������������¼�
-- ��Ϊ���Ƕ���Ĵ�������insert�ģ����Ե�����ִ��insert����ʱ�򣬾ͻ��Զ�����������
insert into dbo.UserInfo(UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag) values('qweqsdd','12sd',0,getdate(),0)
go



create trigger Tr_UserInfo_Update on dbo.UserInfo
for Update
as
begin
	declare @DUserName nvarchar(32)
	declare @DUserPassWord nvarchar(32)

	select @DUserName = (select UserName from deleted)
	select @DUserPassWord = (select UserPassWord from deleted)

	declare @IUserName nvarchar(32)
	declare @IUserPaswWord nvarchar(32)

	select @IUserName = (select UserName from inserted)
	select @IUserPaswWord = (select UserPassWord from inserted)

	declare @ID int
	select @ID = (select ID from inserted)

	update dbo.UserInfo set UserName = @DUserName+@IUserName,UserPassWord = @DUserPassWord + @IUserPaswWord from dbo.UserInfo where ID = @ID
end

update dbo.UserInfo set UserName = N'�޸��ˣ�',UserPassWord = N'��Ҳ���޸��ˣ�' from dbo.UserInfo where ID = 3
go



-- ������
-- �ж�ϵͳ�����ж����У��Ƿ��Ѵ�����Ҫ�����Ĵ����������֣�������ڣ���ɾ���ٴ���һ���µ�
-- if  ( exists  ( select  *  from  sys.all_objects  where  name = ' ���������� ' ) )   drop  function  ����������
-- exists()���жϵ�ʱ�����ʹ���������
-- sys.all_objects������ϵͳ�е����ж���
if(exists(select * from sys.all_objects where name = 'Tr_UserInfo_UpdateReplaceSelect'))
-- ɾ��������
-- drop  trigger  ��������
drop trigger Tr_UserInfo_UpdateReplaceSelect
go
-- ���� instead of ������
-- create  trigger  ��������  on  ����
-- instead  of  update��delete��insert����
-- as
-- begin
-- �Լ�����SQL�ű������������������滻ԭ�еĴ�����������SQL�ű�
-- end
create trigger Tr_UserInfo_UpdateReplaceSelect on dbo.UserInfo
instead of insert
as
begin
	declare @UserName nvarchar(32)
	select @UserName = (select UserName from inserted)
	declare @ID int
	select @ID = (select ID from inserted)
	
	select * from dbo.UserInfo where UserName = @UserName --�滻ԭ�е�SQL�ű�

	print @UserName
	print @ID
end
-- �������������¼�
-- ��Ϊ���Ƕ���Ĵ�������insert�ģ����Ե�����ִ��insert����ʱ�򣬾ͻ��Զ�����������
insert into dbo.UserInfo(UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag) values('pengqi123','1234qsd',0,getdate(),0)









