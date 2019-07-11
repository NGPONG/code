--------------------��̬������--------------------
-- ��ָ�������һ������
-- alter  table  ����  add  ����  ����  (Լ��)  null/not null 
alter table dbo.TableDamon add ID int primary key identity(1,1) not null
alter table dbo.TableDamon add [Address] nvarchar(32) null

-- �޸�ָ���е�һЩ����
-- alter  table  ����  alter  column  ����  ����  (Լ��)  null/not null
alter table dbo.TableDamon alter column [Address] nvarchar(512) null

-- ɾ��ָ������
-- alter  table  ����  drop  column  ����
alter table dbo.TableDamon drop column [Address]

--------------------��̬����Լ��--------------------

-- ɾ��ָ�����е�ָ��Լ��
-- alter  table ����  drop  constraint  Լ����
alter table dbo.TableDamon drop constraint DF__TableDamo__DelFl__117F9D94

-- ���һ��Ĭ��ֵԼ����(DF)default constraint
-- alter  table  ����  add  constraint  Լ��������  default(n)  for  ����
alter table dbo.TableDamon add constraint DF_TableDamon_DelFlag default(0) for DelFlag

-- ���һ������Լ����(PK) primary key constraint 
-- alter  table  ����  add  constraint  Լ����  primary key(����)
alter table dbo.TableDamon add constraint PK_TableDamon_ID primary key(ID)

-- ���һ��ΨһԼ����(UQ)unique constraint
-- alter  table  ����  add  constraint  Լ����  unique(����)
alter table dbo.TableDamon add constraint UQ_TableDamon_Name unique(Name)

--���һ�����Լ�������Լ�� (CK)check constraint
--alter  table  ����  add  constraint  Լ����  check(�����еĹ�ϵ���ʽ)
alter table dbo.TableDamon add constraint CK_TableDamon_Number check(Number>10 and Number <20)

-- alter  table  �������  add  constraint  Լ����  foreign key(������������)  references  ��������(���������������)
-- ���������һ��������������������һ���������
-- ������ֻ��һ������������������һ������������
alter table dbo.Product add constraint FK_Product_Category foreign key(CategoryID) references dbo.Category (CatId)