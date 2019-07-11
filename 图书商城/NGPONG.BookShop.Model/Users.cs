using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.Model
{
    public class Users
    {
        public string Id { get; set; }
        public string LoginId { get; set; }
        public string LoginPwd { get; set; }
        public string Name { get; set; }
        public string Address { get; set; }
        public string Phone { get; set; }
        public string Mail { get; set; }
        public string UserStateId { get; set; }
    }
}
