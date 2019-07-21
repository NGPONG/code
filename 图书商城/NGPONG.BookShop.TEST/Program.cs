using NGPONG.BookShop.DAL;
using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Web.Script.Serialization;

namespace NGPONG.BookShop.TEST
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new CommentDAL().GetBookComments("4946");
            var jsonSerializer = new JavaScriptSerializer();
            string str = jsonSerializer.Serialize(list);
        }
    }
}
