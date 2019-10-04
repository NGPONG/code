using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModuleFirstDemo_01
{
    class Program
    {
        static void Main(string[] args)
        {
            MyModuleContainer db = new MyModuleContainer();
            var query = (from c in db.CustomerSet
                        where c.CustomerId == 2
                        select c).FirstOrDefault();
            var quer2 = db.CustomerSet.Find(2);

            MyModuleContainer db2 = new MyModuleContainer();
            var quer3 = db2.CustomerSet.Find(2);
        }
    }
}
