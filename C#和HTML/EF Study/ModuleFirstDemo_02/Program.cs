using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModuleFirstDemo_02
{
    class Program
    {
        static void Main(string[] args)
        {
            using (EFDemoContainer db = new EFDemoContainer())
            {
                db.Database.CreateIfNotExists();
            }
        }
    }
}
