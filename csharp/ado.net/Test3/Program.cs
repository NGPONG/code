using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test3
{
    class Program
    {
        static void Main(string[] args)
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                string selectSql = @"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime from dbo.UserInfo";
                using (SqlDataAdapter adapter = new SqlDataAdapter(selectSql,conn)) 
                {
                    DataTable dt = new DataTable();
                    adapter.Fill(dt);
                    dt.Rows.RemoveAt(5);

                    adapter.InsertCommand = conn.CreateCommand();
                    adapter.InsertCommand.CommandText = @"insert into dbo.UserInfo(UserName, UserPassWord, ErrorTime, ErrorEndDateTime) values ('1917648573','kissyou199',0,'2018-03-16 16:53:37.343')";
                    adapter.Update(dt);
                    Console.WriteLine("操作成功");
                } 
            }
            Console.ReadLine();
        }
    }
}
