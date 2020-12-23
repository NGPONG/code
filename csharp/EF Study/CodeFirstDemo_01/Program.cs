using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeFirstDemo_01
{
    class Program
    {
        static void Main(string[] args)
        {
            using (MyModule db = new MyModule())
            {
                db.Database.CreateIfNotExists();
                var local = db.Class.Local;
            }
        }
    }
}
