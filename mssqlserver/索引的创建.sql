create table MyIndexTest
(
	ID int identity(1,1) not null,
	Age int null,
	Name nvarchar(32) null,
	gender nvarchar(4) null,
	[Address] nvarchar(32) null
)

-- �����۴�����
-- һ����ֻ�ܴ���һ���۴��������������һ���Զ������������У�����Ĭ��Ϊһ���۴�����
-- create  unique  clustered  index  ������  on  ������ ���� ��
create unique clustered index IX_MYIndexTest_Age on dbo.MyIndexTest(Age)

-- ������Ψһ�ķǾ۴�����
-- create  onoclustered  index  ������  on  ����  �� ���� ��
create nonclustered index IX_MYIndexTest_Name on dbo.MyIndexTest(Name)

-- ����Ψһ�ķǾ۴�����
-- create  unique  nonclustered  index  ������  on  ����  �� ���� ��
create unique nonclustered index IX_MyIndexTest on dbo.MyIndexTest(gender)



