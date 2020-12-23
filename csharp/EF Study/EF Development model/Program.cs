using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EF_Development_model
{
    class Program
    {
        static void Main(string[] args)
        {
            using (CodeFirstModule db = new CodeFirstModule())
            {
                if (!db.Database.Exists())
                {
                    db.Database.Create();
                }
            }
        }
    }
}
