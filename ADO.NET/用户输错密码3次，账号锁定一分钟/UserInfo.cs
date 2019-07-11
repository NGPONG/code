using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 用户输错密码3次_账号锁定一分钟
{
    public class UserInfo
    {
        public int ID { get; set; }
        public string UserName { get; set; }
        public string UserPassWord { get; set; }
        public int ErrrorTime { get; set; }
        public DateTime ErrorEndDateTime { get; set; }
    }
}
