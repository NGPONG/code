using NGPONG.BookShop.DAL;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.BLL
{
    public class UsersService
    {
        public bool CheckUserInfoExists(Users model)
        {
            return UsersDAL.CheckUserInfoExists(model);
        }

        public bool CheckUserInfoLogin(Users model)
        {
            return UsersDAL.CheckUserInfoLogin(model);
        }

        public List<Users> GetUserInfo(Users model)
        {
            return UsersDAL.GetUserInfo(model);
        }

        public int AddkUserInfo(Users model)
        {
            return UsersDAL.AddkUserInfo(model);
        }
    }
}
