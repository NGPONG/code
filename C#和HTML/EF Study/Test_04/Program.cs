using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;

namespace Test_04
{
    class Program
    {
        static void Main(string[] args)
        {
            using (EFDemoEntities1 db = new EFDemoEntities1())
            {
                var local = db.CustomerSet.Local;
                CustomerSet query = (from c in db.CustomerSet
                                     where c.CustomerId == 4
                                     select c).FirstOrDefault();
                query.CustomerAddress = "123123";
                query.CustomerName = "6";
                var attach1 = db.CustomerSet.Attach(query);
                EntityState entityState = db.Entry(attach1).State;
                attach1.CustomerAddress = string.Empty;
                EntityState entityState2 = db.Entry(query).State;
                EntityState entityState3 = db.Entry(attach1).State;
                var a = db.CustomerSet.Attach(attach1);
                EntityState entityState5 = db.Entry(query).State;
                EntityState entityState6 = db.Entry(a).State;
            }
        }
    }
}
