using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test5
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
                    cmd.CommandText = @"insert into dbo.UserInfo(UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag) values ('qwesaf','qwreqr14',0,'2018-03-16 19:34:26.000',1)";

                    object o = cmd.ExecuteScalar();

                    Console.WriteLine(o.ToString());
                }
            }

            Console.ReadLine();

        }

    }
}
