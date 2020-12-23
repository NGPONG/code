using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SqlAdapterdamo
{
    class Program
    {
        static void Main(string[] args)
        {
            string connectionString = ConfigurationManager.ConnectionStrings["sqlConnection"].ConnectionString;
            using (SqlConnection conn = new SqlConnection(connectionString))
            {
                conn.Open();
                string sql = @"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime from dbo.UserInfo";

                using (SqlDataAdapter sda = new SqlDataAdapter(sql, conn))
                {
                    DataTable dt = new DataTable("dt1");
                    //填充：把从数据库中读取出来的数据填充至一张内存表当中
                    sda.Fill(dt);
                    
                    for (int i = 0; i < dt.Rows.Count; i++)
                    {
                        Console.WriteLine(dt.Rows[i]["ID"] + "   " + dt.Rows[i]["UserName"] + "   " + dt.Rows[i]["ErrorTime"] + "   " + dt.Rows[i][3] + "   " + dt.Rows[i][4]);
                    }
                }
            }
            Console.ReadLine();
        }

    }
}
