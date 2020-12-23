using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_01
{
    class Program
    {
        static void Main(string[] args)
        {
            Test testTb = new Test()
            {
                Age = 0,
                Name = "NGPONG2"
            };

            book_shop3Entities book_Shop3Entities = new book_shop3Entities();


            book_Shop3Entities.Entry<Test>(testTb).State = System.Data.Entity.EntityState.Added;
            book_Shop3Entities.SaveChanges();
            Console.ReadKey(true);
        }
    }
}
