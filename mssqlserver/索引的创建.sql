create table MyIndexTest
(
	ID int identity(1,1) not null,
	Age int null,
	Name nvarchar(32) null,
	gender nvarchar(4) null,
	[Address] nvarchar(32) null
)

-- 创建聚簇索引
-- 一个表只能创建一个聚簇索引，当添加了一个自动增长的主键列，该列默认为一个聚簇索引
-- create  unique  clustered  index  索引名  on  表名（ 列名 ）
create unique clustered index IX_MYIndexTest_Age on dbo.MyIndexTest(Age)

-- 创建不唯一的非聚簇索引
-- create  onoclustered  index  索引名  on  表名  （ 列名 ）
create nonclustered index IX_MYIndexTest_Name on dbo.MyIndexTest(Name)

-- 创建唯一的非聚簇索引
-- create  unique  nonclustered  index  索引名  on  表名  （ 列名 ）
create unique nonclustered index IX_MyIndexTest on dbo.MyIndexTest(gender)



