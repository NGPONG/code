using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_05
{
    class Program
    {
        static void Main(string[] args)
        {
            book_shop3Entities db = new book_shop3Entities();
            var query = from b in db.Users
                        where b.Id <= 29
                        select b;

            var local = db.Users.Local;

            foreach (var item in query)
            {

            }

            foreach (var item in query)
            {

            }
        }
    }
}
