using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeFirstDemo_02
{
    class Program
    {
        static void Main(string[] args)
        {
            using (MyTestModule db = new MyTestModule())
            {
                #region init database
                if (!db.Database.Exists())
                {
                    db.Database.Create();


                    List<Order> orders = new List<Order>()
                    {
                        new Order(){ OrderName = "NGPONG CodeFirstTest1", CreateDate = DateTime.Now },
                        new Order(){ OrderName = "NGPONG CodeFirstTest2", CreateDate = DateTime.Now },
                        new Order(){ OrderName = "NGPONG CodeFirstTest3", CreateDate = DateTime.Now },
                        new Order(){ OrderName = "NGPONG CodeFirstTest4", CreateDate = DateTime.Now }
                    };

                    List<Product> products = new List<Product>()
                    {
                        new Product(){ Order = orders[0], ProductName = "NGPONG Product1" },
                        new Product(){ Order = orders[1], ProductName = "NGPONG Product2" },
                        new Product(){ Order = orders[2], ProductName = "NGPONG Product3" },
                        new Product(){ Order = orders[2], ProductName = "NGPONG Product4" },
                        new Product(){ Order = orders[3], ProductName = "NGPONG Product5" },
                        new Product(){ Order = orders[0], ProductName = "NGPONG Product6" }
                    };

                    db.Order.AddRange(orders);
                    db.Product.AddRange(products);

                    db.SaveChanges();
                }
                #endregion

                db.Configuration.LazyLoadingEnabled = true;

                var orderLocal = db.Order.Local;
                var productLocal = db.Product.Local;

                var query = from o in db.Order.Include("Products")
                            where o.OrderId > 2
                            select o;
                
                foreach (var item in query)
                {
                    foreach (var p in item.Products)
                    {

                    }
                }

                Console.ReadKey(true);
            }
        }
    }
}
