using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Text;
using System.Transactions;

namespace ADO.NET中使用事务2
{
    class Program
    {
        static void Main(string[] args)
        {
            using (SqlConnection conn = new SqlConnection(@"server=.;uid=sa;pwd=kissyou199;database=damon")) 
            {
                conn.Open();
                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    try
                    {
                        using (TransactionScope scope = new TransactionScope())//开启事务
                        {
                            cmd.CommandText = @" update dbo.UserInfo set UserName=N'wgwergweg' where ID=2;
		                                                              update dbo.UserInfo set ErrorTime=N'哈哈' where ID=3";
                            cmd.ExecuteNonQuery();

                            scope.Complete();//提交事务，当事务提交失败，事务自动回滚

                            Console.WriteLine("这件事务提交成功了");
                        }
                    }
                    catch (Exception ex) 
                    {
                        Console.WriteLine(ex.Message);
                    }
                }
            }

            Console.ReadKey(true);
        }
    }
}
