--------------------动态创建列--------------------
-- 给指定表添加一列数据
-- alter  table  表名  add  列名  类型  (约束)  null/not null 
alter table dbo.TableDamon add ID int primary key identity(1,1) not null
alter table dbo.TableDamon add [Address] nvarchar(32) null

-- 修改指定列的一些属性
-- alter  table  表名  alter  column  列名  类型  (约束)  null/not null
alter table dbo.TableDamon alter column [Address] nvarchar(512) null

-- 删除指定的列
-- alter  table  表名  drop  column  列名
alter table dbo.TableDamon drop column [Address]

--------------------动态创建约束--------------------

-- 删除指定表中的指定约束
-- alter  table 表名  drop  constraint  约束名
alter table dbo.TableDamon drop constraint DF__TableDamo__DelFl__117F9D94

-- 添加一个默认值约束：(DF)default constraint
-- alter  table  表名  add  constraint  约束的名字  default(n)  for  列名
alter table dbo.TableDamon add constraint DF_TableDamon_DelFlag default(0) for DelFlag

-- 添加一个主键约束：(PK) primary key constraint 
-- alter  table  表名  add  constraint  约束名  primary key(列名)
alter table dbo.TableDamon add constraint PK_TableDamon_ID primary key(ID)

-- 添加一个唯一约束：(UQ)unique constraint
-- alter  table  表名  add  constraint  约束名  unique(列名)
alter table dbo.TableDamon add constraint UQ_TableDamon_Name unique(Name)

--添加一个检查约束：检查约束 (CK)check constraint
--alter  table  表名  add  constraint  约束名  check(带有列的关系表达式)
alter table dbo.TableDamon add constraint CK_TableDamon_Number check(Number>10 and Number <20)

-- alter  table  外键表名  add  constraint  约束名  foreign key(外检表的外键列名)  references  主键表名(主键表的主键列名)
-- 外键表：存在一个外键，该外键关联到另一个表的主键
-- 主键表：只有一个主键，该主键与另一个表的外键关联
alter table dbo.Product add constraint FK_Product_Category foreign key(CategoryID) references dbo.Category (CatId)