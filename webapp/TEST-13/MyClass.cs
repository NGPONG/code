using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web;

namespace TEST_13
{
    public class MyClass
    {
        public void GetCurrentHttpContext()
        {
            // 如果是在一些自定义的类中，需要手动引入System.Web的命名空间才能够使用HttpContex
            HttpContext context = HttpContext.Current;
        }
    }
}
