using NGPONG.BookShop.Common.Helper;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.DAL
{
    public class UsersDAL
    {

        public static bool CheckUserInfoExists(Users model)
        {
            SqlParameter[] parms = 
            {
                new SqlParameter("@LoginId",model.LoginId)
            };

            return SqlHelper.ExecuteScalar("select 1 from users where LoginId = @LoginId", parms) == null ? false : true;
        }

        public static List<Users> GetUserInfo(Users model)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@LoginId",model.LoginId),
                new SqlParameter("@LoginPwd",model.LoginPwd)
            };

            return SqlHelper.GetDataList<Users>("select * from users where LoginId = @LoginId and LoginPwd = @LoginPwd", parms);
        }

        public static int ChangekUserPwd(Users model)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@LoginId",model.LoginId),
                new SqlParameter("@LoginPwd",model.LoginPwd)
            };

            return SqlHelper.ExecuteNonQuery("update Users set LoginPwd = @LoginPwd where LoginId = @LoginId", parms);
        }

        public static bool CheckUserInfoEmail(Users model)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@LoginId",model.LoginId),
                new SqlParameter("@Mail",model.Mail)
            };

            return SqlHelper.ExecuteScalar("select 1 from users where LoginId = @LoginId and Mail = @Mail", parms) == null ? false : true;
        }

        public static int AddkUserInfo(Users model)
        {
            SqlParameter[] parms =
            {
                new SqlParameter("@LoginId",model.LoginId),
                new SqlParameter("@LoginPwd",model.LoginPwd),
                new SqlParameter("@Name",model.Name),
                new SqlParameter("@Address",model.Address),
                new SqlParameter("@Phone",model.Phone),
                new SqlParameter("@Mail",model.Mail)
            };

            return SqlHelper.ExecuteNonQuery("insert into Users(LoginId,LoginPwd,Name,Address,Phone,Mail,UserStateId) values(@LoginId,@LoginPwd,@Name,@Address,@Phone,@Mail,'1')", parms);
        }
    }
}
