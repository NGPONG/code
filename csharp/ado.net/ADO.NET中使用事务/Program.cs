using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Text;

namespace ADO.NET中使用事务
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
                    using (SqlTransaction tran = conn.BeginTransaction()) //开启事务
                    {
                        cmd.Transaction = tran; //指定Command命令在哪个事务中执行SQL脚本
                        try
                        {
                            cmd.CommandText = @" update dbo.UserInfo set UserName=N'wgwergweg' where ID=2;
		                                                              update dbo.UserInfo set ErrorTime=N'哈哈' where ID=3";

                            cmd.ExecuteNonQuery(); //SqlCommand执行非查询语句
                            
                            tran.Commit(); //提交事务

                            Console.WriteLine("执行成功");
                        }
                        catch 
                        {
                            tran.Rollback();
                            Console.WriteLine("事务回滚了"); //事务回滚
                        }
                    }
                }
            }

            Console.ReadLine();
        }
    }
}
