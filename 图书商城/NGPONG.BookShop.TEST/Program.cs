using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.TEST
{
    class Program
    {
        static void Main(string[] args)
        {
            new DAL.SettingDAL().GetSettingValue("123");
        }
    }
}
