
-- ����һ���α꣬���α�ָ��һ����ѯSQL�Ľ����
-- declare  �α���  cursor  for  ��ѯSQL���
declare demoCursor cursor for (select ID,UserName,UserPassWord from dbo.UserInfo)

-- ���αֻ꣬�����Ǵ����α���ܹ�ʹ��
-- open  �α���
open demoCursor

-- ���α������ȡ�������������ݷŵ��Լ�����ı�����ȥ
-- ע�⣺�����Ƕ������һ���α꣬���Ҵ��������α�ͻ�ָ���ѯ������ĵ�0�����ݣ�ÿִ��һ���������������һ����������
-- fetch  next  from  �α���  into  ������

-- ������������
declare @UserName nvarchar(32)
declare @ID int
declare @UserPassWord nvarchar(32)
-- ִ���α������ȡ�����
-- ע�⣺����������д˳�����������α�ʱ����ָ��Ĳ�ѯSQL�ű������������д˳����ͬ
while(@@FETCH_STATUS = 0)
	begin
		fetch next from demoCursor into @ID,@UserName,@UserPassWord
		-- ��ӡ����
		print @ID
		print @UserName
		print @UserPassWord
	end

--ÿ������ʹ����ɺ����Ҫ�ر��α�
close demoCursor
deallocate demoCursor

