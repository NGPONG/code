using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Text;

namespace ADO.NET中调用存储过程实现分页存储
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("一页有几行？");
            int pageSize = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("需要显示第几页？");
            int pageIndex = Convert.ToInt32(Console.ReadLine());

            using (SqlConnection conn = new SqlConnection(@"server=.;uid=sa;pwd=kissyou199;database=damon")) 
            {
                conn.Open();
                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    //当我们在数据库中已创建了存储过程
                    //我们便可以直接通过指定CommandText为存储过程的名字来指定SqlCommand所执行的存储过程
                    cmd.CommandText = @"Pro_UserInfo_GetPages";

                    #region 创建输入参数
                    //创建输入参数
                    SqlParameter parPageIndex = new SqlParameter("@pageIndex", SqlDbType.Int);
                    //设置参数的输入的
                    parPageIndex.Direction = ParameterDirection.Input;
                    parPageIndex.Value = pageIndex;
                    cmd.Parameters.Add(parPageIndex);

                    SqlParameter parPageSize = new SqlParameter("@pageSize", SqlDbType.Int);
                    parPageIndex.Direction = ParameterDirection.Input;
                    parPageSize.Value = pageSize;
                    cmd.Parameters.Add(parPageSize); 
                    #endregion

                    #region 创建输出参数
                    //创建输出参数
                    SqlParameter parCountOut = new SqlParameter("@count", SqlDbType.Int);
                    //设置参数为输出的
                    parCountOut.Direction = ParameterDirection.Output;
                    cmd.Parameters.Add(parCountOut); 
                    #endregion

                    //设置Command的执行类型是存储过程的
                    cmd.CommandType = CommandType.StoredProcedure;

                    using (SqlDataReader reader = cmd.ExecuteReader()) 
                    {
                        while (reader.Read()) 
                        {
                            Console.WriteLine(reader["UserName"]+"\t"+reader["UserPassWord"]);
                        }
                    }

                    //Sql执行完成过后，输出参数自动赋我们在存储过程中所定义的值
                    Console.WriteLine(parCountOut.Value);

                }
            }

            Console.ReadLine();
        }
    }
}
