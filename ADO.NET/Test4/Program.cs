using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test4
{
    class Program
    {
        static void Main(string[] args)
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                string selectSql = @"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime from dbo.UserInfo";
                string insertSql = @"insert into dbo.UserInfo(UserName,UserPassWord,ErrorTime,ErrorEndDateTime) values('asdasd','asdasd',0,'2018/3/19')";
                using (SqlCommand selectCommand = new SqlCommand(selectSql, conn)) 
                {
                    using (SqlDataAdapter adapter = new SqlDataAdapter()) 
                    {
                        adapter.SelectCommand = selectCommand;
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);

                        foreach (DataRow item in dt.Rows)
                        {
                            Console.WriteLine(item["ID"]+"   "+item["UserName"]+"   "+item["UserPassWord"]+"   "+item["ErrorTime"]+"   "+item["ErrorEndDateTime"]);
                        }
                    }
                }
            }

            Console.ReadLine();
        }
    }
}
