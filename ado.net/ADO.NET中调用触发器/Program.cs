using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Text;

namespace ADO.NET中调用触发器
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
                    cmd.CommandText = @"insert into dbo.UserInfo(UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag) values('pengqi123','1234qsd',0,getdate(),0)";

                    using (SqlDataReader reader = cmd.ExecuteReader()) 
                    {
                        if (!reader.HasRows) 
                        {
                            return;
                        }

                        while (reader.Read()) 
                        {
                            Console.WriteLine(reader["UserName"]+"\t"+reader["UserPassWord"]+"\t"+reader["ErrorTime"]);
                        }
                        
                    }
                }
            }

            Console.ReadKey(true);
        }
    }
}
