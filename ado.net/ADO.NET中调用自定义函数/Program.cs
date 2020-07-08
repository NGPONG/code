using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Text;

namespace ADO.NET中调用自定义函数
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
                    cmd.CommandText = @"select dbo.Fun_GetUserInfoCount(1)";//调用自定义函数

                    object o = cmd.ExecuteScalar();

                    Console.WriteLine(o.ToString());
                }
            }

            Console.ReadLine();
        }
    }
}
