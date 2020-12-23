using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;

namespace TEST_15
{
    public class TestModule
    {
        public async void ActionTest()
        {
            await Task.Run(() =>
            {
                HttpContext context = HttpContext.Current;
            });
        }
    }
}