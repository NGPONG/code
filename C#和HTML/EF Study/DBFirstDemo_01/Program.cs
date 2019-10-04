using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBFirstDemo_01
{
    class Program
    {
        static void Main(string[] args)
        {
            CustomerSet customer = new CustomerSet
            {
                CustomerId = 2,
                CustomerName = "NGPONG2"
            };

            EFDemoEntities db = new EFDemoEntities();
            var customerProc = db.CustomerSet.Attach(customer);
            customerProc.CustomerName = "修改了";
            db.SaveChanges();
        }
    }
}
